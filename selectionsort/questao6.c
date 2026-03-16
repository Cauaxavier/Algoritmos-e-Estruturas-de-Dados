#include <stdio.h>

void selectionSort(int *V, int n)
{
    int i, j, indiceMenor;

    for (i = 0; i < n - 1; i++)
    {
        indiceMenor = i;

        for (j = i + 1; j < n; j++)
        {
            if (V[j] < V[indiceMenor])
            {
                indiceMenor = j;
            }
        }

        if (indiceMenor != i)
        {
            int temp = V[i];
            V[i] = V[indiceMenor];
            V[indiceMenor] = temp;
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
    int V[] = {17, 70, 2, 91, 98, 4, 13};
    int n = sizeof(V) / sizeof(V[0]);

    printf("Antes: ");
    imprimirVetor(V, n);

    selectionSort(V, n);

    printf("Depois: ");
    imprimirVetor(V, n);

    return 0;
}
