// CLASE AddressBook - ejercicio E10: clase compuesta: devolver un subconjunto de instancias
//
// La clase AddressBook contiene varias Person (clase COMPUESTA: una clase que tiene
// otras clases como atributos). Person.h/.cc ya están hechos y no hay que tocarlos.
//
// Este fichero (.h) es la DECLARACIÓN de la clase: dice qué atributos y métodos tiene.
// Ya viene escrito y no hay que modificarlo. Lo que hay que programar está en el
// fichero .cc de esta misma carpeta.
//
// #ifndef / #define / #endif (el "guard") evitan que el fichero se incluya dos veces
// en la misma compilación, lo que daría error de "clase redefinida".
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

// TODO: incluir la librería <vector> (para usar vector)
#include "Person.h"
using namespace std;

class AddressBook {
public:
    void add(const Person& p);
    vector<Person> older_than(int edad) const;   // las de edad estrictamente mayor que 'edad'

private:
    vector<Person> people_;
};

#endif
