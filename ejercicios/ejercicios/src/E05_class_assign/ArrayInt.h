// CLASE ArrayInt - ejercicio E05: operator=
//
// La clase ArrayInt guarda un array de enteros en memoria DINÁMICA (con new[]).
// Atributos: data_ (puntero al array) y n_ (número de elementos).
//
// Este fichero (.h) es la DECLARACIÓN de la clase: dice qué atributos y métodos tiene.
// Ya viene escrito y no hay que modificarlo. Lo que hay que programar está en el
// fichero .cc de esta misma carpeta.
//
// #ifndef / #define / #endif (el "guard") evitan que el fichero se incluya dos veces
// en la misma compilación, lo que daría error de "clase redefinida".
#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cstddef>
using namespace std;

class ArrayInt {
public:
    ArrayInt(size_t n, int valor);   // crea n elementos, todos con el valor dado
    ArrayInt(const ArrayInt& otro);
    ArrayInt& operator=(const ArrayInt& otro);
    ~ArrayInt();
    int get(size_t i) const;
    void set(size_t i, int valor);
    size_t size() const;

private:
    int* data_;
    size_t n_;
};

#endif
