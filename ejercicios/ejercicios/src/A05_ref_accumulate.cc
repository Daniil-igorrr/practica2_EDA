
// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      add_to_total
//   Parámetros:  un double con el valor a sumar y un double con el total acumulado
//   Devuelve:    nada (void)
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor o por referencia, constantes o no) según lo
// que la función debe hacer; las pruebas la llaman siempre con variables.
//
// QUÉ DEBE HACER
// Suma el valor al total acumulado, MODIFICANDO el total: tras varias llamadas
// seguidas, el total contiene la suma de todos los valores. El valor a sumar no
// debe cambiar.
//
// IDEA DE SOLUCIÓN
// El total debe ser una referencia (double&) para que cada llamada actualice la
// misma variable. El valor a sumar solo se lee, así que basta con pasarlo por valor.
// La suma con asignación (+=) hace el trabajo en una línea.
//
// EJEMPLOS
// double total = 0; add_to_total(0.5, total); add_to_total(1.25, total);   -> total vale 1.75

// ESCRIBE TU FUNCIÓN AQUÍ
