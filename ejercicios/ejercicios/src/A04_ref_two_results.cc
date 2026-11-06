
// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      divide
//   Parámetros:  cuatro int: dividendo, divisor, y dos variables donde dejar cociente y resto
//   Devuelve:    nada (void)
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Divide dos números enteros y deja el cociente y el resto de la división entera
// en las dos últimas variables recibidas (que el que llama lee después). Un return
// solo puede devolver UN valor; para "devolver" dos se usan parámetros de salida.
// Los dos primeros parámetros (dividendo y divisor) no deben cambiar.
// Si el divisor es 0, deja cociente y resto a 0.
//
// IDEA DE SOLUCIÓN
// Los parámetros de salida deben ser referencias (int&): al asignarles un valor, se
// escribe en las variables del que llama. Con el operador / se obtiene el cociente y
// con % el resto.
//
// EJEMPLOS
// int c, r; divide(17, 5, c, r);   -> c vale 3 y r vale 2
// int c, r; divide(20, 4, c, r);   -> c vale 5 y r vale 0
// int c, r; divide(9, 0, c, r);    -> c vale 0 y r vale 0

// ESCRIBE TU FUNCIÓN AQUÍ
