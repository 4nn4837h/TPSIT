/************************************************************************************************************************************
SIMONDI FRANCESCA 4 A ROB - 21 / 01
ES: 2
Scrivere una funzione che inverta una coda, ovvero produca degli elementi  della coda di partenza. 
Suggerimento: utilizzare una pila
************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queueNode{ // struttura del nodo della coda
     int elemento;
     struct queueNode *next;
}QueueNode;

typedef struct pileNode{ // struttura del nodo della pila
    int elemento;
    struct pileNode *next; // puntatore al nodo precedente se si vuole
}PileNode

int is_empty(QueueNode *head);
void enqueue(QueueNode **head, QueueNode **tail, QueueNode *element);
QueueNode*dequeue(QueueNode **head, QueueNode **tail);

int main(){
     QueueNode *headQ = NULL;
     QueueNode *tailQ = NULL;
     QueueNode *struct_returnQ = NULL;
     QueueNode *elementQ; // variabili per la coda
     PileNode *elementP = NULL;
     PileNode *tail = NULL; // variabili per la pila
     bool condizione = true;
     int dato, nodiCoda, n = 0;

    printf("Inserisci il numero di nodi che vuoi che la coda abbia: ");
    scanf("%d", nodiCoda);

    while(n < nodiCoda){ // finché non ha inserito quanti numeri desidera nella coda il ciclo non finisce
        printf("Inserire elemento: ");
        scanf("%d", &dato); // reperimento del dato
        elementQ = (QueueNode*)malloc(sizeof(QueueNode));
        elementQ->elemento = dato; // inizializzazione dell'elemento da inserire nella coda
        enqueue(&head, &tail, element); // inserimento dell'elemento
    }

    while ((struct_returnQ = dequeue(&head, &tail)) != NULL){ // svuoto la coda
        elementP = (PileNode*)malloc(sizeof(PileNode)); // creo l'elemento della pila
        elementP->elemento = struct_returnQ->elemento; // passo il valore dell'"elemento" della coda estratto del nodo tolto
        push(elementP); // faccio la push dell'elemento
        free(struct_return); // faccio la free così lo posso rifare
    }
    printf("\n\n");
    break;
    return 0;
}

int is_empty(QueueNode*head){ // si controlla la coda: se è piena o meno
     if(head == NULL) return 1;
     else return 0;
}

void enqueue(QueueNode **head, QueueNode **tail, QueueNode *element){ // aggiunta dell'elemento in ultima posizione:coda == til
     if(is_empty(*head)) *head = element; // alla head passo element
     else(*tail)->next = element; // il next lo faccio puntare ad element così abbiamo la posizione della coda
     *tail = element;
     element->next = NULL; // dato che è l'ultimo elemento il puntatore dice NULL
}

QueueNode*dequeue(QueueNode **head, QueueNode **tail){ // tolgo il primo elemento della coda: testa == head
    QueueNode* ret = *head;
    if(is_empty(*head)) return NULL; // se è vuota non può fare nulla
    else *head = ret->next; // se c'è allora il puntatore della testa punterà a next: così non si potrà più accedere alla testa "precedente" in sostanza

    if (*head == NULL) *tail = NULL; // se non c'è una testa allora non ci sarà una coda
    return ret;
}

PileNode* push(Node* testa) {
    Node *successivo;

    if(testa != NULL) {
        successivo = testa;
        testa = (Node*)malloc(sizeof(Node));
        testa->next = successivo;
    } else {
        testa = (Node*)malloc(sizeof(Node));
        testa->next = NULL;
    }
    return testa;
}

PileNode* pop(Node* testa) {
    Node* successivo = NULL;

    if(testa != NULL) {
        successivo = testa;
        testa = testa->next;
        free(successivo);
    }
    return testa;
}

int isEmptyPile(Node* testa) {
    int cont = 0;

    while(testa != NULL) {
        cont++;
        testa = testa->next;
    }
    return cont;
}

