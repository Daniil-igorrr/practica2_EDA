// QUÉ DEBE HACER
// Implementa el operador  bool Person::operator<(const Person& otra) const  que
// dice si 'this' (la persona de la izquierda en  a < b) va ANTES que 'otra'.
// Criterio de orden:
//   1. primero por edad, de menor a mayor,
//   2. si tienen la misma edad, por nombre en orden alfabético (el < de string).
// Dos personas con la misma edad y el mismo nombre no son "menor" una que la otra.
//
// Con este operador definido, las personas se pueden ordenar con sort() de
// <algorithm>, usarse como clave de un set/map, etc.
//
// El constructor y los getters ya están hechos. 'const' al final de operator< indica
// que no modifica el objeto; los atributos de 'otra' se leen como otra.age_ (dentro
// de la clase se puede acceder a los atributos privados de otro objeto de la misma clase).
//
// IDEA DE SOLUCIÓN
//   if (age_ != otra.age_) {
//       return age_ < otra.age_;
//   }
//   return name_ < otra.name_;
//
// EJEMPLOS
//   Person("Zoe", 20) < Person("Ana", 30)   -> true    (20 < 30)
//   Person("Ana", 20) < Person("Zoe", 20)   -> true    (misma edad, "Ana" < "Zoe")
//   Person("Ana", 30) < Person("Zoe", 20)   -> false
//   Person("Ana", 20) < Person("Ana", 20)   -> false   (iguales)
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

bool Person::operator<(const Person& otra) const {
    // TODO: implementar
    return false;
}
