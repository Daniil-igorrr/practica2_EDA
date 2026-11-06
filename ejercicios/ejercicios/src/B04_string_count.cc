#include <string>
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      string_count
//   Parámetros:  un string donde buscar y un string con la subcadena a contar
//   Devuelve:    un int con el número de apariciones
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor, por referencia, constante o no), teniendo
// en cuenta que las pruebas la llaman tanto con literales ("abcabc") como con
// variables de tipo string.
//
// QUÉ DEBE HACER
// Cuenta cuántas veces aparece la subcadena dentro del texto y devuelve ese
// número.
//
// Reglas:
//   - Las apariciones NO se solapan: cuando encuentras una, sigues
//     buscando a partir de la posición en la que ella termina, no de la
//     siguiente. Por eso en "aaaa" la subcadena "aa" aparece 2 veces
//     (posiciones 0 y 2), y no 3.
//   - Si la subcadena es una cadena vacía, devuelve 0 (evita un bucle infinito).
//   - Si no aparece ninguna vez, devuelve 0.
//
// IDEA DE SOLUCIÓN
//   1. contador = 0 y pos = 0,
//   2. busca la subcadena en el texto a partir de 'pos' con s.find(sub, pos),
//   3. si lo encuentra (el resultado no es string::npos): suma 1 al
//      contador y avanza pos hasta el final de la coincidencia
//      (posición encontrada + sub.size()),
//   4. repite desde el paso 2 hasta que no encuentre más, y devuelve el
//      contador.
//
// EJEMPLOS (entrada -> salida)
//   string_count("abcabcabc", "abc") -> 3
//   string_count("aaaa", "aa")       -> 2   (no se solapan)
//   string_count("aaa", "aa")        -> 1
//   string_count("hola", "x")        -> 0
//   string_count("hola", "")         -> 0   (subcadena vacía)

// ESCRIBE TU FUNCIÓN AQUÍ
