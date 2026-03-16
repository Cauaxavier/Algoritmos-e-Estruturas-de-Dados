#include <stdio.h>

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
    printf("]");
}

void insertionSortTracado(int *V, int n)
{
    int i, j, chave;

    printf("Inicial:  ");
    imprimirVetor(V, n);
    printf("\n");

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

        printf("i=%d (chave=%d): ", i, chave);
        imprimirVetor(V, n);
        printf("\n");
    }
}

int main(void)
{
    int V[] = {5, 3, 4, 1, 2};
    int n = sizeof(V) / sizeof(V[0]);

    insertionSortTracado(V, n);

    return 0;
}
