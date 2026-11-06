// QUÉ DEBE HACER
// Implementa el CONSTRUCTOR DE COPIA  ArrayInt(const ArrayInt& otro), que se llama
// cuando se crea un objeto a partir de otro ya existente (ArrayInt b(a); o al pasar
// o devolver un ArrayInt por valor). Debe crear una copia PROFUNDA: un array propio
// con los mismos valores.
//
// Si no se programa (o se programa mal, copiando solo el puntero), los dos objetos
// compartirían el MISMO array: modificar uno cambiaría el otro y, al destruirse,
// los dos harían delete[] sobre la misma memoria (error grave, "double free").
//
// El resto de la clase (constructor, destructor, get, set, size) ya está hecho.
//
// IDEA DE SOLUCIÓN
//   1. reserva un array nuevo del mismo tamaño:  data_ = new int[otro.n_];
//   2. guarda el tamaño:                           n_ = otro.n_;
//   3. copia los valores uno a uno con un bucle:   data_[i] = otro.data_[i];
//
// EJEMPLOS
//   ArrayInt a(3, 7);      // a = {7, 7, 7}
//   ArrayInt b(a);         // b = {7, 7, 7}, con su propia memoria
//   b.set(0, 99);          // b = {99, 7, 7}   y   a sigue siendo {7, 7, 7}
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

ArrayInt::ArrayInt(const ArrayInt& otro) {
    // TODO: implementar
}

ArrayInt::~ArrayInt() {
    delete[] data_;
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
