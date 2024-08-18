#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
    struct aux* ant; 
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT cabeca;
} LISTA;

bool excluirElementoRepetido(LISTA *l, TIPOCHAVE ch) {
    if (l->cabeca->prox == l->cabeca) return false; // Lista vazia

    PONT atual = l->cabeca->prox;
    bool encontrou = false;
    int cont = 0;

    while (atual != l->cabeca) {
        if (atual->reg.chave == ch) {
            
            if (cont == 0) {
                cont = cont + 1;
                atual = atual->prox;
                continue;
            }
            
            encontrou = true;

            PONT paraRemover = atual;

            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
            atual = atual->prox;

            free(paraRemover);
            
        } else {
            atual = atual->prox;
        }
    }
    return encontrou;
}

void inicializarLista(LISTA* l) {
    l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
    l->cabeca->ant = l->cabeca;
}

bool inserirElemLista(LISTA *l, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;

    novo->prox = l->cabeca;
    novo->ant = l->cabeca->ant;
    
    l->cabeca->ant->prox = novo;
    l->cabeca->ant = novo;

    return true;
}

void exibirLista(LISTA* l) {
    PONT atual = l->cabeca->prox;
    printf("Lista: ");
    while (atual != l->cabeca) {
        printf("%d ", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    LISTA lista;
    REGISTRO reg;
    inicializarLista(&lista);

    for (int i = 1; i <= 10; i++) {
        reg.chave = i;
        inserirElemLista(&lista, reg);
    }

    for (int i = 0; i < 5; i++) {
        reg.chave = 4;
        inserirElemLista(&lista, reg);
    }

    exibirLista(&lista);

    excluirElementoRepetido(&lista, 4);

    exibirLista(&lista);

    return 0;
}
