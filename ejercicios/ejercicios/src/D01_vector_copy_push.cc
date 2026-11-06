// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Devuelve un vector NUEVO que contiene los mismos elementos que 'v' y, al final,
// el valor 'x'. El vector original 'v' no debe cambiar.
//
// 'v' llega como 'const vector<int>&': no se puede modificar, así que hay que
// trabajar sobre una copia.
//
// IDEA DE SOLUCIÓN
// 1. haz una copia:            vector<int> copia = v;
// 2. añade 'x' al final:        copia.push_back(x);
// 3. devuelve la copia.
//
// EJEMPLOS
// with_element({1, 2, 3}, 4) -> {1, 2, 3, 4}   (y v sigue siendo {1, 2, 3})
// with_element({}, 5)        -> {5}
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
vector<int> with_element(const vector<int>& v, int x) {
    // TODO: implementar
    return {};
}
