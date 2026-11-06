// EJERCICIO G08 - forma canónica: copia y asignación
//
// Este fichero llega VACÍO a propósito: en el grupo G la lista la escribes tú entera,
// no hay nada hecho. La declaración de la clase está en List.h (no se modifica) y
// aquí defines todos sus métodos.
//
// QUÉ TIENES QUE ESCRIBIR
// Todo lo que declara List.h:
//   - List()
//   - ~List()
//   - List(const List& otra)      <-- NUEVO en este ejercicio
//   - operator=                   <-- NUEVO en este ejercicio
//   - count()
//   - at()
//   - find()
//   - push_front()
//   - push_back()
//   - erase()
//   - clear()
//   - insert_at()
//   - copy() (privado)            <-- NUEVO en este ejercicio
// Si ya hiciste el ejercicio G07, copia aquí tu List.cc y añade solo lo nuevo.
// Si empiezas por este ejercicio, tendrás que escribir también los métodos anteriores.
//
// QUÉ DEBE HACER
// La FORMA CANÓNICA de la clase. Hasta ahora copiar una List estaba prohibido
// (= delete en List.h); en este ejercicio se permite y hay que hacerla bien:
//   - List(const List& otra)              constructor de copia,
//   - List& operator=(const List& otra)   operador de asignación,
//   - void copy(const List& otra)         método privado que usan los dos.
//
// Es exactamente la Sección 4.2 de la práctica, con una lista de enteros en vez de
// pistas.
//
// CÓMO PENSARLO
// La copia tiene que ser PROFUNDA. Copiar head_ tal cual haría que las dos listas
// compartieran los mismos nodos: modificar una cambiaría la otra y, al destruirse
// las dos, cada nodo se liberaría dos veces (el programa falla). Hay que reservar un
// nodo nuevo por cada nodo del original, en el mismo orden.
//
//   - copy(): recorre la lista original creando un nodo nuevo por cada uno y
//     enlazándolo al final de la copia. Para no recorrer la copia entera en cada
//     paso, guarda en un puntero auxiliar el último nodo que has creado. Este método
//     da por supuesto que la lista está vacía al entrar.
//   - constructor de copia: la lista nueva empieza vacía (head_ a nullptr) y después
//     llama a copy().
//   - operator=: el objeto de la izquierda YA tiene nodos, así que primero hay que
//     liberarlos (ya tienes un método para eso) y después copiar. Dos cosas más:
//       · la AUTOASIGNACIÓN (p = p): si vacías la lista antes de comprobarlo,
//         destruyes justo los datos que ibas a copiar. Compruébalo antes de nada.
//       · devuelve *this por referencia, para que funcione a = b = c.
//
// EJEMPLOS
//   a: [1]-->[2]-->[3]
//   List b(a);      ->  b: [1]-->[2]-->[3]   con otros tres nodos distintos
//   a.erase(1);     ->  b no cambia;  b.push_front(0) no cambia a
//   c = a;          ->  c libera lo que tuviera y se queda con una copia propia
//   a = a;          ->  a no cambia (y no se pierde ni se libera nada)
//
// No cambies los nombres ni las firmas de List.h: las pruebas los usan tal y como
// están declarados. Las pruebas cuentan los new y los delete: si falta alguno, el
// resultado es MEMORY aunque los valores sean correctos.
#include "List.h"
