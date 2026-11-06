// CLASE Person - ejercicio E08: operator<<
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
#include <ostream>
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

// Operador de salida: NO es un método de Person (el objeto de la izquierda de <<
// es el ostream), sino una función normal que recibe el flujo y la persona.
ostream& operator<<(ostream& os, const Person& p);

#endif
