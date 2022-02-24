#include <stdio.h>
#include <stdlib.h>
#define MAX_LUNG 30      // manutenibilit� del codice
#define NUM 10
/************************************************************************************************************************************
Simondi Francesca IV A ROB - 14 / 9
ES: 01
si scriva un programma in che:
- definiscaun tipo di dato Studente. Ogni studente � caratterizzato da un nome, un cognome e una matricola.
- acquisisca i dati di 10 studenti e, per ogni nuovo studente inserito, proceda ad un inserimento ordinato
 (lo scopo dell'esercizio è ordinare gli sudenti durante il pricesso di inserimento degli stessi e
  non dopo averli inseriti tutti con un algoritmo di ordinamento).
- stampi i dati degli studenti.
************************************************************************************************************************************/

typedef char stringa[MAX_LUNG];

typedef struct { // struttura campi 3 campi
    stringa nome;
    stringa cognome;
    int matricola;
} Studente;

//void inserimentoDati(Studente c[]) {
void stampa(Studente c[]){
     for(int i = 0; i < NUM; i++) {
        printf("\nNome: %s", c[i].nome);
        printf("\nCognome: %s ", c[i].cognome);
        printf("\nMatricola: %d", c[i].matricola);
     }
}
int main() {
    Studente classe[NUM]; // tabella di 10 righe con tipo di dato Studente
    Studente tmp;
    int i, j;

    // acquisizione dei dati degli studenti -> standart input = tastiera
    //inserimentoDati(classe);
    for(int i = 0; i < NUM; i++) {
        printf("Inserisci le informazioni di uno studente\nNome: ");
        fflush(stdin);
        scanf("%s", tmp.nome);
        printf("Cognome: ");
        fflush(stdin);
        scanf("%s", tmp.cognome);
        printf("Matricola: ");
        fflush(stdin);
        scanf("%d", &tmp.matricola);

        // cerco la posizione di inserimento
        while( i < NUM && classe[i].matricola < tmp.matricola) {
            i += 1;
            //creo lo spazio per inserire l'elemento
            j = NUM;
            while(j < i) {
                tmp = classe[i];
                classe[i] = classe[j - 1];
                tmp = classe[i];
            }
        }
    }

    stampa(classe);

    system("pause");
    return 0;
}
