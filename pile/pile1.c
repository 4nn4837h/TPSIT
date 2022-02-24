#include <stdio.h>
#include <stdlib.h>
#define MAX 50
/************************************************************************************************************************************
Simondi Francesca IV A ROB - 18 / 12
ES: 1 Scrivere un programma che chieda all’utente una stringa composta da parentesi aperte e chiuse:
(,),[,],{,} e che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
************************************************************************************************************************************/

typedef struct Node{ // creazione della struttura di un nodo qualsiasi della pila
    char val;
    struct Node *next;
}Node;

Node* push(Node* testa, char n);
Node* pop(Node* testa);
int isEmpty(Node* testa); // prototipi delle funzioni

int main() {
    char stringa[MAX]; // stringa da passare (char per char) alla pila successivamente
    Node *stack = NULL; // nodo della pila
    int i = 0, cont;

    printf("Stringa: ");
    scanf("%s", stringa); // prendo in input la pila

    while(stringa[i] != '\0') { // se la stringa non è finita
        if(stringa[i] == '(' || stringa[i] == '[' || stringa[i] == '{') stack = push(stack, stringa[i]);
        else stack = pop(stack); // dopo aver controllato che fosse una parentesi aperta
        i++;
    }

    cont = isEmpty(stack); // conta quante celle della pila ci sono

    if(cont == 0) {
        printf("Stringa corretta\n");
    }
    else {
        printf("Stringa non corretta\n");
        printf("Numero di caratteri nello stack: %d", cont);
    }

    free(stack);
    printf("\n");
    system("pause");
    return 0;
}

Node* push(Node* testa, char val) { // immette un nuovo elemento in ultima posizione (LIFO)
    Node *successivo;

    if(testa != NULL) { // se punta a qualcosa
        successivo = testa; // successivo è quello corrente
        testa = (Node*)malloc(sizeof(Node)); // quello corrente è nuovo
        testa->val = val; // al suo campo val viene caricato il valore passato per valore nella funzione
        testa->next = successivo; // al campo next di quello nuovo si passa l'indirizzo di successivo
    } else {
        testa = (Node*)malloc(sizeof(Node)); // si crea il primo nodo della stack == pila
        testa->val = val;
        testa->next = NULL; // non ci sarà un nodo precendente -> next == NULL
    }
    return testa;
}

Node* pop(Node* testa) { // funzione per togliere l'ultimo elemento della pila
    Node* successivo = NULL;

    if(testa != NULL) { // se la pila non è vuota
        successivo = testa; // passo NULL alla testa
        testa = testa->next; // e la t
        free(successivo); // libero "successivo"
    }
    return testa;
}

int isEmpty(Node* testa) {
    int cont = 0; // si parte da 0 nel caso fosse vuota

    while(testa != NULL) { // continuo a contare finché il puntatore non vale NULL == fine pila
        cont++;
        testa = testa->next;
    }
    return cont; // int del numero di nodi della pila
}
