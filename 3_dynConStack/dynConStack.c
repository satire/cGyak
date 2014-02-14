// DINAMIKUS FOLYAMATOS VEREM TÖMBBEL
// jegyzetek + https://www.cs.bu.edu/teaching/c/stack/array/

// A veremmel megvalósítandó műveletek (ADT leírás):

// allocStack: − → V (Üres verem létrehozása.)
// deallocStack: V → − (A verem által lefoglalt memória felszabadítása.)

// isEmpty: V → L (Állapot lekérdezése: üres-e.)
// isFull: V → L (Állapot lekérdezése: tele van-e.)

// push: V × E → V (Új elem beszúrása.)
// pop: V → V × E (Legfelső elem kivétele a veremből.)

// top: V → E (Legfelső elem lekérdezése.)

#include <stdio.h>          // Standard gcc könyvtár a felhasználói I/O kezelésére (printf(), scanf()).
#include <stdlib.h>         // Könyvtár a memória kezelő fügvények hívásához (malloc(), calloc(). free()...).

#include "dynConStack.h"    // A header file betöltése.

// Veremkezelő függvények implementálása:
void allocStack(dynConSTACK *s, int stackSize)
{
    int *elementsArray; //Üres, int típusú pointer,

    // A verem elemeit tartalmazó tömböt futásidőben kell létrehozni a memóriában!!
    elementsArray = (int *)malloc(sizeof(int) * stackSize);  // Az elementsArray pointerhez hozzárendel egy memória területet, a kívánt stackSize szerint.

    if (elementsArray == NULL)
    {
        printf ("Nincs elég memória a verem létrehozásához!\n");
        exit(1);  // kilépés hibával!
    }

    s->stackArray = elementsArray;  // A verem elemeit tartalmazó pointert beállíta, hogy a létrehozott memória területre mutasson.
    s->stackSize = stackSize;       // A verem méretét tartalmazó változóba berakja a megadott maximális veremméretet.
    s->topElement = -1;             // A verem jelenleg üres, azaz a legfelső elem indexét -1 -re állítja.

}

bool isEmpty(dynConSTACK *s)
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

bool isFull(dynConSTACK *s)
{
    // A tömb típus működéséből adódik, hogy az utolsó elem indexe a tömb elemszáma - 1.
    if(s->topElement == (s->stackSize)-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push (dynConSTACK *s, int data)
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
int pop (dynConSTACK *s)
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

void top (dynConSTACK *s)
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

// Felszabadítja a veremnek lefoglalt területet és kinullázza a veret.
// A fögvény meghívása után a verem elérhetetlenné válik, minden benne tárolt adat megsemmisül!!
void deallocStack(dynConSTACK *s)
{
    free(s->stackArray);
    s->stackArray = NULL;
    s->stackSize = 0;
    s->topElement = -1;
}



