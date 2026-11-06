// EJERCICIO G01 - crear nodos y liberarlos
//
// Este fichero llega VACÍO a propósito: en el grupo G la lista la escribes tú entera,
// no hay nada hecho. La declaración de la clase está en List.h (no se modifica) y
// aquí defines todos sus métodos.
//
// QUÉ DEBE HACER
// La lista mínima que no pierde memoria: insertar al principio, contar y liberar.
//   - List()                 deja la lista vacía,
//   - void push_front(int x) crea un nodo con x y lo pone como primero,
//   - int count() const      número de nodos (0 si está vacía),
//   - ~List()                libera TODOS los nodos.
//
// Cada método se define aquí poniendo la clase delante del nombre:
//      int List::count() const {
//          ...
//      }
//
// CÓMO PENSARLO
// Dibuja la lista antes de escribir código. Lista vacía significa head_ == nullptr,
// y es el caso que hay que tratar aparte casi siempre.
//
//   - push_front: reserva el nodo con new, engánchalo delante de lo que ya había y
//     deja head_ apuntando a él. El orden importa: si cambias head_ antes de haber
//     guardado a dónde apuntaba, pierdes toda la lista.
//   - count: recorre con un puntero auxiliar hasta llegar a nullptr. No muevas head_
//     (lo perderías): recorre siempre con una copia del puntero. Olvidar el avance
//     al siguiente nodo deja un bucle infinito (resultado TIMEOUT).
//   - ~List(): todo lo reservado con new hay que liberarlo con delete. Antes de
//     borrar un nodo hay que haberse guardado su next, porque después del delete ese
//     puntero ya no se puede leer.
//
// EJEMPLOS
//   (vacía)                        count() -> 0
//   push_front(3)                  head_ --> [3|/]               count() -> 1
//   push_front(5); push_front(7)   head_ --> [7]-->[5]-->[3]     count() -> 3
//
// No cambies los nombres ni las firmas de List.h: las pruebas los usan tal y como
// están declarados. Las pruebas cuentan los new y los delete: si falta alguno, el
// resultado es MEMORY aunque los valores sean correctos.
#include "List.h"
