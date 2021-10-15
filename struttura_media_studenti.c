#include <stdio.h>
#include <stdlib.h>
#define MAX_AL 25
/*
es_02:
Definire una struttra per memorizzarte i dati degli studenti di una classe e dei voti nelle varie discipline:
 italiano, mate, info.
Si scriva una funzione un C che, a partire da un vettore du studenti fornito come argomento,
 determinila disciplina che ha la media più alta tra le tre.
*/
typedef struct {
    int ita;
    int mate;
    int info;
} Studente;

int prendiStudenti(Studente c[], int max) {
    int i = 0;
    printf("Quando non ci sono più alunni clickare il numero 0 alla prima domanda riguardante il/la nuov* alunn*");
    do {
        printf("Inserisci il voto di italiano dell* alunn* numero %d: ", i);
        scanf("%d", c[i].ita);
        printf("Inserisci il voto di matematica: ");
        scanf("%d", c[i].mate);
        printf("Inserisci il voto di informatica:");
        scanf("%d", c[i].info);
        i += 1;
    } while( c[i].ita != 0 || i > max);
    return i;
}

int mediaMigliore(Studente c[], int stud) {
    int mat = -1;
    int sInfo = 0, sMate = 0, sIta = 0;
    float mInfo, mMate, mIta;
    if( stud != 0) {
        for(int i = 0; i < stud; i++) {
            sInfo = sInfo + c[i].info;
            sMate = sMate + c[i].mate;
            sIta = sIta + c[i].ita;
        }
        mInfo = sInfo / stud;
        mMate = sMate / stud;
        mIta = sIta / stud;
    }
    if(mInfo > mMate && mMate > mIta) {
        mat = 2;
    } else if(mIta > mMate && mMate > mInfo) {
        mat = 0;
    } else {
        mat = 1;
    }
    return mat;
}

int main() {
    Studente classe[MAX_AL];
    int x, n;
    n = prendiStudenti(classe, MAX_AL);
    x = mediaMigliore(classe, n);
    switch (x) {
    case -1:
        printf("\nVi e' stato un errore nel compilare il programma: forse non ci sono alunni nella classe: la classe non esiste.\n");
    case 0:
        printf("\nItaliano e' la materia con la media maggiore!\n");
        break;
    case 1:
        printf("\nMatematica e' la materia con la media maggiore!\n");
        break;
    case 2:
        printf("\nInformatica e' la materia con la media maggiore\n");
        break;
    }
    printf("\n");
    system("pause");
    return 0;
}
