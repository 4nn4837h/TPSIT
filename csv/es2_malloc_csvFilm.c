#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100
/************************************************************************************************************************************
Simondi Francesca IV A ROB 21 / 10
ES: 02
La videoteca "Ciak film" necessita di un programma che carichi la lista film in un array di struttura e che stampi a video i 5 campi:
numero, titolo film, genere, anno di uscita, disponibilit� film.
strtok(variabileStringa, simbolo/letteraConCuiSiDistruggeLaStringa); -- passando NULL
fgets(varibilePerS[], lungMaxStringa, nomeFile);
************************************************************************************************************************************/

typedef struct {
    char num[DIM];
    char titFilm[DIM];
    char genere[DIM];
    char annoUscita[DIM];
    char dispo[DIM];
} Cinema; //dichiarazione della struttura di stringhe


int contaRigheFile(char nomeFile[]) {
    FILE *fp;
    int conta = 0;
    char stringa[DIM];

    fp = fopen (nomeFile, "r");
    if(fp == NULL) {
        printf("IL FILE NON ESISTE\n");
    } else {
        while(fgets(stringa, DIM, fp)) {
            conta++;
        }
    }
    fclose(fp);
    return conta;
}

void caricaVett(Cinema v[], int n, char nomeFilm[]) {
    FILE *fp; // puntatore al file che andr� ad utilizzare
    int c = 0;
    char line[100]; // inizializzo il vettore di caratteri a 100, in modo che la stringa ci stia
    char *pezzo; // puntatore a carattere (quindi in sostanza un array) per dividere la variabile line in vari pezzi

    fp = fopen(nomeFilm, "r"); // apro il file in lettura: cursore all'inizio del file

    for(int i = 0; i < n; i++) {
        fgets(line, 100, fp); // prendo l'intera riga in input
        pezzo = strtok(line, ","); // l'indirizzo di pezzo sar� quello di line fino al carattere ',' che separa la linea in pezzi

        while(pezzo != NULL) { // quando pezzo varr� null il ciclo sifermer� perch� arrivato alla fine del file
            switch(c) { //switch case con c (contatore)
            case 0:
                strcpy((*(v+i)).num, pezzo); //copio il pezzo di stringa letto nel campo della struttura adeguato
                break;
            case 1:
                strcpy((*(v+i)).titFilm, pezzo);
                break;
            case 2:
                strcpy((*(v+i)).genere, pezzo);
                break;
            case 3:
                strcpy((*(v+i)).annoUscita, pezzo);
                break;
            case 4:
                strcpy((*(v+i)).dispo, pezzo);
                break;
            }
            c++; // incremento contatore in modo da mettere nel campo corretto il "pezzo" corretto
            pezzo = strtok(NULL, ",");
        }
        c = 0; // ri inizializziamo la c a 0, in modo che la linea ricominci da capo
    }
    fclose(fp); //chiudo il file
}

void caricaVett1(Cinema *v, int n, char nomeFilm[]) {
    FILE *fp; // puntatore al file che andr� ad utilizzare
    int c = 0;
    char line[100]; // inizializzo il vettore di caratteri a 100, in modo che la stringa ci stia
    char *pezzo; // puntatore a carattere (quindi in sostanza un array) per dividere la variabile line in vari pezzi

    fp = fopen(nomeFilm, "r"); // apro il file in lettura: cursore all'inizio del file

    for(int i = 0; i < n; i++) {
        fgets(line, 100, fp); // prendo l'intera riga in input
        pezzo = strtok(line, ","); // l'indirizzo di pezzo sar� quello di line fino al carattere ',' che separa la linea in pezzi

        while(pezzo != NULL) { // quando pezzo varr� null il ciclo sifermer� perch� arrivato alla fine del file
            switch(c) { //switch case con c (contatore)
            case 0:
                strcpy((v+i)->num, pezzo); //copio il pezzo di stringa letto nel campo della struttura adeguato
                break;
            case 1:
                strcpy((v+i)->titFilm, pezzo);
                break;
            case 2:
                strcpy((v+i)->genere, pezzo);
                break;
            case 3:
                strcpy((v+i)->annoUscita, pezzo);
                break;
            case 4:
                strcpy((v+i)->dispo, pezzo);
                break;
            }
            c++; // incremento contatore in modo da mettere nel campo corretto il "pezzo" corretto
            pezzo = strtok(NULL, ",");
        }
        c = 0; // ri inizializziamo la c a 0, in modo che la linea ricominci da capo
    }
    fclose(fp); //chiudo il file
}

void stampVett1(Cinema *v, int n) { // se volesi mettere nel parametro formale v[] allora ==> (*(v+k)).campo
    for(int k = 0; k < n; k++) {
        printf("%s\t%s\t%s\t%s\t%s", (v + k)->num, (v + k)->titFilm, (v + k)->genere, (v + k)->annoUscita, (v + k)->dispo);
    }
}

void stampVett(Cinema v[], int n) { // se volesi mettere nel parametro formale *v ==> (v + k)->campo
    for(int k = 0; k < n; k++) {
        printf("%s\t%s\t%s\t%s\t%s", (*(v + k)).num, (*(v + k)).titFilm, (*(v + k)).genere, (*(v + k)).annoUscita, (*(v + k)).dispo);
    }
}

int main() {

    Cinema *film;
    int conta = contaRigheFile("file.txt");  //conto quante righe ci sono nel file csv

    film = (Cinema*) malloc (conta * sizeof(Cinema)); //allocazione dinamica

    caricaVett1(film, conta, "file.txt"); //carico la struttura prendendo le informazioni dal file csv

    stampVett1(film, conta); //stampo la matrice caricata in precedenza

    free(film);
    return 0;
}
