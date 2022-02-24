/* char scelta;
        printf("Vuoi uscire dal programma?");
        scanf("%c", &scelta);
        if(scelta == 'S' || scelta == 's'){
            esci = true;
        }
Implementare i metodi enqueue() e dequeue() e creare un programma che permetta
all'utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
SIMONDI FRANCESCA 21 / 01
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queueNode{ // creo la struttura della lista
     int elemento;
     struct queueNode *next;
}QueueNode;


int is_empty(QueueNode *head);
void enqueue(QueueNode **head, QueueNode **tail, QueueNode *element);
QueueNode*dequeue(QueueNode **head, QueueNode **tail);

int main(){
     QueueNode *head = NULL;
     QueueNode *tail = NULL; // puntatori alla testa e alla coda della coda
     QueueNode *struct_return = NULL; // var per il dato di ritorno della funzione
     QueueNode *element; // elemento nuovo
     bool condizione = true; // condizione per far continuare o finire il ciclo while
     int dato; // dato che si vuole inserire nella coda

     while(condizione){
         int scelta; // scelta del menù
         printf("MENU'\n\n >> 1 Inserisci elementi nella coda\n");
         printf(" >> 2 per svuotare la coda\n >> 3 per uscire dal programma\n\n Inserire numero: ");
         scanf("%d",&scelta);

         switch(scelta){
         case 1: // inserire il nuovo elemento nella coda
             printf("Inserire elemento: ");
             scanf("%d",&dato);
             element = (QueueNode*)malloc(sizeof(QueueNode)); // inizializzazione dell'elemento nuovo
             element->elemento = dato;
             enqueue(&head, &tail, element); // aggiunta
             break;

         case 2: // stampa della coda
             printf("Gli elementi inseriti fino ad ora sono:\t");
             while ((struct_return = dequeue(&head, &tail)) != NULL){ // finché la lista non è finita
                    printf("%d\t", struct_return->elemento);
                    free(struct_return);
             }
             printf("\n\n");
             break;

         case 3: // uscita dal programma
             printf("EXIT..");
             condizione = false;
             break;

         default: // se non si inserisce una scelta tra 1 e 3 (estremi compresi)
             printf("[carattere inserito non valido]\n\n");
             break;
         }
     }
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
