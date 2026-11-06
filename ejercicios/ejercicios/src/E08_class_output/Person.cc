// QUÉ DEBE HACER
// Implementa  ostream& operator<<(ostream& os, const Person& p)  para poder escribir
// una Person en cualquier flujo de salida: cout, un fichero o un stringstream. Debe
// escribir la persona con el formato  nombre (edad),  por ejemplo  Ana (30).
//
// Requisitos:
//   - no escribe salto de línea al final,
//   - devuelve el propio flujo 'os' (por referencia) para permitir encadenar:
//       cout << p1 << " y " << p2;
//
// No es un método de la clase sino una función normal (su primer operando es el
// flujo, no una Person). Por eso usa los getters públicos: get_name() y
// get_age(). ostream es el tipo común de cout, ofstream y ostringstream.
//
// IDEA DE SOLUCIÓN
//   os << p.get_name() << " (" << p.get_age() << ")";
//   return os;
//
// EJEMPLOS
//   ostringstream oss; oss << Person("Ana", 30);        -> oss.str() vale "Ana (30)"
//   oss << Person("Luis", 5) << " y " << Person("Eva", 41);
//                                                        -> "Luis (5) y Eva (41)"
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "Person.h"

Person::Person(const string& nombre, int edad) {
    name_ = nombre;
    age_ = edad;
}

string Person::get_name() const {
    return name_;
}

int Person::get_age() const {
    return age_;
}

ostream& operator<<(ostream& os, const Person& p) {
    // TODO: implementar
    return os;
}
