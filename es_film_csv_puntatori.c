#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 35
#define MAX_LUNG 30

/************************************************************************************************************************************
Simondi Francesca IV A ROB
ES: 03
La videoteca "Ciak film" necessita di un programma che carichi la lista film in un array di struttura e che stampi a video i 5 campi:
numero, titolo film, genere, anno di uscita, disponibilità film.

strtok(variabileStringa, simbolo/letteraConCuiSiDistruggeLaStringa); -- passando NULL
fgets(varibilePerS[], lungMaxStringa, nomeFile);
************************************************************************************************************************************/

typedef struct {
    char numero[LUNG];
    char titolo[LUNG];
    char genere[LUNG];
    char anno[LUNG];
    char disponibile[LUNG];
} Lista;

void caricaTabella(Lista film[MAX_LUNG], int nMax, char nomeFile[]) {
    FILE *fp; // creo il file
    char *line[100];
    fp = fopen(nomeFile, "r");

    if(fp == NULL) {
        printf("Il file %s non esiste", nomeFile);
    } else {
        int c = 0; // inizializzo la variabile per staccare i pezzi
        for( int k = 0; k < nMax; k++) {
            fgets(line, 150, fp); // prende tutta la linea comprendendo gli spazi: prende tutta la linea
            printf("ciao"); // da qui in poi non funziona più
            char* parola = strtok(line, ','); // la stringa parola prende ogni parola divisa dalla virgola

            while(parola != NULL) { // finché parola non vale NULL lo faccio
                switch(c) { // aumentando c, si cambia posto di destinazione partendo poi da parola
                case 0:
                    strcpy((*(film + k)).numero, parola); // DESTINAZIONE, STRINGA DI PARTENZA
                    break;
                case 1:
                    strcpy((*(film + k))).titolo, parola);
                    break;
                case 2:
                    strcpy((*(film + k)).genere, parola);
                    break;
                case 3:
                    strcpy((*(film + k)).anno, parola);
                    break;
                case 4:
                    strcpy((*(film + k)).disponibile, parola);
                    break;
                }
                c++;
            }
            c = 0; // così mette c a zero, quindi la parola andrà messa nel numero
            //*parola = strtok(NULL, '.');
        }
        fclose(fp);
    }
}

void showTabella(Lista v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("%3s | %30s | %15s | %4s | %16s", (*(v + k)).numero, (*(v + k)).titolo, (*(v + k)).genere, (*(v + k)).anno, (*(v + k)).disponibile);
    }
}

int main() {
    Lista videoteca[MAX_LUNG];
    caricaTabella(videoteca, MAX_LUNG, "file.csv");
    showTabella(videoteca, MAX_LUNG);

    printf("\n");
    system("pause");
    return 0;
}
