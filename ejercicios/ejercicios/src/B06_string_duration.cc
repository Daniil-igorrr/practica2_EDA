#include <string>
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      format_duration
//   Parámetros:  un int con una duración en segundos
//   Devuelve:    un string con la duración en formato m:ss
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar el parámetro (por valor o por referencia, constante o no) según lo que la
// función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Convierte un número de segundos en texto "minutos:segundos":
//   - los segundos siempre con DOS cifras (0:05, 1:00),
//   - los minutos sin relleno y sin límite (65:00 para 3900 segundos: no se pasa a horas).
// Si el número es negativo, se trata como 0 ("0:00").
//
// IDEA DE SOLUCIÓN
//   1. calcula los minutos y los segundos usando los operadores necesarios
//   2. convierte a texto con to_string(...)  (de <string>): to_string(5) -> "5",
//   3. si el resto es menor que 10, añade un "0" delante para tener dos cifras,
//   4. devuelve  minutos + ":" + resto  como string.
// (Otra opción: un stringstream con setw(2) y setfill('0') de <iomanip>; en ese caso
// añade los #include necesarios.)
//
// EJEMPLOS (entrada -> salida)
//   0     -> "0:00"
//   5     -> "0:05"
//   60    -> "1:00"
//   187   -> "3:07"
//   3900  -> "65:00"
//   -4    -> "0:00"

// ESCRIBE TU FUNCIÓN AQUÍ
