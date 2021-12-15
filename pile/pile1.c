#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct Node{
    char val;
    struct Node *next;
}Node;

Node* push(Node* testa, char n);
Node* pop(Node* testa);
int isEmpty(Node* testa);

int main() {
    char stringa[MAX];
    Node *stack = NULL;
    int i = 0;
    int cont;

    printf("Stringa: ");
    scanf("%s", stringa);

    while(stringa[i] != '\0') {
        if(stringa[i] == '(' || stringa[i] == '[' || stringa[i] == '{') {
            stack = push(stack, stringa[i]);
        }
        else {
            stack = pop(stack);
        }
        i++;
    }

    cont = isEmpty(stack);

    if(cont == 0) {
        printf("Stringa corretta\n");
    }
    else {
        printf("Stringa non corretta\n");
        printf("Numero di caratteri nello stack: %d", cont);
    }

}

Node* push(Node* testa, char val) {
    Node *successivo;

    if(testa != NULL) {
        successivo = testa;
        testa = (Node*)malloc(sizeof(Node));
        testa->val = val;
        testa->next = successivo;
    } else {
        testa = (Node*)malloc(sizeof(Node));
        testa->val = val;
        testa->next = NULL;
    }

    return testa;
}

Node* pop(Node* testa) {
    Node* successivo = NULL;

    if(testa != NULL) {
        successivo = testa;
        testa = testa->next;
        free(successivo);
    }

    return testa;
}

int isEmpty(Node* testa) {
    int cont = 0;

    while(testa != NULL) {
        cont++;
        testa = testa->next;
    }

    return cont;
}