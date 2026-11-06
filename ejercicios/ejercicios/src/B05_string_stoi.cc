#include <string>
// TODO: incluir la librería <stdexcept> (para las excepciones invalid_argument y out_of_range)
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      to_int
//   Parámetros:  un string con el texto a convertir y una variable int donde dejar el
//                resultado
//   Devuelve:    un bool: true si el texto se pudo convertir a entero, false si no
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Convierte el texto a un número entero con la función stoi de <string> y lo deja en la
// variable recibida. Si la conversión falla, devuelve false y la variable NO debe
// modificarse. stoi avisa de los fallos lanzando EXCEPCIONES:
//   - invalid_argument: el texto no empieza por un número ("abc", "").
//   - out_of_range:     el número no cabe en un int ("99999999999999").
// Nota: stoi solo exige que el texto EMPIECE por un número, así que "12abc" se
// convierte en 12 (la función debe comportarse igual que stoi).
//
// IDEA DE SOLUCIÓN
// El código que puede lanzar la excepción se rodea con try y las excepciones se
// recogen con catch:
//     try {
//         int n = stoi(texto);      // si falla, salta directamente al catch
//         ... guardar n en el resultado ...
//         return true;
//     } catch (const invalid_argument&) {
//         return false;
//     } catch (const out_of_range&) {
//         return false;
//     }
// Guarda el resultado en la variable DESPUÉS de la conversión, para no modificarla
// si stoi falla.
//
// EJEMPLOS (entrada -> salida)
//   "42"              -> true,  la variable pasa a valer 42
//   "-7"              -> true,  -7
//   "12abc"           -> true,  12   (así se comporta stoi)
//   "abc"             -> false, la variable no cambia
//   ""                -> false
//   "99999999999999"  -> false  (no cabe en un int)

// ESCRIBE TU FUNCIÓN AQUÍ
