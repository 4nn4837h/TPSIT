#include <stdio.h>
#include <stdlib.h>
#define MAX_LISTA 20
/**
ESERCIZIO 1: LISTE
Sia data una struttura dati dinamica di tipo lista semplicemente concatenata.
Ogni nodo della lista contiene un numero intero come valore.
Si scriva la funzione che, dato un vettore di N numeri interi, restituisce la lista contenente gli N elementi del vettore;
l’elemento di indice 0 va in testa alla lista, ecc.
*/

typedef struct nodo {
    int num;
    struct nodo *next;
} Lista;

int prendiDimensione() {
    int n;
    do {
        printf("Inserisci la dimensione del vettore: ");
        scanf("%d", &n);
    } while(n < 0);
}

void stampaLista(Lista *curr, int n) {
     while(curr != NULL){
     printf("%d\n", curr->num); // stampo il numero
     curr = curr->next;
    }
}

Lista *creaNodo(int val, Lista *nodo){
     Lista* succ = (Lista*) malloc (sizeof(Lista)); // creo la sola cella
     if(nodo != NULL) nodo->next=succ; // tiro la freccia alla nuova cella
     succ->num = val;
     succ->next = NULL; // perché è l'ultimo
     return succ;
}

void deallocazioneLista( Lista* curr, int n){
     Lista *prec;
     for( int i = n - 1; i > 0; i--){
          free(curr);
          //prec->next -= 1;
     }
}

int main() {
    int n = prendiDimensione();
    int valori[n];
    int i;
    for( i = 0; i < n; i++){
     valori[i] = i + 1;
    }// inizializzazione dell'array di valori

    Lista* head = NULL;
    Lista* curr = NULL; // è buona norma inizializzare a NULL

    for(int k = 0; k < i; k++){
     curr = creaNodo(valori[k], curr);
     if(head == NULL) head = curr; // dobbiamo farlo perché altrimenti la testa potrebbe non essere inizializzata
    }

    curr = head; //andiamo nella testa della lista
    stampaLista(curr, n);

    // come fare a deallocare tutti gli elementi della lista?
    // devo fare un for dal fondo, perché altrimenti non abbiamo più il next
    curr = curr[n - 1];
    deallocazioneLista(curr, n);

    printf("\n");
    return 0;
}
