// QUÉ DEBE HACER
// Implementa  vector<Person> AddressBook::older_than(int edad) const : devuelve un vector
// nuevo con las personas de la agenda cuya edad es ESTRICTAMENTE mayor que 'edad',
// en el mismo orden en que se añadieron. La agenda no cambia. Si no hay ninguna,
// devuelve un vector vacío.
//
// 'agregar' ya está hecho: guarda cada persona en el vector people_.
//
// IDEA DE SOLUCIÓN
//   1. crea un vector<Person> vacío para el resultado,
//   2. recorre people_ (for (const Person& p : people_)),
//   3. si p.get_age() > edad, añádela al resultado con push_back,
//   4. devuelve el resultado.
//
// EJEMPLOS
//   AddressBook ag;
//   ag.add(Person("Ana", 20)); ag.add(Person("Eva", 45)); ag.add(Person("Luis", 30));
//   ag.older_than(25)  -> {Eva, Luis}   (en el orden en que se añadieron)
//   ag.older_than(45)  -> {}   (Eva tiene 45, no es mayor)
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "AddressBook.h"

void AddressBook::add(const Person& p) {
    people_.push_back(p);
}

vector<Person> AddressBook::older_than(int edad) const {
    // TODO: implementar
    return {};
}
