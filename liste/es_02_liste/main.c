#include <stdio.h>
#include <stdlib.h>
/**
ESERCIZIO 2 - Simondi Francesca IV A ROB
Si scriva la funzione che stampa a terminale i valori contenuti nella lista in
ordine inverso rispetto a quello della lista stessa (leggendoli dalla lista,
non dal vettore).
*/

typedef struct nodo {
    int num;
    struct nodo *next; // punta a se stessa
    struct nodo *prec = *next - 1;
} Lista;

int prendiDimensione() {
    int n;
    do {
        printf("Inserisci la dimensione del vettore: ");
        scanf("%d", &n);
    } while(n < 0);
}

void stampaLista(Lista *curr, int n) {
    while(curr != NULL) {
        printf("%d\n", curr->num); // stampo il numero
        curr = curr->prec;
    }
}

int main() {
    int n = prendiDimensione();
    int valori[n];
    int i;
    for( i = 0; i < n; i++) {
        valori[i] = i + 1;
    }// inizializzazione dell'array di valori

    Lista* head = NULL;
    Lista* curr = NULL; // è buona norma inizializzare a NULL

    printf("\n");
    system("Pause");
    return 0;
}
