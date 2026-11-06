// EJERCICIO G03 - añadir al final
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
//   - push_front()
//   - push_back()                 <-- NUEVO en este ejercicio
// Si ya hiciste el ejercicio G02, copia aquí tu List.cc y añade solo lo nuevo.
// Si empiezas por este ejercicio, tendrás que escribir también los métodos anteriores.
//
// QUÉ DEBE HACER
// Añade  void push_back(int x) : crea un nodo con x y lo coloca al FINAL de la lista.
//
// CÓMO PENSARLO
// head_ apunta al principio, así que para llegar al final hay que recorrer. Son dos
// casos:
//   - lista vacía: no hay nadie al final, el nodo nuevo pasa a ser head_,
//   - lista no vacía: hay que llegar al ÚLTIMO nodo (el que tiene next == nullptr) y
//     engancharle el nuevo detrás.
// Ojo a la diferencia entre "el último nodo" y "nullptr": si recorres hasta que el
// puntero vale nullptr, te has pasado y ya no tienes a quién enganchar el nodo nuevo.
// La condición del bucle tiene que mirar el next del nodo en el que estás.
//
// Observa de paso lo que cuesta: cada push_back recorre toda la lista. Insertar al
// principio es inmediato; añadir al final, no.
//
// EJEMPLOS
//   (vacía)                        push_back(1)  ->  head_ --> [1|/]
//   head_ --> [1]-->[2]            push_back(3)  ->  head_ --> [1]-->[2]-->[3]
//   push_back(2); push_front(1); push_back(3)  ->  at(0)=1  at(1)=2  at(2)=3
//
// No cambies los nombres ni las firmas de List.h: las pruebas los usan tal y como
// están declarados. Las pruebas cuentan los new y los delete: si falta alguno, el
// resultado es MEMORY aunque los valores sean correctos.
#include "List.h"
