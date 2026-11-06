#include <string>
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      trim_until
//   Parámetros:  un string y un carácter (char)
//   Devuelve:    un int con la posición donde estaba el carácter, o -1
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Busca la primera aparición del carácter en el texto.
//   - Si la encuentra: elimina del texto original todo lo que hay hasta ese
//     carácter, INCLUIDO el carácter, y devuelve la posición (desde 0) donde estaba.
//   - Si no la encuentra: no modifica el texto y devuelve -1.
//
// La función hace dos cosas a la vez: modifica el argumento Y devuelve un valor.
//
// IDEA DE SOLUCIÓN
// El texto debe recibirse por referencia (string&) para poder modificarlo.
// 1. busca el carácter con texto.find(c) (devuelve string::npos si no está),
// 2. si no está, devuelve -1,
// 3. si está en la posición p, quédate con lo que hay después:
//      texto = texto.substr(p + 1);
//    y devuelve p (convertido a int).
//
// EJEMPLOS
// string s = "clave=valor"; int p = trim_until(s, '=');   -> p vale 5 y s vale "valor"
// string t = "sinigual"; int q = trim_until(t, '=');       -> q vale -1 y t sigue valiendo "sinigual"

// ESCRIBE TU FUNCIÓN AQUÍ
