#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DIM 100
/*
es: scrivere un programma che verifichi che la stringa data in input è palindroma o meno.
*/

void stampa(char s[], int *n) {
    printf("Inserisci la stringa: ");
    fflush(stdin);
    scanf("%s", s); // dovrebbe stare su un'unica riga
    *n = strlen(s); // prende anche il tappo
}

bool isPalindromo(char s[], int n) {
    bool ok = true;
    int k = 0;

    while( k < n - 1 && ok) {
        if((*(s + k)) != (*(s + (n - 1 - k)))) {
            ok = false;
        }
        k++;
    }
    return ok;
}

int main() {
    int dim = DIM;
    char stringa[dim]; // ETNAGIGANTE, ANNA

    stampa(stringa, &dim);
    if(isPalindromo(stringa, dim)) {
        printf("\nla stringa e' palindroma.");
    } else {
        printf("\nLa stringa NON e' palindroma.");
    }

    printf("\n");
    system("pause");
    return 0;
}
