#include <stdio.h>
#include <stdlib.h>
#define DIM1 100
#define DIM2 100
/**
Simondi Francesca IV A ROB
Si scriva una funzione malloc2d, in grado di allocare una matrice di numeri float, le cui dimensioni sono ricevute come parametri.
La matrice viene inizializzata azzerando tutte le caselle.
**/

int nr, nc;

void mettiDim(int *nr, int *nc) {
    do {
        printf("Inserire il numero di righe: ");
        scanf("%d", nr);
        printf("Inserire il numero di colonne: ");
        scanf("%d", nc);
    } while (nr == 0 || nc == 0);
}

void inizializza(float **m, int nr, int nc) {
    for(int r = 0; r < nr; r++) {
        for(int c = 0; c < nc; c++) {
            *(*(m + r) + c) = 0.00; // m[r][c] = 0;
        }
    }
}

void stampa(float **m, int nr, int nc) {
    for(int r = 0; r < nr; r++) {
        for(int c = 0; c < nc; c++) {
            printf("m[%d][%d] = %d\t", r, c, *(*(m + r) + c));
        }
        printf("\n");
    }
}

void inserisciNumeri(float **m) {
    int n, r, c;
    printf("Inserisci il numero di numeriche vuoi inserire: ");
    scanf("%d", &n);
    while( n > 0) {
        printf("Inserisci la riga: ");
        scanf("%d", &r);
        printf("Inserisci la colonna: ");
        scanf("%d", &c);
        printf("Inserisci il numero che vuoi inserire nella matrice:\nNella riga %d; colonna %d: ", r, c);
        scanf("%f", &*(*(m + r) + c)); // prendo in input il valore che  viene inserito nella suddetta cella della matrice
        n--;
        printf("\n");
    }
    for(int r = 0; r < nr; r++) {
        for(int c = 0; c < nc; c++) {
            printf("m[%d][%d] = %d\t", r, c, *(*(m + r) + c));
        }
        printf("\n");
    }
}

int main() {

    mettiDim(&nr, &nc);

    // creo la matrice
    float **m = (float **) malloc(nr * sizeof(float)); // dim1 -> righe
    for(int i = 0; i < nr; i++) { // per il numero di righe: imposto le colonne
        *(m + i)= (float *) malloc(nc * sizeof(float));
    }

    //inizializza la matrice a 0 e stampa della matrice
    inizializza(m, nr, nc);
    stampa(m, nr, nc);
    // inserisci tutti i numeri che vuoi
    inserisciNumeri(m);
    printf("\nnon stampa la matrice cambiata\n");
    stampa(m, nr, nc);
     // faccio la free per liberare la memoria del computer
    free(m);

    printf("\n");
    system("pause");
    return 0;
}
