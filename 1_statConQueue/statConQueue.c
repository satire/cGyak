// STATIKUS FOLYAMATOS SOR TÖMBBEL
// jegyzetek + https://www.cs.bu.edu/teaching/c/queue/

// Egy tömb önmagában is viselkedhet sorként, a sor adatszerkezet megkötéseket tesz a tömb elemeinek bejárására,
// módosítására és biztosítja a FIFO viselkedést.

// A sorral megvalósítandó műveletek (ADT leírás):

//isEmpty: S → L (üres-e a sor?)
//isFull: S → L (megtelt-e a sor?)

//push: S × E → S (elem betétele a sor végére)
//pop: S → S × E (elem kivétele a sor elejéről)

//first: S → E (első elem lekérdezése)

#include <stdio.h>          // Standard gcc könyvtár a felhasználói I/O kezelésére (printf(), scanf())..

#include "statConQueue.h"    // A header file betöltése.

// A sor függvényeinek implementálása:
bool isEmpty(statConQUEUE *q)
{
    if(q->tail <= 0)
    {
        return true;    // A sor üres.
    }
    else
    {
        return false;   // A sor nem üres.
    }
}

bool isFull(statConQUEUE *q)
{
    if(q->tail >= QUEUE_SIZE)
    {
        return true;    // A sor tele van.
    }
    else
    {
        return false;   // A sor nincs tele van.
    }
}

void push(statConQUEUE *q, int data)
{
    int newElementIndex;

    if (!isFull(q))
    {
        newElementIndex = (q->head + q->tail)%QUEUE_SIZE;
        q->queueArray[newElementIndex] = data;
        q->tail++;
        printf ("Elem hozzáadva: %i\n",  q->queueArray[newElementIndex]);
    }else{
        printf ("A sor megtelt!\n");
    }
}

int pop(statConQUEUE *q)
{
    int oldElement;

    if (!isEmpty(q))
    {

        /* Save the element so we can return it. */
        oldElement = q->queueArray[q->head];

        /*
         * Advance the index of the front,
         * making sure it wraps around the
         * array properly.
         */
        q->head++;
        q->head %= QUEUE_SIZE;

        q->tail--;


    }else{
        printf ("A sor üres!\n");
        return -1;
    }



    return oldElement;
}

