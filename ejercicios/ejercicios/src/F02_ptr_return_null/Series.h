// CLASE Series - ejercicio F02: devolver un puntero a un dato interno o nullptr
//
// Este fichero (.h) es la DECLARACIÓN de la clase: dice qué atributos y métodos tiene.
// Ya viene escrito y no hay que modificarlo. Lo que hay que programar está en el
// fichero .cc de esta misma carpeta.
//
// #ifndef / #define / #endif (el "guard") evitan que el fichero se incluya dos veces
// en la misma compilación, lo que daría error de "clase redefinida".
#ifndef SERIES_H
#define SERIES_H

class Series {
public:
    Series();
    bool add(int x);                  // false si ya hay 10 valores
    int size() const;
    const int* element(int i) const;     // puntero al elemento i (nullptr si no existe)
    const int* maximum() const;            // puntero al valor máximo (nullptr si vacía)

private:
    int data_[10];
    int n_;
};

#endif
