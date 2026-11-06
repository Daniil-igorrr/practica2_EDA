// QUÉ DEBE HACER
// Implementa  Person AddressBook::oldest() const : devuelve (una copia de) la persona de
// MÁS EDAD de la agenda. Si hay varias con la misma edad máxima, la que se añadió
// primero. Si la agenda está vacía, devuelve Person("", 0).
//
// 'agregar' ya está hecho: guarda cada persona en el vector people_.
//
// IDEA DE SOLUCIÓN
//   1. si people_ está vacío, devuelve Person("", 0),
//   2. guarda la primera como candidata:  Person mayor = people_[0];
//   3. recorre el resto; si alguna tiene get_age() MAYOR que la de la candidata,
//      ella pasa a ser la candidata (con > estricto, en un empate se queda la primera),
//   4. devuelve la candidata.
//
// EJEMPLOS
//   AddressBook ag;
//   ag.add(Person("Ana", 20)); ag.add(Person("Eva", 45)); ag.add(Person("Luis", 30));
//   ag.oldest().get_name() -> "Eva"
//   (agenda vacía) ag.oldest().get_age() -> 0
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "AddressBook.h"

void AddressBook::add(const Person& p) {
    people_.push_back(p);
}

Person AddressBook::oldest() const {
    // TODO: implementar
    return Person("", 0);
}
