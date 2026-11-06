// QUÉ DEBE HACER
// Un puntero es una variable que guarda la DIRECCIÓN de otra variable:
//   - &x    da la dirección de x           (int* p = &x;)
//   - *p    accede a la variable apuntada  (leer: y = *p;  escribir: *p = 5;)
//
// Implementa los dos métodos de Cell que trabajan con punteros:
//   1. int* address(): devuelve un puntero al atributo value_ de la propia casilla.
//      Quien lo reciba podrá leer y modificar el valor interno a través de él.
//   2. void add_to(int* destino) const: suma el valor de la casilla a la variable a la
//      que apunta 'destino' (*destino += value_). Si 'destino' es nullptr no hace nada.
//
// El constructor y get() ya están hechos.
//
// IDEA DE SOLUCIÓN
//   address():  return &value_;
//   add_to():    comprueba destino != nullptr y usa *destino += value_;
//   (Desreferenciar nullptr, es decir usar *destino cuando vale nullptr, hace que el
//    programa se caiga: siempre hay que comprobarlo si puede venir vacío.)
//
// EJEMPLOS
//   Cell c(5);
//   int* p = c.address();   // p apunta al valor interno de c
//   *p = 9;                   // c.get() ahora vale 9
//   int total = 100;
//   c.add_to(&total);        // total pasa a valer 109
//   c.add_to(nullptr);       // no hace nada
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "Cell.h"

Cell::Cell(int valor) {
    value_ = valor;
}

int Cell::get() const {
    return value_;
}

int* Cell::address() {
    // TODO: implementar
    return nullptr;
}

void Cell::add_to(int* destino) const {
    // TODO: implementar
}
