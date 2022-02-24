#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 20
//#define DIM 10
/************************************************************************************************************************************
Simondi Francesca IV A ROB 22 / 10
Scrivere un programma che data una stringa in input dica se la stessa contiene almeno
una ‘A’ tra i primi 10 caratteri.
************************************************************************************************************************************/

bool cercaA(char s[]) {
    bool ok = false;
    int n;
    if(strlen(s) < 10){
    n = strlen(s);
    }

    for(int k = 0; k < n; k++) { // controlla solo i primi 10 caratteri: fino al 9: da 0 a 9
        if(*(s + k) == 'a' || *(s + k) == 'A') {
            ok = true;
        }
    }
    return ok;
}

int main() {
    char s[LUNG];
    printf("Inserire la parola: ");
    fflush(stdin);
    gets(s);

    if(cercaA(s)) {
        printf("\nEntro i primi dieci caratteri della stringa vi e' una 'a' o una 'A'!\n\n");
    } else {
        printf("\nEntro i primi dieci caratteri della stringa NON vi e' una 'a' o una 'A'!\n\n");
    }

    system("pause");
    return 0;
}