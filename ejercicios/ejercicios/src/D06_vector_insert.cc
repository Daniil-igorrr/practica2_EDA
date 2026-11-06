// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Inserta el valor 'x' en la posición 'pos' de 'v' (contando desde 0), desplazando
// una posición a la derecha los elementos que había desde ahí. Modifica el vector
// original. Si 'pos' es mayor que el tamaño del vector, se inserta al final.
//
// IDEA DE SOLUCIÓN
// v.insert(iterador, valor) inserta 'valor' justo ANTES de la posición que
// señala el iterador. Para señalar la posición 'pos' suma al iterador del inicio:
//      v.insert(v.begin() + pos, x);
//
// Antes, comprueba si pos > v.size(); en ese caso usa pos = v.size() (que equivale
// a insertar al final: v.begin() + v.size() es v.end()).
//
// EJEMPLOS
// v = {1, 2, 3}; insert_at(v, 1, 9)  -> v pasa a ser {1, 9, 2, 3}
// v = {1, 2, 3}; insert_at(v, 0, 9)  -> {9, 1, 2, 3}
// v = {1, 2, 3}; insert_at(v, 3, 9)  -> {1, 2, 3, 9}
// v = {1, 2, 3}; insert_at(v, 10, 9) -> {1, 2, 3, 9}   (posición fuera de rango)
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
void insert_at(vector<int>& v, size_t pos, int x) {
    // TODO: implementar
}
