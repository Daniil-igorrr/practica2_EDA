// EJERCICIO G04 - devolver un puntero al dato
//
// Este fichero llega VACÍO a propósito: en el grupo G la lista la escribes tú entera,
// no hay nada hecho. La declaración de la clase está en List.h (no se modifica) y
// aquí defines todos sus métodos.
//
// QUÉ TIENES QUE ESCRIBIR
// Todo lo que declara List.h:
//   - List()
//   - ~List()
//   - count()
//   - at()
//   - find()                      <-- NUEVO en este ejercicio
//   - push_front()
//   - push_back()
// Si ya hiciste el ejercicio G03, copia aquí tu List.cc y añade solo lo nuevo.
// Si empiezas por este ejercicio, tendrás que escribir también los métodos anteriores.
//
// QUÉ DEBE HACER
// Añade  const int* find(int x) const : busca la primera aparición de x y devuelve un
// PUNTERO al valor guardado en el nodo. Si x no está en la lista, devuelve nullptr.
//
// Este es el patrón de los métodos get() y findById() de la práctica: no se devuelve
// una copia del dato, sino la dirección del dato que vive dentro de la estructura.
//
// CÓMO PENSARLO
// Es el recorrido de siempre, comparando el valor de cada nodo. Lo que cambia es lo
// que se devuelve:
//   - si lo encuentras, la dirección del campo del nodo, no una copia suya: una
//     prueba comprueba que dos búsquedas del mismo valor devuelven el MISMO puntero,
//   - si llegas al final sin encontrarlo, nullptr.
// Devolver la dirección de una variable local sería un error grave: esa variable
// desaparece al salir del método y el puntero quedaría colgando.
//
// El const del tipo de retorno significa que quien reciba el puntero puede leer el
// valor pero no modificarlo.
//
// EJEMPLOS
//   head_ --> [4]-->[7]-->[9]      find(7)  -> puntero a ese 7   (*p == 7)
//   head_ --> [4]-->[7]-->[9]      find(5)  -> nullptr
//   (vacía)                        find(1)  -> nullptr
//
// No cambies los nombres ni las firmas de List.h: las pruebas los usan tal y como
// están declarados. Las pruebas cuentan los new y los delete: si falta alguno, el
// resultado es MEMORY aunque los valores sean correctos.
#include "List.h"
