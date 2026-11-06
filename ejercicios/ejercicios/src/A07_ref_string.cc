#include <string>
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      append_suffix
//   Parámetros:  dos string: el texto y el sufijo
//   Devuelve:    nada (void)
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Añade el sufijo al final del texto, MODIFICANDO la variable original del que
// llama. No devuelve nada. El sufijo no debe cambiar.
//
// IDEA DE SOLUCIÓN
// El texto debe recibirse por referencia (string&) para poder cambiar el original.
// Después basta con  texto += sufijo;
// Para el sufijo, que solo se lee, puedes usar una referencia constante (const string&),
// que evita copiarlo y garantiza que no se modifica.
//
// EJEMPLOS
// string s = "hola"; string suf = "_1"; append_suffix(s, suf);   -> s vale "hola_1"
// append_suffix(s, suf);   -> s vale "hola_1_1"

// ESCRIBE TU FUNCIÓN AQUÍ
