#include <stdio.h>
#include "mesinkata.h"

char currentChar;

boolean EndWord;
Word currentWord;

char GetCC()
{
    return currentChar;
}

boolean IsEOP()
{
    return currentChar == MARK;
}

void IgnoreBlanks()
{
    while (GetCC() == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (GetCC() == MARK) EndWord = true;
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    IgnoreBlanks();
    if (GetCC() == MARK) EndWord = true;
    else CopyWord();
    IgnoreBlanks();
}

void CopyWord()
{
    int i = 0;
    while ((GetCC() != MARK) && (GetCC() != BLANK))
    {
        currentWord.TabWord[i] = GetCC();
        ADV();
        i++;
    }
    if (i < NMax) currentWord.Length = i;
    else currentWord.Length = NMax;
}