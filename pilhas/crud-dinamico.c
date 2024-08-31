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
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT topo;
} PILHA;

void inicializarPilha(PILHA* p) {
    p->topo = NULL;
}

int tamanho(PILHA* p) {
    PONT end = p->topo;
    int tam = 0;
    
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    
    return tam;
}

bool estaVazia(PILHA* p) {
    if (p->topo == NULL) {
        return true;
    }
    
    return false;
}

void exibirPilha(PILHA* p) {
    PONT end = p->topo;
    
    printf("Pilha: \" ");
    
    while (end != NULL) {
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    
    printf("\"\n");
}

bool inserirElementoPilha(PILHA* p, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    
    return true;
}

bool excluirElementoPila(PILHA* p, REGISTRO* reg) {
    if (p->topo == NULL) {
        return false;
    }
    
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

bool inverterPilha(PILHA* p) {
    PONT anterior = NULL;
    PONT atual = p->topo;
    PONT proximo = NULL;
    
    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    
    p->topo = anterior;
    
    return true;
    
}

int main() {
    
    PILHA pilha;
    int i;
    
    inicializarPilha(&pilha);
    
    printf("Está vazia %i \n", estaVazia(&pilha));
    
    for (i=0; i<10; i++){
        REGISTRO reg;
        reg.chave = i;
        inserirElementoPilha(&pilha, reg);
    }
    
    exibirPilha(&pilha);
    
    inverterPilha(&pilha);
    
    exibirPilha(&pilha);
    
    REGISTRO reg2;
    
    excluirElementoPila(&pilha, &reg2);
    
    
    printf("\ntamanaho: %d", tamanho(&pilha));
    
    return 0;
}