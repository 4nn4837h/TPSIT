/**
  Per descrivere i pazienti di una clinica disponi del seguente tipo di dato:
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 7
#define MAXSIZE 50
int stack[50];
int top = -1;

// Controllo se stack vuoto
int isempty()
{

    if(top == -1)
        return 1;
    else
        return 0;
}

// Controllo se stack pieno
int isfull()
{
    if(top == MAXDIM)
        return 1;
    else
        return 0;
}


// Prelievo dati dallo stack
void pop(int data)
{

    if(!isempty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Impossibile prelevare dato, Stack vuoto.\n");
    }
}

// Inserimento dati nello stack
void push(int data)
{

    if(!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Impossibile inserire dati, Stack Pieno.\n");
    }
}


void inserisciDatiVet(int vet[])
{
    int k,elemento;

    for(k=0; k<DIM; k++)
    {
        printf("inserisci l'elemento %d :",k);
        scanf("%d",&elemento);

        vet[k]=elemento;
    }
}

void invertiPila(int vet[])
{
    for(int k=DIM; k>=0; k--){
        push(vet[k]);
    }
}


void stampaPila()
{
    int elemento;
    while(top>0)
    {
        elemento = pop(stack[top]);
        printf(" %d \n",elemento);
    }
}

void main()
{
    int vet[DIM];

    inserisciDatiVet(vet);
    invertiPila(vet);
    stampaPila();

    return 0;
}