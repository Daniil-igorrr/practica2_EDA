// QUÉ DEBE HACER
// Implementa el DESTRUCTOR  ~ArrayInt(). Se ejecuta automáticamente cuando el objeto
// se destruye (al salir del bloque donde se declaró, o al hacer delete). El
// constructor reserva memoria con new[]; el destructor debe liberarla, o esa memoria
// se pierde para siempre ("fuga de memoria").
//
// El resto de la clase (constructor, get, set, size) ya está hecho. La copia de
// objetos está prohibida en este ejercicio (= delete) para centrarse en el destructor.
//
// IDEA DE SOLUCIÓN
// Un array reservado con new[] se libera con delete[] (con corchetes):
//      delete[] data_;
// (delete sin corchetes sería un error para un array.)
//
// EJEMPLOS
//   {
//       ArrayInt a(1000, 0);   // reserva memoria
//   }                          // aquí se llama al destructor: la memoria se libera
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "ArrayInt.h"

ArrayInt::ArrayInt(size_t n, int valor) {
    data_ = new int[n];
    n_ = n;
    for (size_t i = 0; i < n_; i++) {
        data_[i] = valor;
    }
}

ArrayInt::~ArrayInt() {
    // TODO: implementar
}

int ArrayInt::get(size_t i) const {
    return data_[i];
}

void ArrayInt::set(size_t i, int valor) {
    data_[i] = valor;
}

size_t ArrayInt::size() const {
    return n_;
}
