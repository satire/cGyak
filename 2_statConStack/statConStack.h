#include <stdbool.h>    // Logikai változó típus definiációját tartalmazó gcc könyvtár

#define STACK_SIZE  5  // A verem maximális méretét tartalmazó konstans definiálása.

// Verem típus deklarálása:
typedef struct {
  int stackArray[STACK_SIZE];   // A verem elemeit tartalmazó tömb.
  int topElement;               // A verem tetején lévő elem indexe.
} statConSTACK;

// Veremkezelő függvények deklarálása:
bool isEmpty(statConSTACK *s);          // Logikai értéket ad vissza: top == -1 -> true, top != -1 -> false;
bool isFull(statConSTACK *s);           // Logikai értéket ad vissza: top == stackSize-1 -> true, top != stackSize-1 -> false;
void push (statConSTACK *s, int);       // Berak a paraméterben kapott dynConSTACK-be egy megadott egész számot.
int  pop(statConSTACK *s);              // Kiveszi a paraméterben kapott dynConSTACK legfelső értékét és átadja az őt hívó függvénynek.
void top (statConSTACK *s);             // Kiírja a paraméterben kapott dynConSTACK legfelső értékét.
