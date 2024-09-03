#include <stdbool.h>
#include <stdio.h>
#define MAX 20

typedef int TYPEKEY;

typedef struct {
    TYPEKEY key;
} REGISTRY;

typedef struct {
    REGISTRY A[MAX];
    int start;
    int numberItems;
} QUEUE;

void inicializeQueue(QUEUE* q) {
    q->start = 0;
    q->numberItems = 0;
}

int queueSize(QUEUE* q) {
    return q->numberItems;
}

void showQuere(QUEUE* q) {
    printf("\nQueue ");
    
    int i = q->start;
    int count;
    
    for (count = 0; count < q->numberItems; count++) {
        printf("%d ", q->A[i].key);
        i = (i + 1) % MAX;
    }
    
    printf("\n");
    
}

bool insertElementsQueue(QUEUE* q, REGISTRY reg) {
    if (q->numberItems >= MAX) {
        return false;
    }
    
    int posicao = (q->start + q->numberItems) % MAX;
    
    q->A[posicao] = reg;
    q->numberItems++;
    
    return true;
}

bool deleteElementQueue(QUEUE* q, REGISTRY* reg) {
    if (q->numberItems == 0) {
        return false;
    }
    
    *reg = q->A[q->start];
    q->start = (q->start + 1) % MAX;
    q->numberItems--;
    
    return true;
}

bool deleteNegativeNumbers(QUEUE* q) {
    if (q->numberItems == 0) {
        return false;
    }

    int count = 0;
    int pos = q->start;

    while (count < q->numberItems) {
        if (q->A[pos].key < 0) {
            
            int i = pos;
            
            while (i != (q->start + q->numberItems - 1) % MAX) {
                int nextPos = (i + 1) % MAX;
                q->A[i] = q->A[nextPos];
                i = nextPos;
            }
            
            q->numberItems--;
          
        } else {
            pos = (pos + 1) % MAX;
            count++;
        }
    }
    return true;
}

void queueInverter(QUEUE* q) {
    int start = q->start;
    int aux;
    int size = q->numberItems;
    int end = size - 1;
    
    while (start <= end) {
        aux = q->A[start].key;
        q->A[start].key = q->A[end].key;
        q->A[end].key = aux;
        start = start + 1;
        end = end - 1;
    }
    
}

int main() {
    
    QUEUE queue;
    REGISTRY registry;
    int i;
    
    inicializeQueue(&queue);
    
    registry.key = -1;
    insertElementsQueue(&queue, registry);
    
    for (i = 0; i < 10; i++) {
        registry.key = i;
        insertElementsQueue(&queue, registry);
    }
    
    registry.key = -2;
    insertElementsQueue(&queue, registry);
    
    deleteNegativeNumbers(&queue);
    
    int tamanho = queueSize(&queue);
    
    printf("Tamanho: %d", tamanho);
    
    showQuere(&queue);
    
    //queueInverter(&queue);
    
    //showQuere(&queue);
    
    for (i = 0; i < 3; i++) {
        deleteElementQueue(&queue, &registry);
    }
    
    //showQuere(&queue);

    return 0;
}