/**
2) Crea un programma che:
a) immetta il numero dei nodi inserendo da tastiera i valori per ogni nodo
b) stampi la lista dei valori inseriti
c) inserisca un nuovo nodo all'inizio della lista
*/
#include <stdio.h>
#include <stdlib.h>

struct elem {/**STRUCT**/
    int *numero; // valore della cella della lista
    struct elem *next; // puntatore alla cella successiva
};

struct elem **list2vet(struct elem *p) { /**FUNZIONE*/
     int i, n = 0;
     struct elem *app, **v; // strut elem *app --- struct elem **v
     app = p; // indirizzo di app = indirizzo p
     while (app != NULL){
          ++n; // conta i record della lista
          app = app->next;
     }
     if (n != 0){
     v = (struct elem **) malloc(n*sizeof(struct elem*));
     for (i = 0; i < n; ++i){
          v[i] = p;
          p = p->next;
     }
     return v;
     }else{
          return NULL;  /* lista vuota */
     }
}

struct elem *creaLista(int k){  /**FUNZIONE*/
     int i;                      // crea una lista di k record
     struct elem *l, *app;
     int n;
     if (k == 0){
          return NULL;
     } else {
          app=l=(struct elem *) malloc(sizeof(struct elem)); // record generatore
     }

     for(i = 0;i < k;++i) {
          l->next = (struct elem *)malloc(sizeof(struct elem));
          l = l->next;
          printf("Inserire un elemento : ");
          scanf("%d",n);
          l->numero = (int *) malloc(sizeof(int));
          strcpy(l->numero, n);
     }
     l->next = NULL;
     l = app->next;
     free(app);
     return l;
}

main () { /**MAIN*/
     struct elem *p1, **v;
     int i;
     p1 = creaLista(3); /*crea una lista di 3 int */
     v = list2vet(p1);
     for(i = 0; i < 3; ++i){
          printf("Nell' elemento %d di v c'e': %d\n",i,v[i]->numero);
     }
}
