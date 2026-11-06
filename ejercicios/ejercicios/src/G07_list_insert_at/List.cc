// EJERCICIO G07 - insertar en una posición
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
//   - erase()
//   - clear()
//   - insert_at()                 <-- NUEVO en este ejercicio
// Si ya hiciste el ejercicio G06, copia aquí tu List.cc y añade solo lo nuevo.
// Si empiezas por este ejercicio, tendrás que escribir también los métodos anteriores.
//
// QUÉ DEBE HACER
// Añade  bool insert_at(int pos, int x) : inserta x en la posición pos, justo delante
// del elemento que hubiera en esa posición, y devuelve true. pos puede ir de 0 hasta
// count(), los dos incluidos: pos == count() equivale a añadir al final. Si pos está
// fuera de ese rango no inserta nada y devuelve false.
//
// Es el método insertAt() de la práctica, con el mismo criterio para pos.
//
// CÓMO PENSARLO
// Primero la validación: fuera de rango es false y la lista no se toca. Fíjate en que
// aquí sí vale pos == count() (al contrario que en at()), porque insertar al final de
// una lista de 3 elementos es insertar en la posición 3.
//
// Después, dos casos:
//   - pos == 0: el nodo nuevo pasa a ser el primero. Ya tienes un método que hace
//     exactamente eso: reutilízalo en vez de repetir el código.
//   - pos > 0: hay que colocarse en el nodo ANTERIOR a la posición pos y enganchar el
//     nodo nuevo entre él y su siguiente. Cuenta bien cuántos pasos hay que dar: para
//     insertar en la posición 1 el anterior es el nodo 0.
//
// En una lista vacía solo es válido insert_at(0, x).
//
// EJEMPLOS
//   head_ --> [1]-->[2]-->[3]      insert_at(1, 9) -> true;  [1]-->[9]-->[2]-->[3]
//   head_ --> [1]-->[2]            insert_at(0, 8) -> true;  [8]-->[1]-->[2]
//   head_ --> [1]-->[2]            insert_at(2, 9) -> true;  [1]-->[2]-->[9]
//   head_ --> [1]-->[2]            insert_at(3, 9) -> false; insert_at(-1, 9) -> false
//   (vacía)                        insert_at(0, 5) -> true;  insert_at(1, 5) -> false
//
// No cambies los nombres ni las firmas de List.h: las pruebas los usan tal y como
// están declarados. Las pruebas cuentan los new y los delete: si falta alguno, el
// resultado es MEMORY aunque los valores sean correctos.
#include "List.h"
