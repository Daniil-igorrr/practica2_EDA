// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Busca la primera aparición de 'x' en 'v' y la elimina del vector (los elementos
// siguientes se desplazan una posición a la izquierda). Devuelve true si eliminó
// algo y false si 'x' no estaba (el vector no cambia).
//
// IDEA DE SOLUCIÓN
// v.erase(iterador) elimina el elemento al que apunta el iterador.
// 1. recorre con iteradores:  for (auto it = v.begin(); it != v.end(); ++it)
// 2. si *it == x: v.erase(it);  y devuelve true (después de erase, 'it' deja de
//    ser válido, por eso no se sigue recorriendo: se sale con return),
// 3. al terminar el bucle, devuelve false.
//
// EJEMPLOS
// v = {1, 2, 3, 2}; erase_first(v, 2) -> true;  v pasa a ser {1, 3, 2}
// v = {1, 2, 3};    erase_first(v, 9) -> false; v sigue siendo {1, 2, 3}
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
bool erase_first(vector<int>& v, int x) {
    // TODO: implementar
    return false;
}
