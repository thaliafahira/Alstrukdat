#include "remove.h"

void RemoveDuplicates(List *L){
    if(IsEmpty(*L)){
        printf("List kosong\n");
    }else{
        address P = First(*L);
        while(P != Nil){
            address Q = Next(P);
            address Prec = P;
            while(Q != Nil){
                if(Info(P) == Info(Q)){
                    DelAfter(L, &Q, Prec);
                }else{
                    Prec = Q;
                    Q = Next(Q);
                }
            }
            P = Next(P);
        }
    }
}