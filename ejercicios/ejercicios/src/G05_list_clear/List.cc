// EJERCICIO G05 - vaciar la lista y reutilizarla
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
//   - clear()                     <-- NUEVO en este ejercicio
// Si ya hiciste el ejercicio G04, copia aquí tu List.cc y añade solo lo nuevo.
// Si empiezas por este ejercicio, tendrás que escribir también los métodos anteriores.
//
// QUÉ DEBE HACER
// Añade  void clear() : libera TODOS los nodos con delete y deja la lista vacía
// (head_ == nullptr). Después la lista tiene que seguir siendo utilizable: se puede
// volver a insertar en ella.
//
// El bucle que libera los nodos ya lo escribiste en el destructor de G01. Aquí lo
// conviertes en un método reutilizable y haces que el destructor lo llame, para no
// tener el mismo código en dos sitios.
//
// CÓMO PENSARLO
//   - El error típico es hacer delete de un nodo y luego usar su next. Hay que
//     guardar el nodo que se va a borrar, avanzar, y solo entonces borrar.
//   - Dejar head_ a nullptr al terminar no es opcional: si no, la lista queda
//     apuntando a nodos liberados y el siguiente count() o el destructor fallan
//     (doble liberación).
//   - clear() sobre una lista vacía no debe hacer nada, y llamarlo dos veces
//     seguidas tampoco debe fallar. Las pruebas comprueban las dos cosas.
//
// EJEMPLOS
//   head_ --> [3]-->[5]-->[7]      clear()  ->  head_ == nullptr; 3 delete
//   (vacía)                        clear()  ->  no hace nada
//   después de clear(): push_back(9)  ->  count() == 1   at(0) == 9
//
// No cambies los nombres ni las firmas de List.h: las pruebas los usan tal y como
// están declarados. Las pruebas cuentan los new y los delete: si falta alguno, el
// resultado es MEMORY aunque los valores sean correctos.
#include "List.h"
