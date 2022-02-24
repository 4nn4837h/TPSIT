#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/************************************************************************************************************************************
Simondi Francesca IV A ROB - 12 / 11
ES: 2
Scrivere un programma che permette all�utente di inizializzare un array (unidimensionale)
di float e ( facendo uso dell�aritmetica dei puntatori:
- individui gli elementi con valore ripetuti;
-sommi i numeri rimasti;
************************************************************************************************************************************/

int inserisciDim() {
    int dim;
    do {
        printf("Inserisci la dimensione che vuoi dell'array: ");
        scanf("%d", &dim);
    } while(dim < 0);
    return dim;
}

float sommaNonRipetuti(float *a, int dim) {
    float somma = 0;
    for(int i = 0; i < dim; i++) { // prendo la cella i
        for(int k = 0; k < dim; k++) { // la cella i la confronto con tutto l'array
            if( *(a + i) != *(a + k)) { // se il valore della cella con indice i � uguale a quello con indice k non ne faccio la somma
                somma = somma + *(a + i);
            }
        }
    }
    return somma;
}

int main() {
    int dim = inserisciDim();
    // allocazione dinamica:
    float *a = (float *) malloc ( dim * sizeof(float));

    //inserisci i numeri in input:
    for(int i = 0; i < dim; i++) {
        printf("Cella [%d] = ", i);
        scanf("%f", a + i);
    }
    // somma non ripetuti:
    float somma = sommaNonRipetuti(a, dim);
    printf("La somma dei numeri non ripetuti vale: %f", somma);
    //deallocazioene dinamica:
    free(a);
    printf("\n");
    return 0;
}
