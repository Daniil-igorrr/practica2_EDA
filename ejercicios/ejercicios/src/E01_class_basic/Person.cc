// QUÉ DEBE HACER
// Implementa los tres métodos declarados en Person.h:
//   - el CONSTRUCTOR Person(nombre, edad): guarda los datos recibidos en los
//     atributos name_ y age_ del objeto,
//   - get_name(): devuelve el nombre guardado,
//   - get_age():   devuelve la edad guardada.
//
// Las definiciones de métodos fuera de la clase se escriben con Person:: delante
// del nombre (Person::get_age). "const" al final de un getter indica que no
// modifica el objeto y permite llamarlo sobre objetos constantes.
//
// IDEA DE SOLUCIÓN
// El constructor asigna los parámetros a los atributos dentro del cuerpo:
//      Person::Person(const string& nombre, int edad) {
//          name_ = nombre;
//          age_ = edad;
//      }
// Los getters solo devuelven el atributo correspondiente.
//
// EJEMPLOS
//   Person p("Ana", 30);
//   p.get_name() -> "Ana"
//   p.get_age()   -> 30
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "Person.h"
