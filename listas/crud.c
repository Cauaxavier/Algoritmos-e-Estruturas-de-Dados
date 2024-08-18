#include <stdio.h>
#include <stdbool.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX+1];
    int numElem;
} LISTA;

void inicializarLista(LISTA* l) {
    l->numElem = 0;
}

void tamanho(LISTA* l) {
    printf("Quantidade de elementos da lista: %d\n", l->numElem);
}

void exibirLista(LISTA* l) {
    int i;
    printf("Lista: \" ");
    for (i = 0; i < l->numElem; i++) {
        printf("%d ", l->A[i].chave);
    }
    printf("\"\n");
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch) { 
    // menos eficiente
    int i;
    for (i = 0; i < l->numElem; i++) {
        if (ch == l->A[i].chave) {
            return i;
        }
    }
    return -1;
}

int buscaSentinela(LISTA* l, TIPOCHAVE  ch) {
    // eficiente se a lista não está ordenado
    int i = 0;

    l->A[l->numElem].chave = ch;

    while (l->A[i].chave != ch) {
        i++;
    }

    if (i == l->numElem) {
        return -1;
    }

    return i;
}

int buscaBinaria(LISTA* l, TIPOCHAVE ch) {
    // mais eficiente se tiver ordenado
    int esq, dir, meio;

    esq = 0;
    dir = l->numElem-1;

    while (esq <= dir) {
        meio = ((esq + dir) / 2);

        if (l->A[meio].chave == ch) {
            return meio;
        } else if (l->A[meio].chave < ch) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return -1;
}

bool inserirElemLista(LISTA* l, REGISTRO reg, int i) {
    int j;
    
    if (l->numElem == MAX | i < 0 | i > l->numElem) {
        return false;
    }
    
    for (j = l->numElem; j > i; j--) {
        l->A[j] = l->A[j-1];
    }
    
    l->A[i] = reg;
    l->numElem++;
    return true;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {

    if (l->numElem >= MAX) {
        return false;
    }

    int pos = l->numElem;

    while (pos > 0 && l->A[pos-1].chave > reg.chave) {
        l->A[pos] = l->A[pos-1];
        pos--;
    }

    l->A[pos] = reg;
    l->numElem++;
}

bool excluirElemLista(TIPOCHAVE ch, LISTA* l) {
    int pos, j;
    pos = buscaBinaria(l, ch);
    
    if (pos == -1) {
        return false;
    }
    
    for (j = pos; j < l->numElem-1; j++) {
        l->A[j] = l->A[j+1]; 
    }
    
    l->numElem--;
    return true;
}

int main() {
    
    LISTA lista;
    REGISTRO registro;
    
    registro.chave = 7;
    
    inicializarLista(&lista);
    int i;
    for (i = 0; i < 10; i++) {
        lista.A[i].chave = i+1;
        lista.numElem++;
    }
    
    excluirElemLista(7, &lista);

    inserirElemListaOrd(&lista, registro);
    
    tamanho(&lista);
    
    exibirLista(&lista);
    
    int indexChave = buscaSequencial(&lista, 8);

    printf("O indice para esse valor é: %d\n", indexChave);

    int indexChave2 = buscaSentinela(&lista, 90);
    
    printf("O indice para esse valor é: %d\n", indexChave2);

    int indexChave3 = buscaBinaria(&lista, 8);
    
    printf("O indice para esse valor é: %d\n", indexChave3);
    
    exibirLista(&lista);
    
    return 0;
}