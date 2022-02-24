#include <stdio.h>
#include <stdlib.h>
#define MAX 99
/************************************************************************************************************************************
Simondi Francesca IV A ROB - 29 / 10
ES: 2
scrivere un programma che chieda n valori interi (max 100), li collochi in un vettore e inverta il vettore
(scambiando il primo elemento con l'ultimo, il secondo con il penultimo ecc). Si usino i puntatori.
************************************************************************************************************************************/

void inserisci(int *v, int *n) {
    do {
        printf("Quanti elementi vuoi che abbia il tuo vettore?\n");
        scanf("%d", n);
    } while( *n < 0 && *n > 100); // funzionava anche senza asterischi

    for(int k = 0 ; k < *n; k++) { // ci devo mettere per forza l'asterisco
        printf("Elemento della cella [%d]: ", k);
        scanf("%d", v + k);
    }
}

void scambia(int *v, int n) {
    int t;
    for(int k = 0; k < n/2; k++) { // faccio un for fino a met� perch� confronto a specchio
            t = *(v + k);
            *(v + k) = *(v + n - k - 1); // v + n-k-1: perch� devo contare che parte da 0
            *(v + n - k - 1) = t; // scambio
    }
}

void stampa(int *v, int n) {
    for(int k = 0; k < n; k++) {
        printf("[%d]", *(v + k));
    }
}
int main() {
    int dim = MAX;
    int *v;
    inserisci(v, &dim);
    *v = (int*) malloc(dim*sizeof(int)); // inizializzazione del vettore con malloc: puntatore
    // il vettore (prima posizione, ovvero con inidice 0) � un int*, per cui faccio un casting, perch� la maclloc restituisce un void*,
    // chiamo la funzione, moltiplico per quante celle voglio avere nel formato che voglio avere: � per avere il giusto numero di celle

    scambia(v, dim);
    stampa(v, dim);

    printf("\n");
    system("pause");
    return 0;
}
