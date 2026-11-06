#include <string>
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      rotate_three
//   Parámetros:  tres string
//   Devuelve:    nada (void)
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Rota el contenido de tres variables string: la primera pasa a tener lo que tenía
// la segunda, la segunda lo que tenía la tercera, y la tercera lo que tenía la
// primera. Los cambios deben verse en las variables originales.
//
// IDEA DE SOLUCIÓN
// Los tres parámetros deben ser referencias (string&).
// Antes de sobrescribir nada, guarda en una variable temporal el valor que se va a
// perder (el de la primera), y luego asigna en orden:
//     temporal = a;  a = b;  b = c;  c = temporal;
//
// EJEMPLOS
// string x = "uno", y = "dos", z = "tres"; rotate_three(x, y, z);
//    -> x vale "dos", y vale "tres" y z vale "uno"

// ESCRIBE TU FUNCIÓN AQUÍ
