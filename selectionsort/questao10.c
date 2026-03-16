#include <stdio.h>

void selectionSortOrdem(int *V, int n, int ordem)
{
    int i, j, indiceSelecionado;

    if (ordem != 1 && ordem != -1)
    {
        return;
    }

    for (i = 0; i < n - 1; i++)
    {
        indiceSelecionado = i;

        for (j = i + 1; j < n; j++)
        {
            if ((ordem == 1 && V[j] < V[indiceSelecionado]) ||
                (ordem == -1 && V[j] > V[indiceSelecionado]))
            {
                indiceSelecionado = j;
            }
        }

        if (indiceSelecionado != i)
        {
            int temp = V[i];
            V[i] = V[indiceSelecionado];
            V[indiceSelecionado] = temp;
        }
    }
}

void copiarVetor(int *destino, const int *origem, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        destino[i] = origem[i];
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
    int original[] = {23, 5, -8, 17, 17, 0, 42, -1};

    int crescente[8];
    int decrescente[8];
    int n = sizeof(original) / sizeof(original[0]);

    copiarVetor(crescente, original, n);
    copiarVetor(decrescente, original, n);

    printf("Vetor original: ");
    imprimirVetor(original, n);

    selectionSortOrdem(crescente, n, 1);
    printf("Ordem crescente: ");
    imprimirVetor(crescente, n);

    selectionSortOrdem(decrescente, n, -1);
    printf("Ordem decrescente: ");
    imprimirVetor(decrescente, n);

    return 0;
}
