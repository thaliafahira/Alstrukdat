#include "listlinier.h"
#include "remove.h"

void RemoveDuplicates(List *L)
{
    List New; CreateEmpty(&New);
    while (!IsEmpty(*L))
    {
        infotype insert; DelVFirst(L, &insert);
        InsVLast(&New, insert);

        int before = 1;
        int after  = 2;
        while (before != after)
        {
            before = NbElmt(*L);
            DelP(L, insert);
            after  = NbElmt(*L);
        }
    }
    (*L) = New;
}
