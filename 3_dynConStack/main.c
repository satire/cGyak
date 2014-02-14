#include <stdio.h>
#include <stdlib.h>

#include "dynConStack.h"

int main ()
{
    int veremMeret;
    scanf("%d", &veremMeret);
    int szam;
    dynConSTACK verem;

    allocStack(&verem, veremMeret);

    szam = 10;
    push(&verem, szam);

    szam = 20;
    push(&verem, szam);

    szam = 30;
    push(&verem, szam);

    szam = 40;
    push(&verem, szam);

    szam = 50;
    push(&verem, szam);

    szam = 60;
    push(&verem, szam);

    szam = 70;
    push(&verem, szam);

    szam = 80;
    push(&verem, szam);

    szam = 90;
    push(&verem, szam);


    int veremMeret1;

    scanf("%d", &veremMeret1);

    dynConSTACK ujverem;

    allocStack(&ujverem, veremMeret1);

    szam = 10;
    push(&ujverem, szam);

    szam = 20;
    push(&ujverem, szam);

    szam = 30;
    push(&ujverem, szam);

    szam = 40;
    push(&ujverem, szam);

    szam = 50;
    push(&ujverem, szam);

    szam = 60;
    push(&ujverem, szam);

    szam = 70;
    push(&ujverem, szam);

    szam = 80;
    push(&ujverem, szam);

    szam = 90;
    push(&ujverem, szam);

    top(&verem);
    top(&ujverem);
    deallocStack(&verem);
    deallocStack(&ujverem);

    return 0;
}
