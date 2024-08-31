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
    PONT inicio;
} LISTA;

PONT buscaSequencial(LISTA *l, TIPOCHAVE ch, PONT* ant) {
    *ant = NULL;
    PONT atual = l->inicio;
    
    while ((atual != NULL) && (atual->reg.chave < ch)) {
        *ant = atual;
        atual = atual->prox;
    } 
    
    if ((atual != NULL) && (atual->reg.chave == ch)) {
        return atual;
    }
    
    return NULL;
}

bool inserirElemLista(LISTA *l, REGISTRO reg) {
    TIPOCHAVE ch = reg.chave;
    PONT ant, i;
    
    i = buscaSequencial(l, ch, &ant);
    
    if (i != NULL) {
        return false;
    }
    
    i = (PONT) malloc(sizeof(ELEMENTO));
    
    i->reg = reg;
    
    if (ant == NULL) {
        i->prox = l->inicio;
        l->inicio = i;
    } else {
        i->prox = ant->prox;
        ant->prox = i;
    }
}

void exibirLista(LISTA* l) {
    PONT endereco = l->inicio;
    printf("Lista: ");

    while (endereco != NULL) {
        printf("%d ", endereco->reg.chave);
        endereco = endereco->prox; 
    }

}

void exibirListaRecursivo(PONT atual) {
    if (atual == NULL) {
        return;
    } 
    
    printf("%d ", atual->reg.chave);
    
    exibirListaRecursivo(atual->prox);
    
}

int tamanhoListaRecursivo(PONT atual, int tamanhoAtual) {
    if (atual == NULL) {
        return tamanhoAtual;
    }
    
    return tamanhoListaRecursivo(atual->prox, tamanhoAtual+1);
    
}

void inverterLista(LISTA* l) {
    
    PONT ant = NULL;
    PONT atual = l->inicio;
    PONT prox = NULL;
    
    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    
    l->inicio = ant;
    
}

void incializarLista(LISTA* l) {
    l->inicio = NULL;
}

int main() {
    
    LISTA lista;
    REGISTRO reg;
    int i;
    
    incializarLista(&lista);
    
     for (i = 11; i > 0; i--) {
        reg.chave = i;
        
        inserirElemLista(&lista, reg);
     }
     
     //exibirLista(&lista);
    
     exibirListaRecursivo(lista.inicio);
     
     int tamanho = tamanhoListaRecursivo(lista.inicio, 0);
     
     printf("\n %d", tamanho);
    
    return 0;
}
