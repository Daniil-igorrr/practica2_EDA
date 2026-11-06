
// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      increment
//   Parámetros:  un int
//   Devuelve:    nada (void)
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Suma 1 a la variable que recibe, MODIFICÁNDOLA: el cambio debe verse en la
// variable original del que llama. No devuelve nada.
//
// IDEA DE SOLUCIÓN
// Para que la función pueda cambiar la variable original, el parámetro debe ser una
// REFERENCIA: se declara añadiendo & al tipo (int& n). Entonces n no es una copia
// sino otro nombre para la misma variable.
//
// EJEMPLOS
// int x = 5; increment(x);   -> x vale 6
// increment(x); increment(x);   -> x vale 8

// ESCRIBE TU FUNCIÓN AQUÍ
