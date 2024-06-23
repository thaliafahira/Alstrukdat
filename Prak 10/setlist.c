#include "setlist.h"
#include <stdlib.h>

address Alokasi(infotype Elmt) {
    address P = (address)malloc(sizeof(ElmtSet));
    if (P != NULL) {
        Info(P) = Elmt;
        Next(P) = NULL;
    }
    return P;
}

void Dealokasi(address *P) {
    free(*P);
}

void CreateEmpty(Set *S) {
    First(*S) = NULL;
}

boolean IsEmpty(Set S) {
    return First(S) == NULL;
}

void Insert(Set *S, infotype Elmt) {
    if (!IsMember(*S, Elmt)) {
        address P = Alokasi(Elmt);
        if (P != NULL) {
            address Last = First(*S);
            if (Last != NULL) {
                while (Next(Last) != NULL) {
                    Last = Next(Last);
                }
                Next(Last) = P;
            } else {
                First(*S) = P;
            }
        }
    }
}

void Delete(Set *S, infotype Elmt) {
    address Prec = Nil;
    address P = First(*S);
    while (P != NULL && Info(P) != Elmt) {
        Prec = P;
        P = Next(P);
    }
    if (P != NULL) {
        if (Prec != NULL) {
            Next(Prec) = Next(P);
        } else {
            First(*S) = Next(P);
        }
        Dealokasi(&P);
    }
}

boolean IsMember(Set S, infotype Elmt) {
    address P = First(S);
    while (P != NULL && Info(P) != Elmt) {
        P = Next(P);
    }
    return P != NULL;
}

int Count(Set S) {
    int count = 0;
    address P = First(S);
    while (P != NULL) {
        count++;
        P = Next(P);
    }
    return count;
}