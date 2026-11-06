// QUÉ DEBE HACER
// Implementa el OPERADOR DE ASIGNACIÓN  operator=, que se llama cuando se asigna un
// objeto a otro que YA existe:  b = a;  (distinto del constructor de copia, que crea
// un objeto nuevo). Debe dejar a 'this' como una copia PROFUNDA de 'otro'.
//
// Requisitos:
//   - 'this' ya tiene un array propio que hay que liberar para no perder memoria,
//   - el nuevo tamaño puede ser distinto del anterior,
//   - la autoasignación  a = a;  no debe romper nada,
//   - debe devolver *this (una referencia al propio objeto) para permitir encadenar:
//     p = q = r;
//
// El resto de la clase (constructores, destructor, get, set, size) ya está hecho.
//
// EJEMPLOS
//   ArrayInt a(3, 7), b(2, 1);
//   b = a;            // b pasa a ser {7, 7, 7} (tamaño 3), independiente de a
//   b.set(0, 99);     // a sigue siendo {7, 7, 7}
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
    data_ = new int[otro.n_];
    n_ = otro.n_;
    for (size_t i = 0; i < n_; i++) {
        data_[i] = otro.data_[i];
    }
}

ArrayInt::~ArrayInt() {
    delete[] data_;
}

ArrayInt& ArrayInt::operator=(const ArrayInt& otro) {
    // TODO: implementar
    return *this;
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
