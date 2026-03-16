#include <stdio.h>

void bubbleSortOrdem(int v[], int n, int ordem)
{
    int i, j, trocou;

    if (n <= 1)
    {
        return;
    }

    if (ordem != 1 && ordem != -1)
    {
        return;
    }

    for (i = 0; i < n - 1; i++)
    {
        trocou = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            if ((ordem == 1 && v[j] > v[j + 1]) ||
                (ordem == -1 && v[j] < v[j + 1]))
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }

        if (!trocou)
        {
            break;
        }
    }
}

void imprimirVetor(const int v[], int n)
{
    int i;

    printf("[");
    for (i = 0; i < n; i++)
    {
        printf("%d", v[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void)
{
    int v0[1] = {0};
    int n0 = 0;

    int v1[] = {42};
    int n1 = 1;

    int vRep[] = {5, 1, 5, 3, 3, 2, 1};
    int nRep = sizeof(vRep) / sizeof(vRep[0]);

    int vMix[] = {-4, 8, 0, -1, 7, -9, 3};
    int nMix = sizeof(vMix) / sizeof(vMix[0]);

    printf("Teste n=0 (crescente): ");
    bubbleSortOrdem(v0, n0, 1);
    imprimirVetor(v0, n0);

    printf("Teste n=1 (decrescente): ");
    bubbleSortOrdem(v1, n1, -1);
    imprimirVetor(v1, n1);

    printf("Repetidos (crescente): ");
    bubbleSortOrdem(vRep, nRep, 1);
    imprimirVetor(vRep, nRep);

    printf("Positivos/negativos (decrescente): ");
    bubbleSortOrdem(vMix, nMix, -1);
    imprimirVetor(vMix, nMix);

    return 0;
}
