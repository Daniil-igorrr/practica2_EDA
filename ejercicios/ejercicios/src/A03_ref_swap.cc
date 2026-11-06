
// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      swap_ints
//   Parámetros:  dos int
//   Devuelve:    nada (void)
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Intercambia los valores de las dos variables recibidas: después de la llamada,
// la primera contiene lo que tenía la segunda y viceversa. Los cambios deben verse
// en las variables originales del que llama.
//
// IDEA DE SOLUCIÓN
// Ambos parámetros deben ser referencias (int&).
// Para intercambiar necesitas una variable temporal que guarde uno de los valores:
//     int temporal = a; a = b; b = temporal;
// (La librería <utility> tiene swap(a, b), pero aquí se trata de hacerlo a mano.)
//
// EJEMPLOS
// int x = 1, y = 2; swap_ints(x, y);   -> x vale 2 e y vale 1

// ESCRIBE TU FUNCIÓN AQUÍ
