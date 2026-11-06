#include <string>
// TODO: incluir la librería <sstream> (para usar stringstream)
using namespace std;

// QUÉ DEBE HACER
// Convierte los datos de una persona (nombre, edad y altura) en UNA sola
// cadena con el formato  nombre,edad,altura  (separados por comas, sin
// espacios).
//
// Un stringstream funciona como 'cout', pero en lugar de escribir en la
// pantalla escribe en un string interno. Idea de solución:
//   1. declara un stringstream:   stringstream ss;
//   2. escribe en él con el operador <<, igual que con cout. Los números
//      se convierten a texto solos:  ss << nombre << "," << edad << ...
//   3. obtén el texto acumulado con ss.str() y devuélvelo.
//
// La altura es un double: se escribe con el formato por defecto de <<
// (1.75 se escribe "1.75" y 2.0 se escribe "2"). No hace falta ajustar
// decimales.
//
// EJEMPLOS (entrada -> salida)
//   person_to_string("Ana", 30, 1.75)  -> "Ana,30,1.75"
//   person_to_string("Luis", 5, 1.2)   -> "Luis,5,1.2"
//   person_to_string("", 0, 0)         -> ",0,0"
//
// No cambies el nombre ni los parámetros de la función: las pruebas
// la llaman tal y como está declarada.
string person_to_string(const string& nombre, int edad, double altura) {
    // TODO: implementar
    return "";
}
