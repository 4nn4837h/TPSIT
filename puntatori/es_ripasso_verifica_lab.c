#include <stdio.h>
#include <stdlib.h>
/************************************************************************************************************************************
Simondi Francesca IV A ROB - 12 / 11
ES: 1
Scrivere un programma per leggere e stampare un array bidimensionale di interi, una matrice.
Il programma richiede all�utente il numero di righe e di colonne dopo di che richiede ad uno
ad uno gli elementi da inserire nell'array.
Il programma inoltre deve gestire dinamicamente l'allocazione e la deallocazione della memoria.
************************************************************************************************************************************/

int main()
{
     int nr, nc, r, c;
     printf("inserisci il numero di righe: ");
     scanf("%d", &nr);
     printf("inserisci il numero di colonne: ");
     scanf("%d", &nc);
     int **m = (int **) malloc(nr * sizeof(int*)); // creo la prima cella ti tutte le righe
     for(int i = 0; i < nr; i++){
          *(m + i) = (int*) malloc(nc * sizeof(int)); // creo tutte le celle per ogni riga
     }

     // richiesta dei numeri in input
     for(r = 0; r < nr; r++){
          for(c = 0; c < nc; c++){
               printf("Nella cella [%d][%d], inserisci un numero: ", r, c);
               scanf("%d", ((m + r) + c));
          }
     }

     // tabella in output:
     for(int r = 0; r < nr; r++){
          for(int c = 0; c < nc; c++){
               printf("Cella [%d][%d]: ", r, c);
          }
     }

     printf("int: %d, *int: %d", sizeof(int), sizeof(int*));

     //disallocazione dinamica:
     free(m);

    printf("\n");
    system("pause");
    return 0;
}
