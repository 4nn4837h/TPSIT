/************************************************************************************************************************************
SIMONDI FRANCESCA 4 A ROB - 21 / 01
ES: 2
Scrivere una funzione che inverta una coda, ovvero produca degli elementi  della coda di partenza.
Suggerimento: utilizzare una pila.
************************************************************************************************************************************/
// righe:50, 58, 59, 76, 77
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queueNode{ // struttura del nodo della coda
     int elemento;
     struct queueNode *next;
     struct queueNode *head;
}QueueNode;

typedef struct pileNode{ // struttura del nodo della pila
    int elemento;
    struct pileNode *next; // puntatore al nodo precedente se si vuole
}PileNode;

int is_empty(QueueNode *head);
void enqueue(QueueNode **head, QueueNode **tail, QueueNode *element);
QueueNode*dequeue(QueueNode **head, QueueNode **tail);
PileNode* push(PileNode* testa, int val);
PileNode* pop(PileNode* testa);
int isEmptyPile(PileNode* testa);

int main(){
     QueueNode *headQ = NULL;
     QueueNode *tailQ = NULL;
     QueueNode *struct_returnQ = NULL;
     PileNode *struct_returnP = NULL;
     QueueNode *elementQ; // variabili per la coda
     PileNode *elementP = NULL;
     PileNode *tail = NULL; // variabili per la pila
     bool condizione = true;
     int dato, nodiCoda, n = 0;

    printf("Inserisci il numero di nodi che vuoi che la coda abbia: ");
    scanf("%d", &nodiCoda);

    while(n < nodiCoda){ // finché non ha inserito quanti numeri desidera nella coda il ciclo non finisce
        printf("Inserire l'elemento %d: ", n+1);
        scanf("%d", &dato); // reperimento del dato
        elementQ = (QueueNode*)malloc(sizeof(QueueNode));
        elementQ->elemento = dato; // inizializzazione dell'elemento da inserire nella coda
        enqueue(&headQ, &tailQ, elementQ); // inserimento dell'elemento
        //free(elementQ);
        n ++;
    } // fin qui funziona bene
    n = 0;
    while ((struct_returnQ = dequeue(&headQ, &tailQ)) != NULL && n < nodiCoda){ // svuoto la coda
        elementP = (PileNode*)malloc(sizeof(PileNode)); // creo l'elemento della pila
        dato = struct_returnQ->elemento; // passo il valore dell'"elemento" della coda estratto del nodo tolto
        push(elementP, dato); // faccio la push dell'elemento così lo aggiungo in testa alla coda
        //free(elementP);
        //free(struct_returnQ); // se metto uno di questi due mi mette error 0x000005 -> errore nel puntatore
    } // fin qui funziona

    //free(struct_returnQ); // se lo metto mi mette errore 374 -> heap corruption
    printf("\n%d\n", nodiCoda);
    n = 0;
    while(n < nodiCoda && !isEmpty(tail)){ // finché non ha inserito quanti numeri desidera nella coda il ciclo non finisce
        elementQ = (QueueNode*)malloc(sizeof(QueueNode));
        //free(struct_returnP); // con o senza questo l'errore è sempre lo stesso
        struct_returnP = (PileNode*)malloc(sizeof(PileNode));
        struct_returnP = pop(tail);
        printf("-> problema riga 72\n");
        dato = (*struct_returnP).elemento; // struct_returnP->elemento
        printf("->%d - \n", dato);
        elementQ->elemento = dato; // inizializzazione dell'elemento da inserire nella coda
        printf("problema 1");
        enqueue(&headQ, &tailQ, elementQ); // inserimento dell'elemento
        //free(elementQ); // faccio la free così lo posso rifare
        //free(struct_returnP); // faccio la free così lo posso rifare
        printf("problema 2");
        n++;
    }

     n = 0;
    while ((struct_returnQ = dequeue(&headQ, &tailQ)) != NULL && n < nodiCoda){
          printf("Elemento %d: %d\n", n+1, struct_returnQ->elemento);
          free(struct_returnQ); // faccio la free così lo posso rifare
          n++;
    }

    free(headQ);
    free(tailQ);
    free(tail);
    free(elementP);
    free(elementQ); // faccio la free così si ripulisce la memoria
    printf("\n\n");
    return 0;
}

int is_empty(QueueNode*head){ // si controlla la coda: se è piena o meno
     if(head == NULL) return 1;
     else return 0;
}

void enqueue(QueueNode **head, QueueNode **tail, QueueNode *element){ // aggiunta dell'elemento in ultima posizione:coda == tail
     if(is_empty(*head)) *head = element; // alla head passo element
     else(*tail)->next = element; // il next lo faccio puntare ad element così abbiamo la posizione della coda
     *tail = element;
     element->next = NULL; // dato che è l'ultimo elemento il puntatore dice NULL
}

QueueNode* dequeue(QueueNode **head, QueueNode **tail){ // tolgo il primo elemento della coda: testa == head
    QueueNode* ret = *head;
    if(is_empty(*head)) return NULL; // se è vuota non può fare nulla
    else *head = ret->next; // se c'è allora il puntatore della testa punterà a next: così non si potrà più accedere alla testa "precedente" in sostanza

    if (*head == NULL) *tail = NULL; // se non c'è una testa allora non ci sarà una coda
    return ret;
}

PileNode* push(PileNode* testa, int val) { // immette un nuovo elemento in ultima posizione (LIFO)
    PileNode *successivo;

    if(testa != NULL) { // se punta a qualcosa
        successivo = testa; // successivo è quello corrente
        testa = (PileNode*)malloc(sizeof(PileNode)); // quello corrente è nuovo
        testa->elemento = val; // al suo campo val viene caricato il valore passato per valore nella funzione
        testa->next = successivo; // al campo next di quello nuovo si passa l'indirizzo di successivo
    } else {
        testa = (PileNode*)malloc(sizeof(PileNode)); // si crea il primo nodo della stack == pila
        testa->elemento = val;
        testa->next = NULL; // non ci sarà un nodo precendente -> next == NULL
    }
    return testa;
}

PileNode* pop(PileNode* testa) { // funzione per togliere l'ultimo elemento della pila
    PileNode* successivo = NULL;
    if(testa != NULL) { // se la pila non è vuota
        successivo = testa; // passo NULL alla testa
        testa = testa->next; // e la testa si aggiorna
        free(successivo); // libero "successivo"
    }
    return testa;
}

int isEmpty(PileNode* testa) {
    int cont = 0; // si parte da 0 nel caso fosse vuota
    while(testa != NULL) { // continuo a contare finché il puntatore non vale NULL == fine pila
        cont++;
        testa = testa->next;
    }
    return cont; // int del numero di nodi della pila
}

