#include <string>
// TODO: incluir la librería <sstream> (para usar istringstream)
using namespace std;

// QUÉ DEBE HACER
// Extrae de una línea de texto los datos de una persona: nombre (string),
// edad (int) y altura (double). Los tres valores vienen separados por
// espacios, por ejemplo "Ana 30 1.75".
//
// Los resultados se devuelven por los parámetros 'nombre', 'edad' y
// 'altura', que son REFERENCIAS (&): lo que les asignes dentro de la
// función lo verá quien llamó. La función devuelve además un bool:
// true si se pudieron leer los tres datos, false si no.
//
// Un stringstream también se puede usar para LEER, igual que cin. Idea de
// solución:
//   1. crea un flujo a partir de la línea:   istringstream iss(linea);
//   2. lee con el operador >>, que salta los espacios y convierte el texto
//      al tipo de la variable de destino
//   3. cada lectura devuelve 'true' si tuvo éxito y 'false' si falló (por
//      ejemplo, se esperaba un número y había letras, o la línea se acabó
//      antes de tiempo)
//
// EJEMPLOS (entrada -> salida)
//   linea = "Ana 30 1.75"        -> true;  nombre="Ana", edad=30, altura=1.75
//   linea = "  Luis   5   1.2 "  -> true;  nombre="Luis", edad=5, altura=1.2
//   linea = "Ana treinta 1.75"   -> false (la edad no es un número)
//   linea = "Ana 30"             -> false (falta la altura)
//   linea = ""                   -> false
//
// No cambies el nombre ni los parámetros de la función: las pruebas
// la llaman tal y como está declarada.
bool string_to_person(const string& linea, string& nombre, int& edad, double& altura) {
    // TODO: implementar
    return false;
}
