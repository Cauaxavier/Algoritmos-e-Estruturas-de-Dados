#include <stdio.h>

void insertionSort(int *V, int n)
{
    int i, j, chave;

    for (i = 1; i < n; i++)
    {
        chave = V[i];
        j = i;

        while (j > 0 && chave < V[j - 1])
        {
            V[j] = V[j - 1];
            j--;
        }

        V[j] = chave;
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

    insertionSort(V, n);

    printf("Depois: ");
    imprimirVetor(V, n);

    return 0;
}
