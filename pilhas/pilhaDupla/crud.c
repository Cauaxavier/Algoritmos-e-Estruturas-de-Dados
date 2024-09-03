#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int topo1;
    int topo2;
} PILHADUPLA;

void inicializarPilhaDupla(PILHADUPLA* p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}

int tamanhoPilhaDupla(PILHADUPLA* p) {
    
    int tamanhoTopo1 = p->topo1 + 1;
    int tamanhoTopo2 = MAX - p->topo2;
    
    return tamanhoTopo1 + tamanhoTopo2;
}

bool exibirUmaPilha(PILHADUPLA* p, int pilha) {
    if (pilha < 1 || pilha > 2) {
        return false;
    }
    
    printf("PILHA%d: ", pilha);
    
    int i;
    
    if (pilha == 1) {
        for (i=p->topo1; i >= 0; i--) {
            printf("%d ", p->A[i].chave);
        }
    } else if (pilha == 2) {
        for (i=p->topo2; i < MAX; i++) {
            printf("%d ", p->A[i].chave);
        }
    }
    
    printf("\n");

    return true;
}

bool inserirElementoPilha(PILHADUPLA* p, REGISTRO reg, int pilha) {
    if (pilha < 1 || pilha > 2) {
        return false;
    }

    if (p->topo1 + 1 == p->topo2) {
        return false;
    } 
    
    if (pilha == 1) {
        p->topo1 = p->topo1 + 1;
        p->A[p->topo1] = reg;
    } else {
        p->topo2 = p->topo2 - 1;
        p->A[p->topo2] = reg;
    }
 
    return true;
    
}

bool excluirElementoPilha(PILHADUPLA* p, REGISTRO* reg, int pilha) {
    if (pilha < 1 || pilha > 2) {
        return false;
    }
    
    if (pilha==1) {
        
        if (p->topo1 == -1) {
            return false;
        }
        
        *reg = p->A[p->topo1];
        p->topo1 = p->topo1 - 1;
    } else {
        
        if (p->topo2 == MAX) {
            return false;
        }
        
        *reg = p->A[p->topo2];
        p->topo2 = p->topo2 + 1;
        
    }
    
    return true;
}

void reinicializarPilha(PILHADUPLA* p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}

int main() {
    
    PILHADUPLA pilha;
    REGISTRO registro;
    
    int i;
    
    inicializarPilhaDupla(&pilha);
    
     for (i = 0; i < 4; i++) {
        registro.chave = i;
        inserirElementoPilha(&pilha, registro, 1);
    }
    
    for (i = 7; i >= 4; i--) {
        registro.chave = i;
        inserirElementoPilha(&pilha, registro, 2);
    }
    
    excluirElementoPilha(&pilha, &registro, 1);
    excluirElementoPilha(&pilha, &registro, 2);
    
    exibirUmaPilha(&pilha, 1);
    exibirUmaPilha(&pilha, 2);
    
    return 0;
}