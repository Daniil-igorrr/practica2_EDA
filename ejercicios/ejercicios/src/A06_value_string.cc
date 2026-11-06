#include <string>
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      with_suffix
//   Parámetros:  dos string: el texto y el sufijo
//   Devuelve:    un string con el texto seguido del sufijo
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Devuelve el texto con el sufijo añadido al final. Las variables originales del
// que llama (texto y sufijo) NO deben cambiar.
//
// IDEA DE SOLUCIÓN
// Si recibes el texto por valor, el parámetro es una copia local del string: puedes
// añadirle el sufijo directamente (con +=) y devolverla, sin tocar el original.
//
// EJEMPLOS
// string s = "hola"; string suf = "_1";
// with_suffix(s, suf) -> "hola_1"      (s sigue valiendo "hola")

// ESCRIBE TU FUNCIÓN AQUÍ
