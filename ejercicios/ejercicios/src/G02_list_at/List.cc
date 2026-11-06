// EJERCICIO G02 - recorrer hasta una posición
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
//   - at()                        <-- NUEVO en este ejercicio
//   - push_front()
// Si ya hiciste el ejercicio G01, copia aquí tu List.cc y añade solo lo nuevo.
// Si empiezas por este ejercicio, tendrás que escribir también los métodos anteriores.
//
// QUÉ DEBE HACER
// Añade  int at(int pos) const : devuelve el valor que está en la posición pos,
// contando desde 0 en el primer nodo. Si pos no existe (negativa, o mayor o igual
// que el número de nodos) devuelve 0.
//
// at() es el método que usan todas las pruebas siguientes para mirar el contenido de
// la lista, así que merece la pena dejarlo bien.
//
// CÓMO PENSARLO
// Es el mismo recorrido de count(), pero parando al llegar a la posición pedida en
// vez de llegar hasta el final. Dos formas de equivocarse:
//   - no comprobar pos < 0 antes de empezar,
//   - salir del bucle sin comprobar si el puntero acabó en nullptr: si pos se pasa
//     del final, se leería un nodo que no existe (CRASH o basura).
// Fíjate en que las posiciones van de 0 a count()-1: at(count()) NO existe.
//
// EJEMPLOS
//   head_ --> [7]-->[5]-->[3]      at(0) -> 7    at(1) -> 5    at(2) -> 3
//   head_ --> [7]-->[5]-->[3]      at(3) -> 0    at(-1) -> 0
//   (vacía)                        at(0) -> 0
//
// No cambies los nombres ni las firmas de List.h: las pruebas los usan tal y como
// están declarados. Las pruebas cuentan los new y los delete: si falta alguno, el
// resultado es MEMORY aunque los valores sean correctos.
#include "List.h"
