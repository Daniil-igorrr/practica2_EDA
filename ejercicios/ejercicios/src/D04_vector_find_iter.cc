// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Igual que el ejercicio anterior (devolver la posición de la primera aparición
// de 'x' en 'v', o -1 si no está), pero el recorrido debe hacerse con
// ITERADORES en lugar de con un índice.
//
// IDEA DE SOLUCIÓN
// Un iterador es como un puntero a un elemento del vector:
//   - v.begin() apunta al primer elemento y v.end() a una posición justo después del último,
//   - ++it avanza al siguiente elemento y *it da su valor.
//
// 1. recorre:  for (auto it = v.begin(); it != v.end(); ++it)
//    ('auto' deja que el compilador deduzca el tipo del iterador),
// 2. si *it == x, la posición es la distancia desde el principio: it - v.begin()
//    (es un número con signo; conviértelo a int con static_cast<int>),
// 3. si el bucle termina sin encontrarlo, devuelve -1.
//
// EJEMPLOS
// find_iterator({5, 7, 9, 7}, 7) -> 1
// find_iterator({5, 7, 9}, 9)    -> 2
// find_iterator({5, 7, 9}, 4)    -> -1
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
int find_iterator(const vector<int>& v, int x) {
    // TODO: implementar
    return -1;
}
