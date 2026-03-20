#include <stdio.h>

void insertionSortMetricas(int *V, int n, int *comparacoes, int *movimentacoes)
{
    int i, j, chave;

    *comparacoes = 0;
    *movimentacoes = 0;

    for (i = 1; i < n; i++)
    {
        chave = V[i];
        j = i;

        while (j > 0)
        {
            (*comparacoes)++;
            if (chave < V[j - 1])
            {
                V[j] = V[j - 1];
                (*movimentacoes)++;
                j--;
            }
            else
            {
                break;
            }
        }

        V[j] = chave;
        (*movimentacoes)++;
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

void imprimirResumo(const char *titulo, int comparacoes, int movimentacoes){
    printf("%-22s comparacoes = %d | movimentacoes = %d\n",
           titulo, comparacoes, movimentacoes);
}

int main(void)
{
    const int n = 20;
    int i;
    int trabalho[20];
    int comparacoes, movimentacoes;

    int ordenado[20];
    for (i = 0; i < n; i++)
        ordenado[i] = i + 1;

    int reverso[20];
    for (i = 0; i < n; i++)
        reverso[i] = n - i;

    int aleatorio[20] = {7, 14, 2, 18, 5, 11, 1, 16, 9, 3,
                         20, 6, 13, 8, 19, 4, 12, 17, 10, 15};

    int quaseOrdenado[20];
    for (i = 0; i < n; i++)
        quaseOrdenado[i] = i + 1;

    quaseOrdenado[4] = 6;
    quaseOrdenado[5] = 5;
    quaseOrdenado[14] = 16;
    quaseOrdenado[15] = 15;
  
    copiarVetor(trabalho, ordenado, n);
    insertionSortMetricas(trabalho, n, &comparacoes, &movimentacoes);
    imprimirResumo("(i) Ordenado:", comparacoes, movimentacoes);

    copiarVetor(trabalho, reverso, n);
    insertionSortMetricas(trabalho, n, &comparacoes, &movimentacoes);
    imprimirResumo("(ii) Reverso:", comparacoes, movimentacoes);

    copiarVetor(trabalho, aleatorio, n);
    insertionSortMetricas(trabalho, n, &comparacoes, &movimentacoes);
    imprimirResumo("(iii) Aleatorio:", comparacoes, movimentacoes);

    copiarVetor(trabalho, quaseOrdenado, n);
    insertionSortMetricas(trabalho, n, &comparacoes, &movimentacoes);
    imprimirResumo("(iv) Quase ordenado:", comparacoes, movimentacoes);

    return 0;
}
