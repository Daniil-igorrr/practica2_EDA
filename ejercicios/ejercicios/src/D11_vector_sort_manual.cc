// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Devuelve una COPIA de 'v' ordenada de menor a mayor. El vector original no
// cambia. La ordenación debe programarse a mano con bucles: NO uses sort() de
// <algorithm> (eso es el ejercicio siguiente).
//
// IDEA DE SOLUCIÓN
// Elige un algoritmo sencillo, por ejemplo burbuja o inserción, y aplícalo a la copia:
//
//   copia = v;
//   Burbuja: repite  for i = 0 .. n-2  { for j = 0 .. n-2-i {
//                si copia[j] > copia[j+1], intercámbialos } }
//   (para intercambiar dos valores puedes usar swap(copia[j], copia[j+1]) de <utility>,
//    que ya está disponible al incluir <vector>).
//
// Cuidado con vectores de tamaño 0 o 1: con size_t, 'n - 1' sería un número enorme si
// n = 0. Comprueba ese caso antes o usa comparaciones que no resten.
//
// EJEMPLOS
// sorted_manual({5, 2, 9, 1, 5}) -> {1, 2, 5, 5, 9}
// sorted_manual({1, 2, 3})       -> {1, 2, 3}
// sorted_manual({})              -> {}
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
vector<int> sorted_manual(const vector<int>& v) {
    // TODO: implementar
    return {};
}
