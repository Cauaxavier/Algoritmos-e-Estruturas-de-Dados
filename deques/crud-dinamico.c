#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct auxElem {
    REGISTRO reg;
    struct auxElem* ant;
    struct auxElem* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT cabeca;
} DEQUE;

void inicializarDeque(DEQUE* d) {
    d->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

int tamanho(DEQUE* d) {
    PONT end = d->cabeca->prox;
    int tam = 0;
    
    while (end != d->cabeca) {
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirDequefim(DEQUE* d) {
    PONT end = d->cabeca->ant;
    printf("Deque partindo do fim \" ");
    while (end != d->cabeca) {
        printf("%d ", end->reg.chave);
        end = end->ant;
    }
    printf("\"\n");
}

bool inserirDequeFim(DEQUE* d, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    
    novo->reg = reg;
    novo->prox = d->cabeca;
    novo->ant = d->cabeca->ant;
    d->cabeca->ant = novo;
    novo->ant->prox = novo;
    return true;
}

bool excluirElementoDequeInicio(DEQUE* d, REGISTRO* reg) {
    if (d->cabeca->prox == d->cabeca) {
        return false;
    }
    PONT apagar = d->cabeca->prox;
    *reg = apagar->reg;
    d->cabeca->prox = apagar->prox;
    apagar->prox->ant = d->cabeca;
    free(apagar);
    return true;
}

void reinicializarDeque(DEQUE* d) {
    PONT end = d->cabeca->prox;
    
    while (end != d->cabeca) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

int main() {
    
    DEQUE deque;
    REGISTRO registro, registro2;
    int i;
    
    inicializarDeque(&deque);
    
    for (i=0; i < 10; i++) {
        registro.chave = i;
        inserirDequeFim(&deque, registro);
    }
    
    excluirElementoDequeInicio(&deque, &registro2);
    
    exibirDequefim(&deque);
    
    reinicializarDeque(&deque);
    
    int dequeTamanho = tamanho(&deque);
    
    printf("O tamanho do deque é: %d\n", dequeTamanho);
    
    return 0;
}