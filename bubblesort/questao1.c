#include <stdio.h>

void bubbleSort(int v[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int v[] = {17, 70, 2, 91, 98, 4, 13};
    int n = sizeof(v) / sizeof(v[0]);
    int i;

    printf("Vetor antes da ordenacao:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

    bubbleSort(v, n);

    printf("\nVetor depois da ordenacao:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
