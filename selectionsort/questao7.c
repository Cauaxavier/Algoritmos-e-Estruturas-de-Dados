#include <stdio.h>

void selectionSort(int *V, int n)
{
    int i, j, menor;

    for (i = 0; i < n - 1; i++)
    {
        menor = i;

        for (j = i + 1; j < n; j++)
        {
            if (V[j] < V[menor])
            {
                menor = j;
            }
        }

        if (menor != i)
        {
            int temp = V[i];
            V[i] = V[menor];
            V[menor] = temp;
        }
    }
}

void imprimirVetor(const int *V, int n)
{
    int i;
    printf("[");

    for (i = 0; i < n; i++)
    {
        printf("%d", V[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }

    printf("]\n");
}

int main(void)
{
    int V[] = {23, 5, -8, 17, 17, 0, 42, -1};
    int n = sizeof(V) / sizeof(V[0]);

    printf("Antes: ");
    imprimirVetor(V, n);

    selectionSort(V, n);

    printf("Depois: ");
    imprimirVetor(V, n);

    return 0;
}
