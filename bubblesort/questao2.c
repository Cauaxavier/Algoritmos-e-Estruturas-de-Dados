#include <stdio.h>

void bubbleSortInstrumentado(int v[], int n, int *comparacoes, int *trocas) {
    if (v == NULL || n <= 1) return;

    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;

        for (int j = 0; j < n - 1 - i; j++) {
            (*comparacoes)++;
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*trocas)++;
                trocou = 1;
            }
        }

        if (!trocou)
            break;
    }
}

int main() {
    int v[] = {17, 70, 2, 91, 98, 4, 13};
    int n = sizeof(v) / sizeof(v[0]);
    int comparacoes = 0, trocas = 0;
    int i;

    printf("Vetor antes da ordenacao:\n");
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    bubbleSortInstrumentado(v, n, &comparacoes, &trocas);

    printf("Vetor depois da ordenacao:\n");
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    printf("Trocas:      %d\n", trocas);
    printf("Comparacoes: %d\n", comparacoes);

    return 0;
}
