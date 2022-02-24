#include <stdio.h>
#include <stdlib.h>
#define MAX_AL 25 // massimo di alunni
/************************************************************************************************************************************
Simondi Francesca IV A ROB - 5 / 11
ES: 02
Definire una struttra per memorizzarte i dati degli studenti di una classe e dei voti nelle varie discipline:
 italiano, mate, info.
Si scriva una funzione un C che, a partire da un vettore du studenti fornito come argomento,
 determinila disciplina che ha la media pi� alta tra le tre.
************************************************************************************************************************************/

typedef struct {
    int ita;
    int mate;
    int info;
} Studente;

int prendiStudenti(Studente *c, int max) {
    int nAlunni = 0, i;
    printf("Quanti alunni ci sono in classe? ");
    scanf("%d", &nAlunni);
    for ( i = 0; i < nAlunni; i++) {
        printf("Alunn* numero %d:\nVoto di italiano: ", i + 1);
        scanf("%d", ((c + i)->ita));
        printf("Voto di matematica: ");
        scanf("%d", &c[i].mate);
        printf("Voto di informatica:");
        scanf("%d", &c[i].info);
        printf("\n");
    }
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
