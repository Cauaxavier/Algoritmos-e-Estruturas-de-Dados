#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef enum{left, right} SIDE;
typedef int TYPEKEY;

typedef struct aux {
    TYPEKEY key;
    struct aux *right, *left;  // Corrigido o tipo da estrutura
} NO;

typedef NO* POINT;

POINT searchKey(TYPEKEY key, POINT root) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->key == key) {
        return root;
    }
    
    POINT aux = searchKey(key, root->left);
    
    if (aux) {
        return aux;
    }
    
    return searchKey(key, root->right);
}

POINT createNewNo(TYPEKEY key) {
    POINT newNo = (POINT) malloc(sizeof(NO));
    
    newNo->right = NULL;
    newNo->left = NULL;
    newNo->key = key;
    
    return newNo;
}

void createRoot(POINT* root, TYPEKEY key) {
    *root = createNewNo(key);
}

bool insertSon(POINT root, TYPEKEY newKey, TYPEKEY fatherKey, SIDE side) {
    POINT father = searchKey(fatherKey, root);
    
    if (!father) {
        return false;
    }
    
    POINT no = createNewNo(newKey);
    
    if (side == left) {
        father->left = no;
    } else {
        father->right = no;
    }
    
    return true;
}

void printTreePreOrder(POINT root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d ", root->key);
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}


void printTreeSymmetrical(POINT root) {
    if (root == NULL) {
        return;
    }
    
    printTreeSymmetrical(root->left);
    printf("%d ", root->key);
    printTreeSymmetrical(root->right);
}

void printPostOrder(POINT root) {
    if (root == NULL) {
        return;
    }
    
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->key);
}

int main () {
    POINT root = NULL;

    // Criando a raiz
    createRoot(&root, 10);
    printf("Raiz criada com chave: %d\n", root->key);

    // Inserindo nós
    insertSon(root, 5, 10, left);
    insertSon(root, 15, 10, right);
    insertSon(root, 3, 5, left);
    insertSon(root, 7, 5, right);
    insertSon(root, 12, 15, left);
    insertSon(root, 18, 15, right);

    // Imprimindo a árvore
    printf("Árvore em pré-ordem: ");
    printTreePreOrder(root);
    printf("\n");

    printf("Árvore ordem simétrica: ");
    printTreeSymmetrical(root);
    printf("\n");
    
    printf("Árvore ordem simétrica: ");
    printPostOrder(root);
    printf("\n");

    // Procurando uma chave
    TYPEKEY keyToSearch = 7;
    POINT foundNode = searchKey(keyToSearch, root);
    if (foundNode) {
        printf("Chave %d encontrada.\n", foundNode->key);
    } else {
        printf("Chave %d não encontrada.\n", keyToSearch);
    }

    return 0;
}