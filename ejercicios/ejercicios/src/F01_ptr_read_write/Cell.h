// CLASE Cell - ejercicio F01: leer y escribir a través de un puntero
//
// Este fichero (.h) es la DECLARACIÓN de la clase: dice qué atributos y métodos tiene.
// Ya viene escrito y no hay que modificarlo. Lo que hay que programar está en el
// fichero .cc de esta misma carpeta.
//
// #ifndef / #define / #endif (el "guard") evitan que el fichero se incluya dos veces
// en la misma compilación, lo que daría error de "clase redefinida".
#ifndef CELL_H
#define CELL_H

class Cell {
public:
    Cell(int valor);
    int get() const;
    int* address();                    // puntero al valor interno
    void add_to(int* destino) const;    // suma el valor a la variable apuntada

private:
    int value_;
};

#endif
