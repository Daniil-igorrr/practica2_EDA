// TODO: incluir la librería <vector> (para usar vector)
// TODO: incluir la librería <algorithm> (para usar sort())
// TODO: incluir la librería <functional> (para usar greater<int>)
using namespace std;

// QUÉ DEBE HACER
// Ordena el vector 'v' de MAYOR a MENOR, modificando el propio vector. Debe usarse
// la función sort de <algorithm> (para usar sort()). No devuelve nada.
//
// IDEA DE SOLUCIÓN
// sort(inicio, fin) ordena de menor a mayor el rango [inicio, fin). Para ordenar todo
// el vector se le pasan v.begin() y v.end():   sort(v.begin(), v.end());
//
// Para orden inverso se le pasa un tercer argumento, el criterio de comparación. Ya
// existe uno hecho: greater<int>() (de <functional> (para usar greater<int>)), que dice que a va antes que b
// si a > b:   sort(v.begin(), v.end(), greater<int>());
//
// EJEMPLOS
// v = {3, 1, 4, 1, 5} ; sort_desc(v) -> v pasa a ser {5, 4, 3, 1, 1}
// v = {}                ; sort_desc(v) -> {}
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
void sort_desc(vector<int>& v) {
    // TODO: implementar
}
