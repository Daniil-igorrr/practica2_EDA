// EJERCICIO G06 - eliminar un nodo
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
//   - find()
//   - push_front()
//   - push_back()
//   - erase()                     <-- NUEVO en este ejercicio
//   - clear()
// Si ya hiciste el ejercicio G05, copia aquí tu List.cc y añade solo lo nuevo.
// Si empiezas por este ejercicio, tendrás que escribir también los métodos anteriores.
//
// QUÉ DEBE HACER
// Añade  bool erase(int x) : elimina la PRIMERA aparición de x liberando su nodo con
// delete y devuelve true. Si x no está, no cambia nada y devuelve false.
//
// CÓMO PENSARLO
// Para quitar un nodo de la lista hay que puentearlo: el nodo ANTERIOR tiene que
// pasar a apuntar al siguiente del que se borra. El problema es que desde un nodo no
// se puede llegar al anterior, así que durante el recorrido hay que ir mirando el
// siguiente del nodo actual, no el actual.
//
// Casos que hay que tratar (pruébalos todos, uno a uno):
//   - lista vacía,
//   - el nodo a borrar es el primero: no hay anterior, lo que cambia es head_,
//   - el nodo a borrar está en el medio o es el último,
//   - el nodo a borrar es el único de la lista,
//   - x no está en la lista.
//
// Y el orden de siempre: primero se re-enlaza, después se hace delete. En cuanto
// liberas el nodo, su next ya no se puede leer.
//
// EJEMPLOS
//   head_ --> [1]-->[2]-->[3]      erase(2) -> true;   head_ --> [1]-->[3]
//   head_ --> [1]-->[2]-->[3]      erase(1) -> true;   head_ --> [2]-->[3]
//   head_ --> [1]-->[2]-->[1]      erase(1) -> true;   head_ --> [2]-->[1]
//   head_ --> [1]                  erase(9) -> false;  no cambia nada
//   (vacía)                        erase(1) -> false
//
// No cambies los nombres ni las firmas de List.h: las pruebas los usan tal y como
// están declarados. Las pruebas cuentan los new y los delete: si falta alguno, el
// resultado es MEMORY aunque los valores sean correctos.
#include "List.h"
