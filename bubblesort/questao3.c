#include <stdio.h>

/*
 * Bubble Sort Otimizado com flag de early stop.
 *
 * Por que melhora o melhor caso de O(n^2) para O(n)?
 * -----------------------------------------
 * No Bubble Sort normal, os dois lacos sempre executam ate o fim,
 * independente de o vetor ja estar ordenado ou não: O(n^2) em todos os casos.
 *
 * Com a flag 'houveTroca', algo muda:
 *   - Ao iniciar cada passada externa (i), a flag e resetada para 0.
 *   - Se nenhuma troca ocorrer durante a passada interna(j), o vetor ja
 *     esta ordenado e o laco externo é interrompido com break.
 *   - No melhor caso (vetor ja ordenado), a primeira passada percorre
 *     os n-1 elementos sem trocar nenhum par, detecta houveTroca == 0
 *     e para imediatamente: apenas n-1 comparacoes -> O(n).
 *   - No pior caso (ordem inversa) o comportamento continua O(n^2),
 *     pois havera troca em toda passada ate o fim.
 */
void bubbleSortOptimizado(int v[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        int houveTroca = 0; 

        for (j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                houveTroca = 1; 
            }
        }

        if (!houveTroca)
            break;
    }
}

void imprimir(const int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int v[] = {17, 70, 2, 91, 98, 4, 13};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Antes:  ");
    imprimir(v, n);
    bubbleSortOptimizado(v, n);
    printf("Depois: ");
    imprimir(v, n);

    return 0;
}
