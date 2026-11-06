// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Devuelve un vector NUEVO con los elementos de 'v' que son estrictamente MAYORES
// que 'umbral', en el mismo orden. El vector original no cambia.
//
// IDEA DE SOLUCIÓN
// 1. crea un vector vacío para el resultado,
// 2. recorre 'v' (for (int e : v)),
// 3. si e > umbral, añádelo al resultado con push_back,
// 4. devuelve el resultado.
//
// EJEMPLOS
// filter_greater({1, 5, 3, 8, 2}, 3) -> {5, 8}   (el 3 no es mayor que 3)
// filter_greater({1, 2}, 5)          -> {}
// filter_greater({}, 0)              -> {}
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
vector<int> filter_greater(const vector<int>& v, int umbral) {
    // TODO: implementar
    return {};
}
