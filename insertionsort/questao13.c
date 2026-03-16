#include <stdio.h>

void insertionSortMetricas(int *V, int n, long *comparacoes, long *movimentacoes)
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

void imprimirResumo(const char *titulo, long comparacoes, long movimentacoes)
{
    printf("%-22s comparacoes = %ld | movimentacoes = %ld\n",
           titulo, comparacoes, movimentacoes);
}

int main(void)
{
    const int n = 20;
    int i;
    int trabalho[20];
    long comparacoes, movimentacoes;

    /* (i) ordenado: 1..20 */
    int ordenado[20];
    for (i = 0; i < n; i++)
        ordenado[i] = i + 1;

    /* (ii) reverso: 20..1 */
    int reverso[20];
    for (i = 0; i < n; i++)
        reverso[i] = n - i;

    /* (iii) aleatorio fixo (embaralhamento de 1..20) */
    int aleatorio[20] = {7, 14, 2, 18, 5, 11, 1, 16, 9, 3,
                         20, 6, 13, 8, 19, 4, 12, 17, 10, 15};

    /* (iv) quase ordenado: ordenado com 2 trocas pontuais */
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

    printf("\nExplicacao:\n");
    printf("Ordenado:     cada chave ja esta no lugar certo; o while nao desloca nada.\n");
    printf("              comparacoes = n-1 (minimo), movimentacoes = n-1 (so V[j]=chave).\n");
    printf("Reverso:      cada nova chave deve percorrer todo o trecho ja ordenado.\n");
    printf("              comparacoes e movimentacoes chegam ao maximo: O(n^2).\n");
    printf("Aleatorio:    custo medio, aproximadamente n^2/4 comparacoes e movimentacoes.\n");
    printf("Quase ord.:   pouquissimos deslocamentos; custo proximo do caso ordenado.\n");
    printf("              Por isso o Insertion Sort e muito eficiente em dados ja ordenados\n");
    printf("              ou com poucas inversoes -- melhor que Bubble e Selection nesses casos.\n");

    return 0;
}
