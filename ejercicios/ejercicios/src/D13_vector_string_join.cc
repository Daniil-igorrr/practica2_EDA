#include <string>
// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Devuelve un único string con todos los elementos del vector, en orden, separados
// por 'sep'. Es la operación contraria a tokenize. El separador solo aparece ENTRE
// elementos: ni al principio ni al final. Un vector vacío da "".
//
// IDEA DE SOLUCIÓN
// 1. crea un string vacío para el resultado,
// 2. recorre el vector con un bucle con índice,
// 3. antes de añadir cada elemento excepto el primero (i > 0), añade el separador,
// 4. añade el elemento y, al terminar, devuelve el resultado.
//
// EJEMPLOS
// join({"a", "b", "c"}, ", ")  -> "a, b, c"
// join({"solo"}, "-")         -> "solo"
// join({}, ",")               -> ""
// join({"a", "", "c"}, "/")   -> "a//c"
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
string join(const vector<string>& v, const string& sep) {
    // TODO: implementar
    return "";
}
