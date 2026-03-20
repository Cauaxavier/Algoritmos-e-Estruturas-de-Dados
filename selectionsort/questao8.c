#include <stdio.h>

void selectionSortMetricas(int *V, int n, long *comparacoes, long *trocas)
{
    int i, j, menor;

    *comparacoes = 0;
    *trocas = 0;

    for (i = 0; i < n - 1; i++)
    {
        menor = i;

        for (j = i + 1; j < n; j++)
        {
            (*comparacoes)++;
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
            (*trocas)++;
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

void imprimirResumo(const char *titulo, long comparacoes, long trocas)
{
    printf("%s\n", titulo);
    printf("comparacoes = %ld\n", comparacoes);
    printf("trocas = %ld\n\n", trocas);
}

int main(void)
{
    int i;
    const int n = 20;
    int ordenado[20];
    int reverso[20];
    int aleatorio[20] = {12, 3, 19, 0, 8, 14, 7, 1, 16, 5, 10, 4, 13, 6, 18, 2, 17, 9, 15, 11};
    int trabalho[20];
    long comparacoes;
    long trocas;

    for (i = 0; i < n; i++)
    {
        ordenado[i] = i + 1;
        reverso[i] = n - i;
    }

    copiarVetor(trabalho, ordenado, n);
    selectionSortMetricas(trabalho, n, &comparacoes, &trocas);
    imprimirResumo("(i) Vetor ordenado", comparacoes, trocas);

    copiarVetor(trabalho, reverso, n);
    selectionSortMetricas(trabalho, n, &comparacoes, &trocas);
    imprimirResumo("(ii) Vetor reverso", comparacoes, trocas);

    copiarVetor(trabalho, aleatorio, n);
    selectionSortMetricas(trabalho, n, &comparacoes, &trocas);
    imprimirResumo("(iii) Vetor aleatorio", comparacoes, trocas);

    return 0;
}
