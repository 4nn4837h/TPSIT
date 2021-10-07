#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 25
#define MAX_LUNG 50

/************************************************************************************************************************************
ES: 03
La videoteca "Ciak film" necessita di un programma che carichi la lista film in un array di struttura e che stampi a video i 5 campi:
numero, titolo film, genere, anno di uscita, disponibilità film.

strtok(variabileStringa, simbolo/letteraConCuiSiDistruggeLaStringa); -- passando NULL
fgets(varibilePerS[], lungMaxStringa, nomeFile);
************************************************************************************************************************************/

typedef struct {
    int numero;
    char titolo[LUNG];
    char genere[LUNG];
    int anno;
    char disponibile[LUNG];
} Lista;

int caricaTabella(Lista film[MAX_LUNG], int nMax, char nomeFile[]) {
    int dim;
    FILE *fp;
    int k, j;
    char *parola;

    fp = fopen(nomeFile, "r");
    if(fp == NULL) {
        printf("Il file %s non esiste", nomeFile);
    } else {
        k = 0;
        while(k < nMax && (fscanf(fp, "%d", film[k].numero) != EOF)) { // inizio a inserire il nome
               while(parola != NULL){
            strtok(parola, ','); // nel puntatore parola metto tutte le parole divise dalla , e le stampoman mano
               } // finché non vale null, e quindi vuol dire che vi è il carattere terminatore
            fscanf(fp, "%d", film[k].anno);
            fgets(film[k].disponibile, LUNG, fp); // variabile in cui vado a ficcare la stringa, lungezza massima della stringa, file
            k++;
        }
        dim = k;
        fclose(fp);
    }
    return dim;
}

int main() {
    int dim;
    Lista videoteca[dim];
    dim = caricaTabella(videoteca, MAX_LUNG, "file.csv");

    printf("\n");
    system("pause");
    return 0;
}
