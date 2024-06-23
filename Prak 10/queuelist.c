/* File : queuelist.c */
#include "queuelist.h"

/* Prototype untuk membantu fungsi Alokasi */
address Alloc(infotype X);

void Alokasi(address *P, infotype X) {
    *P = Alloc(X);
}

address Alloc(infotype X) {
    address P = (address) malloc(sizeof(ElmtQueue));
    P->Info = X;
    P->Next = Nil;
    return P;
}

void Dealokasi(address P) {
    free(P);
}

boolean IsEmpty(Queue Q) {
    return Head(Q) == Nil;
}

int NbElmt(Queue Q) {
    int count = 0;
    address P = Head(Q);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

void CreateEmpty(Queue *Q) {
    (*Q).HEAD = Nil;
    (*Q).TAIL = Nil;
}

void Enqueue(Queue *Q, infotype X) {
    address P = Alloc(X);
    if (IsEmpty(*Q)) {
        Head(*Q) = Tail(*Q) = P;
    } else {
        Next(Tail(*Q)) = P;
        Tail(*Q) = P;
    }
}

void Dequeue(Queue *Q, infotype *X) {
    if (!IsEmpty(*Q)) {
        address P = Head(*Q);
        *X = InfoHead(*Q);
        Head(*Q) = Next(Head(*Q));
        Dealokasi(P);
    }
}