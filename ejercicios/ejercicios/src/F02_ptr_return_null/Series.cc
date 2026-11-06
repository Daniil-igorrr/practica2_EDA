// QUÉ DEBE HACER
// Implementa  const int* Series::maximum() const : devuelve un puntero al elemento de
// mayor valor de la serie. Si hay varios con el mismo valor máximo, al PRIMERO de ellos.
// Si la serie está vacía, devuelve nullptr.
//
// Devolver un puntero (y no una copia del valor) permite distinguir "no hay ninguno"
// (nullptr) de "el máximo es 0", y da acceso al propio dato interno. Es el mismo patrón
// que los típicos métodos get/findById.
//
// El puntero es 'const int*': se puede leer lo apuntado (*p) pero no modificarlo.
// El resto de la clase (constructor, agregar, tamano, elemento) ya está hecho.
//
// IDEA DE SOLUCIÓN
//   1. si n_ == 0, devuelve nullptr,
//   2. guarda la dirección del primer elemento como candidata:  const int* mejor = &data_[0];
//   3. recorre el resto; si data_[i] > *mejor, la candidata pasa a ser &data_[i],
//   4. devuelve la candidata.
//
// EJEMPLOS
//   Series s;  s.add(3); s.add(9); s.add(2);
//   s.maximum()                 -> puntero al segundo elemento;  *s.maximum() vale 9
//   (serie vacía) s.maximum()   -> nullptr
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "Series.h"

Series::Series() {
    n_ = 0;
}

bool Series::add(int x) {
    if (n_ >= 10) {
        return false;
    }
    data_[n_] = x;
    n_++;
    return true;
}

int Series::size() const {
    return n_;
}

const int* Series::element(int i) const {
    if (i < 0 || i >= n_) {
        return nullptr;
    }
    return &data_[i];
}

const int* Series::maximum() const {
    // TODO: implementar
    return nullptr;
}
