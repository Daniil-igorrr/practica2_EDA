#include <string>
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      string_remove
//   Parámetros:  un string con el texto original y un carácter (char) a eliminar
//   Devuelve:    un string con el texto sin ese carácter
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor, por referencia, constante o no), teniendo
// en cuenta que las pruebas la llaman tanto con literales ("banana") como con
// variables de tipo string.
//
// QUÉ DEBE HACER
// Devuelve una COPIA del texto en la que se han eliminado todas las apariciones
// del carácter indicado. El resto de caracteres se conservan en el mismo orden.
// El string original NO debe quedar modificado.
//
// IDEA DE SOLUCIÓN
//   1. crea un string vacío para el resultado,
//   2. recorre el texto original carácter a carácter,
//   3. añade al resultado (con += o push_back) solo los caracteres que sean
//      distintos del que hay que eliminar,
//   4. devuelve el resultado.
//
// EJEMPLOS (entrada -> salida)
//   string_remove("banana", 'a')     -> "bnn"
//   string_remove("hola mundo", ' ') -> "holamundo"
//   string_remove("abc", 'z')        -> "abc"   (no hay ninguna 'z')
//   string_remove("aaa", 'a')        -> ""      (se elimina todo)
//   string_remove("", 'a')           -> ""

// ESCRIBE TU FUNCIÓN AQUÍ
