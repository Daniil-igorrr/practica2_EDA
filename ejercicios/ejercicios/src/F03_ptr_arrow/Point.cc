// QUÉ DEBE HACER
// Cuando se tiene un PUNTERO a un objeto, sus atributos se alcanzan con el operador ->:
//      p->x       equivale a       (*p).x
//
// Implementa las tres funciones declaradas en Point.h (el constructor ya está hecho):
//   1. void move_by(Point* p, int dx, int dy): suma dx a la x y dy a la y del punto
//      apuntado, modificándolo. Si p es nullptr, no hace nada.
//   2. bool is_origin(const Point* p): true si el punto apuntado es (0, 0). Si p es
//      nullptr, devuelve false.
//   3. Point* farthest(Point* a, Point* b): devuelve el puntero (a o b, no una copia)
//      al punto más alejado del origen, comparando x*x + y*y. En un empate devuelve a.
//      Si uno de los dos es nullptr devuelve el otro; si ambos lo son, nullptr.
//
// IDEA DE SOLUCIÓN
//   - Comprueba siempre != nullptr antes de usar ->  (usarlo sobre nullptr rompe el programa).
//   - desplazar:  p->x += dx;  p->y += dy;
//   - farthest: calcula las dos distancias al cuadrado y devuelve la dirección
//     (el propio puntero a o b) del mayor.
//
// EJEMPLOS
//   Point a(3, 4);
//   move_by(&a, 1, 1);             // a pasa a ser (4, 5)
//   is_origin(&a)                    -> false
//   Point b(1, 1);
//   farthest(&a, &b) == &a         -> true
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "Point.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

void move_by(Point* p, int dx, int dy) {
    // TODO: implementar
}

bool is_origin(const Point* p) {
    // TODO: implementar
    return false;
}

Point* farthest(Point* a, Point* b) {
    // TODO: implementar
    return nullptr;
}
