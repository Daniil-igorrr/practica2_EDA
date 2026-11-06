// QUÉ DEBE HACER
// Hay que llevar la cuenta de cuántos objetos Person se han creado en total. Ese
// número no pertenece a ningún objeto concreto sino a la CLASE, así que se guarda en
// un atributo estático (static): existe una única copia, compartida por todos los
// objetos, y existe aunque no haya ninguno creado.
//
// Tres cosas que programar:
//   1. DEFINIR el atributo estático created_ (declarado en Person.h con static) e
//      inicializarlo a 0. Un atributo estático se declara dentro de la clase pero se
//      define UNA vez fuera, en el .cc, SIN repetir la palabra static:
//          int Person::created_ = 0;
//   2. Incrementar created_ en el CONSTRUCTOR, para contar cada objeto que se crea.
//   3. Implementar el método estático total_created(), que devuelve created_.
//
// Un método estático (static) también pertenece a la clase: se llama con
// Person::total_created() sin necesidad de ningún objeto, y no tiene 'this', así
// que solo puede usar atributos estáticos (no name_ ni age_).
//
// Nota: el contador NO baja cuando un objeto se destruye (cuenta las creadas, no
// las que siguen vivas). Las pruebas no copian objetos.
//
// EJEMPLOS
//   int antes = Person::total_created();
//   Person a("Ana", 30);
//   Person b("Luis", 5);
//   Person::total_created() - antes  -> 2
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "Person.h"

// TODO: definir aquí el atributo estático created_ (ver arriba)

Person::Person(const string& nombre, int edad) {
    name_ = nombre;
    age_ = edad;
    // TODO: contar este objeto
}

string Person::get_name() const {
    return name_;
}

int Person::get_age() const {
    return age_;
}

int Person::total_created() {
    // TODO: implementar
    return 0;
}
