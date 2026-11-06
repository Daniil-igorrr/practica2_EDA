#include <string>
// TODO: incluir la librería <vector> (para usar vector)
// TODO: incluir la librería <fstream> (para usar ifstream)
using namespace std;

// QUÉ DEBE HACER
// Lee el fichero de texto cuya ruta es 'ruta' y devuelve sus líneas en un
// vector<string>, en orden, sin el salto de línea ('\n') final de cada una.
// Si el fichero no existe o no se puede abrir, devuelve un vector vacío.
//
// Idea de solución:
//   1. abre el fichero para lectura y comprueba si se abrió correctamente
//   2. declara un string 'linea' y un vector vacío para el resultado,
//   3. lee línea a línea en un bucle que termine al llegar al final del
//      fichero, añadiendo cada línea leída al vector
//   4. devuelve el vector. El fichero se cierra solo al salir de la función.
//
// Detalles (las pruebas los comprueban):
//   - Las líneas vacías del fichero se devuelven como "" (no se saltan).
//   - Da igual que la última línea termine o no en salto de línea.
//
// EJEMPLOS (contenido del fichero -> salida)
//   "uno\ndos\ntres\n"   -> {"uno", "dos", "tres"}
//   "uno\n\ntres"        -> {"uno", "", "tres"}
//   "" (fichero vacío)   -> {}
//   (el fichero no existe) -> {}
//
// No cambies el nombre ni los parámetros de la función: las pruebas
// la llaman tal y como está declarada.
vector<string> read_lines(const string& ruta) {
    // TODO: implementar
    return {};
}
