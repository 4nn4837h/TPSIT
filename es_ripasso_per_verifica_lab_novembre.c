#include <stdio.h>
#include <stdlib.h>
/**
Esercizio 1
Scrivere un programma per leggere e stampare un array bidimensionale di interi, una matrice.
Il programma richiede all’utente il numero di righe e di colonne dopo di che richiede ad uno
ad uno gli elementi da inserire nell'array.
Il programma inoltre deve gestire dinamicamente l'allocazione e la deallocazione della memoria.
*/
int main()
{
     int nr, nc;
     printf("inserisci il numero di righe: ");
     scanf("%d", &nr);
     printf("inserisci il numero di colonne: ");
     scanf("%d", &nc);
     int **mat = (int **) malloc(nr * sizeof(int)); // creo la prima cella ti tutte le righe
     for(int i = 0; i < nr; i++){
          *mat[i] = (int*) malloc(nc * sizeof(int)); // creo tutte le celle per ogni riga
     }

     // richiesta dei numeri in input
     for(int r = 0; r < nr; r++){
          for(int c = 0; c < nc; c++){
               printf("Nella cella [%d][%d], inserisci un numero: ", r, c);
               scanf("%d" &*(*(mat + r)+c));
          }
     }

     //disallocazione dinamica:
     free(mat);

    printf("\n");
    system("pause");
    return 0;
}
