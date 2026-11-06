// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Elimina de 'v' los elementos repetidos, dejando solo la PRIMERA aparición de cada
// valor y conservando el orden original. Modifica el vector original (no
// devuelve nada).
//
// IDEA DE SOLUCIÓN
// Una forma sencilla: construir un vector auxiliar con los valores sin repetir.
// 1. crea  vector<int> sin_repetidos;
// 2. para cada elemento e de v, comprueba si ya está en sin_repetidos (recorriéndolo
//    con un bucle, o con find de <algorithm>); si NO está, añádelo con push_back,
// 3. al final asigna el resultado al original:   v = sin_repetidos;
//
// EJEMPLOS
// v = {1, 2, 1, 3, 2, 1} -> v pasa a ser {1, 2, 3}
// v = {4, 4, 4}          -> {4}
// v = {1, 2, 3}          -> {1, 2, 3}   (sin duplicados, no cambia)
// v = {}                 -> {}
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
void remove_duplicates(vector<int>& v) {
    // TODO: implementar
}
