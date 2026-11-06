#include <string>
// TODO: incluir la librería <vector> (para usar vector)
// TODO: incluir la librería <fstream> (para usar ofstream)
using namespace std;

// QUÉ DEBE HACER
// Escribe en el fichero de texto 'ruta' todas las cadenas del vector
// 'lineas', una por línea (cada una seguida de un salto de línea '\n').
// Si el fichero ya existía, su contenido anterior se sustituye. Devuelve
// true si se pudo escribir y false si no se pudo abrir el fichero (por
// ejemplo, porque la carpeta no existe).
//
// Idea de solución:
//   1. abre el fichero para escritura:   ofstream f(ruta);
//      Esto crea el fichero o lo vacía si ya existía,
//   2. si no se pudo abrir (!f), devuelve false,
//   3. recorre el vector y escribe cada elemento con el operador <<,
//      igual que con cout, añadiendo '\n' al final de cada uno,
//   4. devuelve true. El fichero se cierra solo al salir de la función.
//
// EJEMPLOS (entrada -> contenido del fichero / valor devuelto)
//   write_lines("a.txt", {"uno", "dos"})  -> a.txt contiene "uno\ndos\n"; true
//   write_lines("a.txt", {})              -> a.txt queda vacío;           true
//   write_lines("carpeta_inexistente/a.txt", {"x"}) -> no se crea nada;   false
//
// No cambies el nombre ni los parámetros de la función: las pruebas
// la llaman tal y como está declarada.
bool write_lines(const string& ruta, const vector<string>& lineas) {
    // TODO: implementar
    return false;
}
