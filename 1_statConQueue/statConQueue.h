#include <stdbool.h>    // Logikai változó típus definiációját tartalmazó gcc könyvtár

#define QUEUE_SIZE 8  // A sor maximális méretét tartalmazó konstans definiálása.

// sor típus deklarálása:
typedef struct {
    int queueArray[QUEUE_SIZE];   // A sor elemeit tartalmazó tömb.
    int head;                     // A sor elején lévő elem indexe.
    int tail;                     // A sor végén álló elem indexe.
} statConQUEUE;

// Veremkezelő függvények deklarálása:
bool isEmpty(statConQUEUE *q);          // Logikai értéket ad vissza: tail <= 0 -> true;
bool isFull(statConQUEUE *q);           // Logikai értéket ad vissza: tail >= QUEUE_SIZE -> true;
void push (statConQUEUE *q, int);       // Berak a paraméterben kapott dynConSTACK-be egy megadott egész számot.
int  pop(statConQUEUE *q);              // Kiveszi a paraméterben kapott dynConSTACK legfelső értékét és átadja az őt hívó függvénynek.
void first (statConQUEUE *q);           // Kiírja a paraméterben kapott dynConSTACK legfelső értékét.
