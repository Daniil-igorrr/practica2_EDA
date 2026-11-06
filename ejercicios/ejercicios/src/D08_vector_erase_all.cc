// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Elimina de 'v' TODAS las apariciones de 'x' y devuelve cuántas eliminó (0 si no
// había ninguna). Modifica el vector original y conserva el orden del resto.
//
// IDEA DE SOLUCIÓN
// El problema típico: erase invalida el iterador, y si además haces ++it te saltas
// el siguiente elemento (o lo pierdes). erase devuelve un iterador al elemento que
// ha quedado en la posición eliminada, así que se usa ese valor:
//
//      auto it = v.begin();
//      while (it != v.end()) {
//          if (*it == x) { it = v.erase(it); cuenta++; }   // NO avanzar
//          else          { ++it; }                          // solo avanzar si no se borra
//      }
//
// (Alternativa avanzada: el 'idiom erase-remove' con std::remove de <algorithm>.)
//
// EJEMPLOS
// v = {1, 2, 1, 3, 1}; erase_all(v, 1) -> 3; v pasa a ser {2, 3}
// v = {1, 1, 2};       erase_all(v, 1) -> 2; v pasa a ser {2}   (consecutivos)
// v = {1, 2};          erase_all(v, 5) -> 0; v sigue igual
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
int erase_all(vector<int>& v, int x) {
    // TODO: implementar
    return 0;
}
