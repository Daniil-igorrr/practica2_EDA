#include <string>
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      reversed
//   Parámetros:  un string
//   Devuelve:    un string con los caracteres en orden inverso
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Devuelve una copia del texto con los caracteres en orden inverso. El texto
// original NO debe cambiar.
//
// IDEA DE SOLUCIÓN
// La función solo necesita LEER el texto. Para leer un string sin copiarlo y sin poder
// modificarlo por error, se pasa por referencia constante (const string&).
// 1. crea un string vacío para el resultado,
// 2. recorre el texto original de atrás hacia delante,
// 3. añade cada carácter al resultado,
// 4. devuelve el resultado.
// (Alternativa: copiar el texto y darle la vuelta con reverse de <algorithm>.)
//
// EJEMPLOS
// string s = "abc"; reversed(s)   -> "cba"   (s sigue valiendo "abc")
// reversed("")   -> ""

// ESCRIBE TU FUNCIÓN AQUÍ
