#include <string>
// TODO: incluir la librería <cctype> (para usar tolower())
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      string_tolower
//   Parámetros:  un string con el texto original
//   Devuelve:    un string con el texto convertido a minúsculas
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar el parámetro (por valor, por referencia, constante o no); las
// pruebas la llaman siempre con variables de tipo string.
//
// QUÉ DEBE HACER
// Devuelve una COPIA del texto con todas las letras convertidas a minúsculas.
// El resto de caracteres (espacios, dígitos, signos) no cambian. El string
// original NO debe quedar modificado.
//
// IDEA DE SOLUCIÓN
//   1. haz una copia del texto original,
//   2. recorre la copia con un bucle accediendo a cada carácter posición a posición
//   3. asigna a cada carácter tolower(c) (la función tolower de <cctype>
//      convierte una letra mayúscula en minúscula, si recibe otro carácter lo devuelve sin modificar),
//   4. devuelve la copia.
//
// EJEMPLOS (entrada -> salida)
//   string_tolower("PASAR a minUSCUlas") -> "pasar a minusculas"
//   string_tolower("Hola Mundo 123")     -> "hola mundo 123"
//   string_tolower("ya en minusculas")   -> "ya en minusculas"
//   string_tolower("")                   -> ""

// ESCRIBE TU FUNCIÓN AQUÍ
