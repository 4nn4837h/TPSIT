#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 150
/************************************************************************************************************************************
Simondi Francesca IV A ROB - 5 / 11
Si scriva un programma in XC che chieda all'utente 2 stringhe e concateni la seconda alla fine della prima,
NON si usi la funzione strcat della libreria stdio.h, si usini�o i puntatiri e non la notazione vettoriale, attenzione al tappo '\0'
***********************************************************************************************************************************/

void prendiCaratteri(char * s,  char fr[]) {
    printf("%s", fr);
    fflush(stdin);
    gets(s);
}

void stampaStringa(char *s) {
    fflush(stdin);
    puts(s); // ogni prima lettera delle due stringhe stampa un carattere diverso, lo stesso: una 'l ad angolo' e la '�'
}

void attacca(char *s1, char *s2, int n1, int n2) {
    //for(int k = 0; k < n1 - 1; k++)  // dimensione - 1 perch� c'� il tappo
    int s = n1 + n2;
    *s1 = (char *)malloc(s * sizeof(char));
    int part = s - n2; // alla lunghezza totale della stringa tolgo la dimensione della seconda stringa cos� da trovare il suo punto di partenza per attaccarla
    strcpy((s1 + part), s2);
}
int main() {
    char s1[LUNG], s2[LUNG];

    prendiCaratteri(s1, "Inserisci la I frase: "); // prendono le parole della prima stringa
    int l1 = strlen(s1);// prendono la lunghezza delle stringhe
    *s1 = (char *)malloc(l1 * sizeof(char));

    prendiCaratteri(s2, "Inserisci la II frase: "); // seconda stringa
    int l2 = strlen(s2);
    *s2 = (char *)malloc(l2 * sizeof(char));

    attacca(s1, s2, l1, l2);// attacca la seconda stringa alla prima
    stampaStringa(s1);

    printf("\n");
    system("pause");
    return 0;
}
