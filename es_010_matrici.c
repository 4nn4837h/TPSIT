#include <stdio.h>
#include <stdlib.h>
#define REPARTI 3
#define MESI 6
#define LUNG 20
/**********************************************************************************************************************************
Simondi Francesca IV A ROB
ES: 10
I dati sugli incassi di 3 reparti di un magazzino nei primi 6 mesi sono
organizzati in una matrice, il numero di riga indica il numero del reparto,
il numero di colonna indica il mese.
1. Calcolare l'incasso totale per ogni mese;
2. l'incasso totale per ogni reparto;
3. l'incasso totale per tutti i reparti nel periodo considerato.
**********************************************************************************************************************************/

int stampaMenu() {
    int scelta;
    printf("\n\n>> Scegli con un numero l'alternativa che vuoi testare :");
    printf("\n - 0 -  Esci dal programma;");
    printf("\n - 1 -  Carica la matrice, la tabella;");
    printf("\n - 2 -  Calcola l'incasso totale di ogni mese;");
    printf("\n - 3 -  Calcola l'incasso totale per ogni reparto;");
    printf("\n - 4 -  Calcola l'incasso totale per tutti i reparti nel periodo considerato;");
    printf("\nScelta: ");
    scanf("%d", &scelta);
    printf("\n");
    return scelta;
}
// dato che è una matrice devo sempre darle la seconda dimensione
void caricaMatrice(float m[][MESI], int nR, int nC) {
    FILE *f; // creo il file
    //f = "matrice.txt";
    f = fopen("matrice.txt", "r");  // se il file esiste il cursore viene posizonato all'inizio del file (con un while lo si legge tutto)
    if (f == NULL) { // se il file non esiste
        printf("Il file e' inesistente.\n");
    }
     int k;
    for(k = 0; k < MESI; k++) {
        fscanf(f, "%f-%f-%f\n", &m[k][0], &m[k][1], &m[k][2]);
    }
    /*
    for( int k = 0; k < nR; k++) {
        printf(">>> %d° reparto:\n", k); // k = colonne
        for(int i = 0; i < nC; i++) {
            printf("> %d° mese:\n", i); // i = righe
            scanf("%f", &m[k][i]);
        }
    }
    */
    fclose(f); // chiudo il file
}

void incassoReparto(float m[/*REPARTI*/][MESI]) {
     FILE* f;
     f/*[LUNG]*/ = "risultati.txt";
     f = fopen("risultati.txt", "w");
    float somma = 0;
    int k, i;

    for(k = 0; k < REPARTI; k++) {// scorro ogni reparto
        for(i = 0; i < MESI; i++) { // scorro il mese -> somma del mese
            somma = somma + m[i][MESI];
        }
        fprintf("risultati.txt", "L'incasso totale per il %d mese e': %.2f\n", k, somma);
    }
}

void incassoTotale(float m[/*REPARTI*/][MESI]) {
     FILE* f;
     f/*[LUNG]*/ = "risultati.txt";
     f = fopen("risultati.txt", "w");
    float somma = 0;
    int k, i;

    for(i = 0; i < MESI; i++) { // scorro ogni mese
        for(k = 0; k < REPARTI; k++) {// scorro il reparto -> somma del reparto
            somma = somma + m[REPARTI][k];
        }
        fprintf("risultati.txt", "L'incasso totale per il %d reparto e': %.2f\n", i, somma);
    }
}

float incassoTot( float m[][MESI], int x, int y) {
    float s = 0;
    int k, i;

    for(k = 0; k < y; k++) { // scorre colonne
        for(i = 0; i < x; i++) { // scorre righe
            s = s + m[x][y];
        }
    }
    return s;
}

void showMatrice(float m[][MESI], int x, int y) {
    for(int k = 0; k < y; k++) {
        for(int i = 0; i < x; i++) {
            printf("%7.2f", m[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int scelta;
    float m[REPARTI][MESI];
    FILE *fs;

    fs = fopen("risultati.txt", "a"); // il nome del file su cui vado a scrivere i risultati lo apro in append
    float somma = 0;

    do {
        scelta = stampaMenu(); // la scelta viene fatta
        switch (scelta) { // in base alla scelta chiamo diverse funzioni e procedure
        case 1:
            caricaMatrice(m, REPARTI, MESI); // prende i dati, e passa sempre matrice e dimensioni, così la funzione resta generica
            showMatrice(m, REPARTI, MESI); // stampa la matrice
            break;
        case 2:
            incassoReparto(m);
            break;
        case 3:
            incassoTotale(m);
            break;
        case 4:
            somma = incassoTot(m, REPARTI, MESI);
            fprintf("risultati.txt", "La somma dell'incasso nell'intero periodo di tutti i reparti e': %.2f\n", somma);
            break;
        }

    } while(scelta != 0); // clicchi 0: esci dal programma

    fclose(fs);
    printf("\n");
    return 0;
    system("pause");
}
