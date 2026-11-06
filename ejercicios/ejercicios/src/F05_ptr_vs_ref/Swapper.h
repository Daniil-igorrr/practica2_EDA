// CLASE Swapper - ejercicio F05: paso por puntero frente a paso por referencia
//
// Este fichero (.h) es la DECLARACIÓN de la clase: dice qué atributos y métodos tiene.
// Ya viene escrito y no hay que modificarlo. Lo que hay que programar está en el
// fichero .cc de esta misma carpeta.
//
// #ifndef / #define / #endif (el "guard") evitan que el fichero se incluya dos veces
// en la misma compilación, lo que daría error de "clase redefinida".
#ifndef SWAPPER_H
#define SWAPPER_H

class Swapper {
public:
    void with_pointers(int* a, int* b) const;
    void with_references(int& a, int& b) const;
};

#endif
