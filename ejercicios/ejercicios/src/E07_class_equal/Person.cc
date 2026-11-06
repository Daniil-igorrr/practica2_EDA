// QUÉ DEBE HACER
// Implementa  bool Person::operator==(const Person& otra) const  : dos personas son
// IGUALES si tienen el mismo nombre Y la misma edad. Sin este operador, el
// compilador no sabe comparar dos Person con == (ni buscarlas con find, ni usarlas en
// muchos algoritmos y contenedores).
//
// El constructor y los getters ya están hechos. 'const' al final indica que la
// comparación no modifica el objeto. Dentro de la clase se puede acceder a los
// atributos privados de 'otra' (otra.name_, otra.age_).
//
// IDEA DE SOLUCIÓN
//   return name_ == otra.name_ && age_ == otra.age_;
//
// EJEMPLOS
//   Person("Ana", 30) == Person("Ana", 30)   -> true
//   Person("Ana", 30) == Person("Ana", 31)   -> false  (distinta edad)
//   Person("Ana", 30) == Person("Eva", 30)   -> false  (distinto nombre)
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

bool Person::operator==(const Person& otra) const {
    // TODO: implementar
    return false;
}
