// STATIKUS FOLYAMATOS VEREM TÖMBBEL
// jegyzetek + https://www.cs.bu.edu/teaching/c/queue/array/

// Egy tömb önmagában is viselkedhet veremként, az adatszerkezet megkötéseket tesz a tömb elemeinek bejárására,
// módosítására és biztosítja a LIFO viselkedést.

// A veremmel megvalósítandó műveletek (ADT leírás):

// isEmpty: V → L (Állapot lekérdezése: üres-e.)
// isFull: V → L (Állapot lekérdezése: tele van-e.)

// push: V × E → V (Új elem beszúrása.)
// pop: V → V × E (Legfelső elem kivétele a veremből.)

// top: V → E (Legfelső elem lekérdezése.)

#include <stdio.h>          // Standard gcc könyvtár a felhasználói I/O kezelésére (printf(), scanf())..

#include "statConStack.h"    // A header file betöltése.

// Veremkezelő függvények implementálása:
bool isEmpty(statConSTACK *s)
{
    // A 0. elem kivétele után a legfelső elemre hivatkozó (topElement) változónak -1-nek kell lennie.
    // (inicializáláskor, vagy a pop()-ban lévő (s->topElement)--; logikai törlés miatt)
    if(s->topElement == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(statConSTACK *s)
{
    if(s->topElement == STACK_SIZE-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push (statConSTACK *s, int data)
{
    if (!isFull(s))
    {
        (s->topElement)++;
        s->stackArray[s->topElement] = data;
        printf ("Elem hozzáadva: %i\n", s->stackArray[s->topElement]);
    }
    else
    {
        printf ("A verem megtelt!\n");
    }
}

// Lekérdezi a verem legfelső elemét (s->stackArray[s->topElement]),
// kitörli a veremből, majd a lekért értéket átadja az őt meghívó függvénynek.
int pop (statConSTACK *s)
{
    int data;
    if (!isEmpty(s))
    {
        data = s->stackArray[s->topElement];
        (s->topElement)--;  // Logikai törlés
    }
    else
    {
        printf ("A verem üres!\n");
        return (s->topElement);
    }
    return(data);
}

void top (statConSTACK *s)
{
    if (!isEmpty(s))
    {
        printf ("legfelső elem: %i\n", s->stackArray[s->topElement]);
    }
    else
    {
        printf ("A verem üres!\n");
    }
}
