#include <string>
// TODO: incluir la librería <vector> (para usar vector)
using namespace std;

// QUÉ DEBE HACER
// Devuelve el string más largo (más caracteres) del vector. Si hay varios con la
// misma longitud máxima, devuelve el PRIMERO de ellos. Si el vector está vacío,
// devuelve "".
//
// IDEA DE SOLUCIÓN
// 1. si el vector está vacío, devuelve "",
// 2. guarda el primer elemento como candidato: string mejor = v[0];
// 3. recorre el resto; si algún elemento tiene size() MAYOR que el del candidato,
//    pasa a ser el candidato (con > estricto, en un empate se queda el primero),
// 4. devuelve el candidato.
//
// EJEMPLOS
// longest({"sol", "elefante", "gato"})  -> "elefante"
// longest({"ab", "cd", "e"})             -> "ab"     (empate: el primero)
// longest({})                          -> ""
//
// No cambies el nombre ni los parámetros de la función: las pruebas la llaman tal y como está declarada.
string longest(const vector<string>& v) {
    // TODO: implementar
    return "";
}
