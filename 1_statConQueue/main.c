// BYTE BUFFER
// a program 256 random bit értékeket generál, melyeket 1 Byte-os csoportokban küld a kimenetre.

#include <stdio.h>
#include <stdlib.h> // Könyvtár a memória kezelő fügvények hívásához (malloc(), calloc(). free()...).

#include "statConQueue.h"   // A sor szerkezetet leíró forrás linkelése.


int main()
{
    statConQUEUE *sor;                    // statConQUEUE típusú változóra mutató pointer.

    sor= malloc(sizeof(statConQUEUE));   // Helyfoglalás a sornak.

    int i;

    for(i = 1; i<=256; i++){
        printf("%i. ", i);

        push(sor, (rand() % 2));

        // A ciklus összevárja és eltárolja a random bit értékeket,
        // míg ki nem adnak egy teljes Byteot, majd az eredeti sorrendben irja ki.
        if (i%8 == 0){
            printf("%i", pop(sor));
            printf("%i", pop(sor));
            printf("%i", pop(sor));
            printf("%i", pop(sor));
            printf("%i", pop(sor));
            printf("%i", pop(sor));
            printf("%i", pop(sor));
            printf("%i\n", pop(sor));
        }
    }

    free(sor);      // a sor felszabadítása.
    sor = NULL;     // és kiürítése.
    return 0;
}
