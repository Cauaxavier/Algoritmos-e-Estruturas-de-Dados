#include <stdio.h>

#define N 20

typedef struct
{
    int comparacoes;
    int trocas;
} Metricas;

void bubbleSortNormal(int v[], int n, Metricas *metricas)
{
    int i, j;

    metricas->comparacoes = 0;
    metricas->trocas = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            metricas->comparacoes++;

            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                metricas->trocas++;
            }
        }
    }
}

void bubbleSortOptimizado(int v[], int n, Metricas *metricas)
{
    int i, j;

    metricas->comparacoes = 0;
    metricas->trocas = 0;

    for (i = 0; i < n - 1; i++)
    {
        int houveTroca = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            metricas->comparacoes++;

            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                metricas->trocas++;
                houveTroca = 1;
            }
        }

        if (!houveTroca)
            break;
    }
}

void copiarVetor(int destino[], const int origem[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        destino[i] = origem[i];
}

void imprimir(const int v[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void preencherOrdenado(int v[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        v[i] = i + 1;
}

void preencherReverso(int v[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        v[i] = n - i;
}

void compararCaso(const char *titulo, const int original[], int n)
{
    int copiaNormal[N];
    int copiaOtimizada[N];
    Metricas normal;
    Metricas otimizada;

    copiarVetor(copiaNormal, original, n);
    copiarVetor(copiaOtimizada, original, n);

    printf("=== %s ===\n", titulo);
    printf("Vetor original: ");
    imprimir(original, n);

    bubbleSortNormal(copiaNormal, n, &normal);
    bubbleSortOptimizado(copiaOtimizada, n, &otimizada);

    printf("Bubble normal:     comparacoes = %d, trocas = %d\n", normal.comparacoes, normal.trocas);
    printf("Bubble otimizado:  comparacoes = %d, trocas = %d\n", otimizada.comparacoes, otimizada.trocas);
    printf("Reducao de comparacoes: %d\n", normal.comparacoes - otimizada.comparacoes);
    printf("Reducao de trocas:      %d\n", normal.trocas - otimizada.trocas);
    printf("\n");
}

int main(void)
{
    int ordenado[N];
    int reverso[N];
    int desordenado[N] = {12, 5, 19, 1, 8, 17, 3, 14, 10, 2, 20, 7, 6, 15, 4, 18, 9, 13, 11, 16};

    preencherOrdenado(ordenado, N);
    preencherReverso(reverso, N);

    printf("Comparacao entre Bubble normal e Bubble com early stop (n = %d)\n\n", N);

    compararCaso("Caso 1 - Ja ordenado", ordenado, N);
    compararCaso("Caso 2 - Reverso", reverso, N);
    compararCaso("Caso 3 - Desordenado", desordenado, N);

    printf("Conclusao:\n");
    printf("O caso que mais reduz operacoes com early stop e o vetor ja ordenado,\n");
    printf("porque nenhuma troca ocorre na primeira passada e o algoritmo termina cedo.\n");

    return 0;
}
