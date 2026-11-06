// CLASE Person - ejercicio E10: clase compuesta: devolver un subconjunto de instancias
// (Clase ya completa: no hay que modificarla.)
//
// Este fichero (.h) es la DECLARACIÓN de la clase: dice qué atributos y métodos tiene.
// Ya viene escrito y no hay que modificarlo. Lo que hay que programar está en el
// fichero .cc de esta misma carpeta.
//
// #ifndef / #define / #endif (el "guard") evitan que el fichero se incluya dos veces
// en la misma compilación, lo que daría error de "clase redefinida".
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
public:
    Person(const string& nombre, int edad);
    string get_name() const;
    int get_age() const;

private:
    string name_;
    int age_;
};

#endif
