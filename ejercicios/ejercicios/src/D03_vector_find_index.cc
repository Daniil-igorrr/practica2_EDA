// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Busca el valor 'x' en el vector 'v' y devuelve la posición (índice, desde 0)
// de su PRIMERA aparición. Si no está, devuelve -1.
//
// El recorrido debe hacerse con un bucle con índice (for con i = 0, 1, 2...).
//
// IDEA DE SOLUCIÓN
// 1. recorre las posiciones:   for (size_t i = 0; i < v.size(); i++)
// 2. compara el elemento de esa posición (v[i]) con x,
// 3. si son iguales, devuelve i inmediatamente (return corta la función),
// 4. al terminar el bucle sin haber devuelto nada, devuelve -1.
//
// EJEMPLOS
// find_index({5, 7, 9, 7}, 7) -> 1   (hay dos, se devuelve la primera)
// find_index({5, 7, 9}, 5)    -> 0
// find_index({5, 7, 9}, 4)    -> -1
// find_index({}, 1)           -> -1
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
int find_index(const vector<int>& v, int x) {
    // TODO: implementar
    return -1;
}
