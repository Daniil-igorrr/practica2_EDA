// CLASE Point - ejercicio F03: puntero a objeto: el operador ->
//
// Este fichero (.h) es la DECLARACIÓN de la clase: dice qué atributos y métodos tiene.
// Ya viene escrito y no hay que modificarlo. Lo que hay que programar está en el
// fichero .cc de esta misma carpeta.
//
// #ifndef / #define / #endif (el "guard") evitan que el fichero se incluya dos veces
// en la misma compilación, lo que daría error de "clase redefinida".
#ifndef POINT_H
#define POINT_H

class Point {
public:
    int x;
    int y;
    Point(int x, int y);
};

// Funciones que trabajan con punteros a Point:
void move_by(Point* p, int dx, int dy);
bool is_origin(const Point* p);
Point* farthest(Point* a, Point* b);

#endif
