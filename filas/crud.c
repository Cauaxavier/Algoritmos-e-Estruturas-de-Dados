#include <stdbool.h>
#include <stdio.h>
#define MAX 10

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

int main() {
    
    QUEUE queue;
    REGISTRY registry;
    int i;
    
    inicializeQueue(&queue);
    
    for (i = 0; i < 10; i++) {
        registry.key = i;
        insertElementsQueue(&queue, registry);
    }
    
    int tamanho = queueSize(&queue);
    
    printf("Tamanho: %d", tamanho);
    
    for (i = 0; i < 3; i++) {
        deleteElementQueue(&queue, &registry);
    }
    
    showQuere(&queue);

    return 0;
}