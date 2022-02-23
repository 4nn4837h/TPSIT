/*
Per descrivere i pazienti di una clinica disponi del seguente tipo di dato:
Paziente 
Scrivi i Prototipi,le chiamate e il codice delle seguenti specifiche:
1. definisci una variabile rossi di tipo paziente;
2. definisci un array di 20 pazienti di nome clinica e di tipo paziente;
3. imposta una procedura (prototipo) con il corretto passaggio dei parametri che permetta ad
un utente di inserire tutti dati di un paziente che è stato passato alla procedura;
4. imposta una procedura (prototipo) che stampa la pressione e la temperatura di un
paziente;
5. imposta una procedura (prototipo) che dato l&#39;indirizzo dell&#39;array clinica ed il numero di
pazienti che vi sono sulla lista, calcola il saldo totale della clinica;
6. imposta tutte le chiamate nel main che realizzino in sequenza i punti precedenti;
7. facoltativo: ora completa l'esercizio scrivendo il codice di tutte le procedure.
*/
#include <stdio.h>
#include <stdlib.h>
#define N_PAZIENTI_MAX 20
int top = -1;

typedef struct
{
char nome[256];
char cognome[256];
int matricola;
int pressione[2]; // minima e massima
int temperature[3]; // temperature della mattina e pomeriggio e sera
float parcella; // in euro quello che deve al dottore
} Paziente; // Iniziale maiuscola

// Controllo se stack vuoto
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

// Controllo se stack pieno   
int isfull() {

   if(top == N_PAZIENTI_MAX)
      return 1;
   else
      return 0;
}

// Prelievo utimo elemento inserito
char peek(){
   return stack[top];
}

void inserisciPaziente(Paziente *p){ // 3
    printf("Inserisci il nome:\t");
    fflush(stdin);
    scanf("%s", p->nome);
    printf("Inserisci il cognome:\t");
    fflush(stdin);
    scanf("%s", p->cognome);
}

void stampaPaziente(Paziente p){ // 4
    printf("Inserisci il nome:\t%s", p.nome);
    printf("Inserisci il cognome:\t", p.cognome);
}

double saldoClinica(Paziente p[], int nPazienti){ // 5
    duoble somma = 0;
    // for per leggereil numero di paziente e somma delle parcelle
    for(int i = 0; i < N_PAZIENTI_MAX; i++){
        somma += p[i].parcella;
    }
}

int main(){
    Paziente rossi; // 1: variabile di tipo paziente
    Paziente clinica[N_PAZIENTI_MAX]; // 2: array di tipo paziente: clinica

    // 6: chiamate delle funzioni e delle procedure
    inserisciPaziente(&rossi);
    stampaPaziente(rossi);

    int i;
    for ( i = 0; i < N_PAZIENTI_MAX; i++) inserisciPaziente(&clinica[i]);
    for (int i = 0; i < N_PAZIENTI_MAX; i++) stampaPaziente(clinica[i]);

    printf("Il saldo della clinica con %d e' di: € %g ", N_PAZIENTI_MAX, saldoClinica(clinica, N_PAZIENTI_MAX));
    fflush(stdin);
    getchar();
    return 0;
}