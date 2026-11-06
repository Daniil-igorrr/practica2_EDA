// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Busca en 'v' la primera aparición de 'viejo' y la sustituye por 'nuevo'.
// Modifica el vector original. Devuelve true si encontró el valor (y lo cambió)
// y false si no estaba (en ese caso el vector no cambia). Solo se cambia la
// PRIMERA aparición.
//
// IDEA DE SOLUCIÓN
// 1. recorre el vector; para poder MODIFICAR los elementos usa una referencia:
//      for (int& e : v)   // 'e' es el propio elemento, no una copia
//    (o un bucle con índice y v[i] = nuevo),
// 2. si e == viejo: asigna  e = nuevo;  y devuelve true,
// 3. al terminar el bucle, devuelve false.
//
// EJEMPLOS
// v = {5, 7, 9, 7}; replace_first(v, 7, 0) -> true;  v pasa a ser {5, 0, 9, 7}
// v = {5, 7};       replace_first(v, 4, 0) -> false; v sigue siendo {5, 7}
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
bool replace_first(vector<int>& v, int viejo, int nuevo) {
    // TODO: implementar
    return false;
}
