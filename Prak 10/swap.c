#include <stdlib.h>
#include "swap.h"

address AddressAtIndex(List L, infotype x)
/* 
Mencari address suatu node pada element ke- X
*/
{
    int idx = 1;
    address P = First(L);
    while((idx < x) && (P != Nil)){
        idx++;
        P = Next(P);
    } /* idx == x, P adalah address dari node element ke-x */
    return P;
}

void Swap(List *L1) {
    int angka_pertama, angka_kedua;
    scanf("%d %d", &angka_pertama, &angka_kedua);

    if (angka_pertama == angka_kedua) {
        // No need to swap if both numbers are the same
        return;
    }

    address Pawal = AddressAtIndex(*L1, angka_pertama);
    address Pakhir = AddressAtIndex(*L1, angka_kedua);

    if (Pawal == Nil || Pakhir == Nil) {
        // One of the positions is out of the list's bounds
        return;
    }

    if (Next(Pawal) == Pakhir) {
        // Special case if the nodes are adjacent and Pawal is before Pakhir
        address temp = Next(Pakhir);
        if (Prev(Pawal) != Nil) Next(Prev(Pawal)) = Pakhir;
        Prev(Pakhir) = Prev(Pawal);
        Next(Pawal) = temp;
        if (temp != Nil) Prev(temp) = Pawal;
        Prev(Pawal) = Pakhir;
        Next(Pakhir) = Pawal;
    } else if (Next(Pakhir) == Pawal) {
        // Special case if the nodes are adjacent and Pakhir is before Pawal
        address temp = Next(Pawal);
        if (Prev(Pakhir) != Nil) Next(Prev(Pakhir)) = Pawal;
        Prev(Pawal) = Prev(Pakhir);
        Next(Pakhir) = temp;
        if (temp != Nil) Prev(temp) = Pakhir;
        Prev(Pakhir) = Pawal;
        Next(Pawal) = Pakhir;
    } else {
        // General case for non-adjacent nodes
        address tempPrevPawal = Prev(Pawal), tempNextPawal = Next(Pawal);
        address tempPrevPakhir = Prev(Pakhir), tempNextPakhir = Next(Pakhir);

        if (tempPrevPawal != Nil) Next(tempPrevPawal) = Pakhir;
        if (tempNextPawal != Nil) Prev(tempNextPawal) = Pakhir;
        if (tempPrevPakhir != Nil) Next(tempPrevPakhir) = Pawal;
        if (tempNextPakhir != Nil) Prev(tempNextPakhir) = Pawal;

        Next(Pawal) = tempNextPakhir;
        Prev(Pawal) = tempPrevPakhir;
        Next(Pakhir) = tempNextPawal;
        Prev(Pakhir) = tempPrevPawal;
    }

    // Update the First and Last if needed
    if (Pawal == First(*L1)) First(*L1) = Pakhir;
    else if (Pakhir == First(*L1)) First(*L1) = Pawal;

    if (Pawal == Last(*L1)) Last(*L1) = Pakhir;
    else if (Pakhir == Last(*L1)) Last(*L1) = Pawal;
}