#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* ** Prototype ** */
boolean IsEmpty (List L){
    return (First(L) == Nil);
}
void CreateEmpty (List *L){
    First(*L) = Nil;
}
address Alokasi (infotype X){
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else
        return Nil;
}
void Dealokasi (address *P){
    free(*P);
}
address Search (List L, infotype X){
    address P = First(L);
    boolean found = false;
    while((P != Nil) && (!found)){
        if(Info(P) == X){
            found = true;
        }
        else{
            P = Next(P);
        }
    }
    if(found){
        return P;
    }
    else{
        return Nil;
    }
}
void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if(P != Nil){
        Next(P) = First(*L);
        First(*L) = P;
    }
}
void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if(P != Nil){
        if(IsEmpty(*L)){
            First(*L) = P;
        }
        else{
            address Last = First(*L);
            while(Next(Last) != Nil){
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}
void DelVFirst (List *L, infotype *X){
    if(!IsEmpty(*L)){
        address P = First(*L);
        *X = Info(P);
        First(*L) = Next(P);
        Next(P) = Nil;
        Dealokasi(&P);
    }
}
void DelVLast (List *L, infotype *X){
    if(!IsEmpty(*L)){
        address P = First(*L);
        if(Next(P) == Nil){
            *X = Info(P);
            First(*L) = Nil;
            Dealokasi(&P);
        }
        else{
            address Last = First(*L);
            while(Next(Next(Last)) != Nil){
                Last = Next(Last);
            }
            P = Next(Last);
            *X = Info(P);
            Next(Last) = Nil;
            Dealokasi(&P);
        }
    }
}
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast(List *L, address P){
    if(IsEmpty(*L)){
        First(*L) = P;
    }
    else{
        address Last = First(*L);
        while(Next(Last) != Nil){
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}
void DelFirst(List *L, address *P){
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}
void DelP(List *L, infotype X){
    if(!IsEmpty(*L)){
        address Prec = Nil;
        address P = First(*L);
        boolean found = false;
        while((Next(P) != Nil) && (!found)){
            if(Info(Next(P)) == X){
                found = true;
                Prec = P;
            }
            else{
                P = Next(P);
            }
        }
        if(found){
            DelAfter(L, &P, Prec);
        }
        else if(Info(First(*L)) == X){
            DelFirst(L, &P);
        }
    }
}
void DelLast(List *L, address *P){
    if(!IsEmpty(*L)){
        if(Next(First(*L)) == Nil){
            *P = First(*L);
            First(*L) = Nil;
        }
        else{
            address Last = First(*L);
            while(Next(Next(Last)) != Nil){
                Last = Next(Last);
            }
            *P = Next(Last);
            Next(Last) = Nil;
        }
    }
}
void DelAfter(List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}
void PrintInfo(List L){
    address P = First(L);
    printf("[");
    while(P != Nil){
        printf("%d", Info(P));
        if(Next(P) != Nil){
            printf(",");
        }
        P = Next(P);
    }
    printf("]\n");
}
int NbElmt(List L){
    int count = 0;
    address P = First(L);
    while(P != Nil){
        count++;
        P = Next(P);
    }
    return count;
}
infotype Max(List L){
    infotype max = Info(First(L));
    address P = First(L);
    while(P != Nil){
        if(Info(P) > max){
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}
address AdrMax(List L){
    infotype max = Info(First(L));
    address maxP = First(L);
    address P = First(L);
    while(P != Nil){
        if(Info(P) > max){
            max = Info(P);
            maxP = P;
        }
        P = Next(P);
    }
    return maxP;
}
infotype Min (List L){
    infotype min = Info(First(L));
    address P = First(L);
    while(P != Nil){
        if(Info(P) < min){
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}
address AdrMin(List L){
    infotype min = Info(First(L));
    address minP = First(L);
    address P = First(L);
    while(P != Nil){
        if(Info(P) < min){
            min = Info(P);
            minP = P;
        }
        P = Next(P);
    }
    return minP;
}
float Average(List L){
    int sum = 0;
    int count = 0;
    address P = First(L);
    while(P != Nil){
        sum += Info(P);
        count++;
        P = Next(P);
    }
    return (float)sum/count;
}
void InversList(List *L){
    if(!IsEmpty(*L)){
        address Prec = Nil;
        address P = First(*L);
        address temp;
        while(P != Nil){
            temp = Next(P);
            Next(P) = Prec;
            Prec = P;
            P = temp;
        }
        First(*L) = Prec;
    }
}
void Konkat1(List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    if(IsEmpty(*L1)){
        First(*L3) = First(*L2);
    }
    else{
        address P = First(*L1);
        while(Next(P) != Nil){
            P = Next(P);
        }
        First(*L3) = First(*L1);
        Next(P) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}