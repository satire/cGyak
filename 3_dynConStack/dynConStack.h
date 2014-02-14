#include <stdbool.h>    // Logikai változó típus definiációját tartalmazó gcc könyvtár

// Verem típus deklarálása:
typedef struct {
  int *stackArray;  // A verem elemeit tartalmazó tömbre mutató pointer.
  int topElement;   // A verem tetején lévő elem indexe.
  int stackSize;    // A verem méretét tartalmazó egész változó.
} dynConSTACK;

// Veremkezelő függvények deklarálása:
void allocStack(dynConSTACK *s, int stackSize);       // Létrehozza a vermet
bool isEmpty(dynConSTACK *s);                         // Logikai értéket ad vissza: top == -1 -> true, top != -1 -> false;
bool isFull(dynConSTACK *s);                          // Logikai értéket ad vissza: top == stackSize-1 -> true, top != stackSize-1 -> false;
void push (dynConSTACK *s, int);                      // Berak a paraméterben kapott dynConSTACK-be egy megadott egész számot.
int  pop(dynConSTACK *s);                             // Kiveszi a paraméterben kapott dynConSTACK legfelső értékét és átadja az őt hívó függvénynek.
void top (dynConSTACK *s);                            // Kiírja a paraméterben kapott dynConSTACK legfelső értékét.
void deallocStack(dynConSTACK *s);                    // Felszabadítja a verem által lefoglalt területet.
