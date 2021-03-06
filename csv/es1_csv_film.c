/************************************************************************************************************************************
Simondi Francesca IV A ROB 21 / 10
ES: 01
La videoteca "Ciak film" necessita di un programma che carichi la lista film in un array di struttura e che stampi a video i 5 campi : 
numero, titolo film, genere, anno di uscita, disponibilit√† film
************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 30


typedef struct {

    char num[LUNG];
    char titolo[LUNG];
    char tipologia[LUNG];
    char anno[LUNG];
    char disp[LUNG];

} Film;

void leggi(Film film[], int n, char nomefilm[]) {
    FILE *fp;
    int conta = 0;
    char line[100];

    fp = fopen(nomefilm, "r"); // apro il file
    for(int k = 0; k < n; k++) { // per ogni riga
        fgets(line, 100, fp); // prende le righe
        char* pezzo = strtok(line, ","); // carattere per separare i campi

        while(pezzo != NULL) { // finch√© non finisce la riga
            switch(conta) {
            case 0:
                strcpy((*(film + k)).num, pezzo);
                break;
            case 1:
                strcpy((*(film + k)).titolo, pezzo);
                break;
            case 2:
                strcpy((*(film + k)).tipologia, pezzo);
                break;
            case 3:
                strcpy((*(film + k)).anno, pezzo);
                break;
            case 4:
                strcpy((*(film + k)).disp, pezzo);
                break;
            }
            conta++;
            pezzo = strtok(NULL, ",");
        }
        conta=0;
    }
}

void stampa(Film v[],int n) {
    printf("\t%Numero \tTitolo  \tTipologia  \tAnno  \tDisponibilita' \n");
    for(int k=0; k<n; k++) {
        printf("\t%s \t%s  \t%s  \t%s  \t%s \n",(*(v + k)).num, (*(v + k)).titolo, (*(v + k)).tipologia, (*(v + k)).anno, (*(v + k)).disp);
    }
}

int main() {
    Film catalogo[LUNG];
    leggi(catalogo,LUNG,"listafilm.csv");
    stampa(catalogo,LUNG);

    printf("\n");
    system("pause");
    return 0;
}
