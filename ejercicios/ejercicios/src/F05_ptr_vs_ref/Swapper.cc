// QUÉ DEBE HACER
// Hay dos formas de que una función modifique las variables de quien la llama:
//   - por REFERENCIA (int& a): a es otro nombre para la variable original; se usa
//     como una variable normal (a = 5;). No puede ser "nula".
//   - por PUNTERO (int* a): a guarda la dirección de la variable; se accede a ella con
//     * (*a = 5;) y quien llama pasa la dirección con & (f(&x)). Puede ser nullptr.
//
// Implementa las dos versiones de la misma operación, INTERCAMBIAR los valores de dos
// enteros:
//   1. with_pointers(int* a, int* b): intercambia los valores apuntados. Si alguno de los
//      dos punteros es nullptr, no hace nada.
//   2. with_references(int& a, int& b): intercambia los valores de las dos variables.
//
// IDEA DE SOLUCIÓN
// Necesitas una variable temporal:
//   with_pointers:      int temporal = *a;  *a = *b;  *b = temporal;
//   with_references:   int temporal = a;   a = b;    b = temporal;
//
// EJEMPLOS
//   Swapper inter;  int x = 1, y = 2;
//   inter.with_pointers(&x, &y);       // x vale 2 e y vale 1
//   inter.with_references(x, y);      // vuelven a valer 1 y 2
//   inter.with_pointers(&x, nullptr);  // no hace nada
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "Swapper.h"

void Swapper::with_pointers(int* a, int* b) const {
    // TODO: implementar
}

void Swapper::with_references(int& a, int& b) const {
    // TODO: implementar
}
