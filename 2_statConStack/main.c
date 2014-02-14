#include <stdio.h>
#include <stdlib.h>

#include "statConStack.h"

int main()
{
    statConSTACK *verem;                    // statConSTACK típusú változóra mutató pointer.

    verem = malloc(sizeof(statConSTACK));   // Helyfoglalás a veremnek.

    verem->topElement = -1;                 // A verem üresre állítása.

    statConSTACK *verem2;
    verem2 = malloc(sizeof(statConSTACK));
    verem2->topElement = -1;


    int szam;

    szam = 10;
    push(verem, szam);

    szam = 20;
    push(verem, szam);

    szam = 30;
    push(verem, szam);

    szam = 40;
    push(verem, szam);

    szam = 50;
    push(verem, szam);

    szam = 60;
    push(verem, szam);

    szam = 70;
    push(verem, szam);

    szam = 80;
    push(verem, szam);

    szam = 90;
    push(verem, szam);


    szam = 100;
    push(verem2, szam);

    szam = 200;
    push(verem2, szam);

    szam = 300;
    push(verem2, szam);

    szam = 400;
    push(verem2, szam);

    szam = 500;
    push(verem2, szam);

    szam = 600;
    push(verem2, szam);

    szam = 700;
    push(verem2, szam);

    szam = 800;
    push(verem2, szam);

    szam = 900;
    push(verem2, szam);

    top(verem);
    top(verem2);
    free(verem);    // a verem felszabadítása.
    verem = NULL;
    free(verem2);    // a verem felszabadítása.
    verem2 = NULL;
    return 0;
}
