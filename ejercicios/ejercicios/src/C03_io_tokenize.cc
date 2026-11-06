#include <string>
// TODO: incluir la librería <vector> (para usar vector)
// TODO: incluir la librería <sstream> (para usar istringstream)
using namespace std;

// QUÉ DEBE HACER
// Divide el string 's' en "tokens" (trozos) usando el carácter 'sep' como
// separador, y los devuelve en un vector<string>, en el mismo orden en que
// aparecen. El separador no forma parte de ningún token.
//
// Idea de solución: la función getline sirve también para leer de un
// stringstream, y su tercer parámetro indica en qué carácter parar:
//   1. crea un flujo a partir de 's':      istringstream iss(s);
//   2. declara un string 'token' y un vector vacío para el resultado,
//   3. repite   while (getline(iss, token, sep))   { guarda token }
//      Cada vuelta lee hasta el siguiente 'sep' (o hasta el final) y
//      el bucle termina cuando ya no queda nada por leer,
//   4. devuelve el vector.
//
// Comportamiento de getline que debes conocer (las pruebas lo comprueban):
//   - Dos separadores seguidos producen un token vacío ("").
//   - Un separador al final NO produce un token vacío final.
//   - Una cadena vacía no produce ningún token (vector vacío).
//
// EJEMPLOS (entrada -> salida)
//   tokenize("a,b,c", ',')     -> {"a", "b", "c"}
//   tokenize("uno dos", ' ')   -> {"uno", "dos"}
//   tokenize("a,,c", ',')      -> {"a", "", "c"}
//   tokenize("a,b,", ',')      -> {"a", "b"}
//   tokenize("sinseparador", ',') -> {"sinseparador"}
//   tokenize("", ',')          -> {}
//
// No cambies el nombre ni los parámetros de la función: las pruebas
// la llaman tal y como está declarada.
vector<string> tokenize(const string& s, char sep) {
    // TODO: implementar
    return {};
}
