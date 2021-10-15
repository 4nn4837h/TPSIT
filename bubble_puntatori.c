#include <stdio.h>
#include <stdlib.h>
/*
Togliere le parentesi quadre dal codice del Bubble sort
*/

int chiediDim(char frase[]) {
    int d;
    printf("%s", frase);
    do {
        scanf("%d", &d);
    } while(d <= 0);
    return d;
}

void bubbleSort3(float v[], int n) {
    int k;
    int sup = n - 1;// j == sup
    float t;

    for(k = 0; k < sup; k++) {
        for(sup = n - 1; sup > 0; sup--) {
            if(v[k] > v[k + 1]) {
                t = v[k];
                v[k] = v[k + 1];
                v[k + 1] = t;
            }
        }
    }
}

void bubbleSortSenzaQuadre(float v[], int n) {
    int k;
    int sup = n - 1;// j == sup
    float t;

    for(k = 0; k < sup; k++) {
        for(sup = n - 1; sup > 0; sup--) {
            if(*(v + n) > *(v + (n + 1))) { // se avessi scritto *v + n, se nella cella di indirizzo v ha 100, diventa 100 + n
                t = *(v + n);
                *(v + n) = *(v + (n + 1));
                *(v + (n + 1)) = t;
            }
        }
    }
}

void stampaVett(float v[], int n, char frase[]) {
    printf("\n%f\n", frase);
    for(int k = 0; k < n; k++) {
        printf("%3.2f\n", *(v+k)); // printf("%3.2f\n", v+k); ==> stampa l'indirizzo delle celle
    }
}

void caricaVett(float v[], int n) {
    for(int k = 0; k < n; k++) {
        printf("Inserisci il numero nella cella v[%d]: ", k);
        scanf("%f", v+k);
    }
}

void copiaVett(float v[], float v0[], int n) {
    for(int k = 0; k < n; k++) {
        *(v + k) = *(v0 + k);
    }
}

int main() {
    int dim = chiediDim("Inserire la quantita' di numeri che si vuole inserire: ");
    float v0[dim], v1[dim];

    printf("Inserisci i numeri del vettore:\n");
    caricaVett(v0, dim);
    copiaVett(v1, v0, dim);

    bubbleSort3(v0, dim); // argomenti == parametri attuali
    stampaVett(v0, dim, "Bubble Sort con quadre");
    bubbleSortSenzaQuadre(v1, dim);
    stampaVett(v1, dim, "Bubble Sort senza quadre");
    printf("\n");
    system("pause");
    return 0;
}
