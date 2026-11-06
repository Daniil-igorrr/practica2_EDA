#include <string>
using namespace std;

// FUNCIÓN QUE HAY QUE ESCRIBIR
//   Nombre:      string_find
//   Parámetros:  un string donde buscar y un string con la subcadena a buscar
//   Devuelve:    un int con la posición de la primera aparición, o -1
// Las pruebas la llaman con este nombre, así que respétalo. Decide tú cómo
// declarar los parámetros (por valor, por referencia, constante o no), teniendo
// en cuenta que las pruebas la llaman tanto con literales ("hola") como con
// variables de tipo string.
//
// QUÉ DEBE HACER
// Busca la subcadena dentro del texto y devuelve la posición (índice, empezando
// a contar desde 0) donde empieza su PRIMERA aparición. Si no aparece,
// devuelve -1.
//
// Se puede resolver de dos maneras (elige una):
//   a) Con el método de string s.find(sub). Devuelve string::npos cuando
//      no encuentra nada; en ese caso hay que devolver -1. Ojo: npos no
//      es -1, así que compara con string::npos.
//   b) A mano: para cada posición i posible del texto, comprueba si los
//      sub.size() caracteres que empiezan en i son iguales a la subcadena
//      (por ejemplo con s.compare(i, sub.size(), sub) == 0, o con un
//      bucle interior). Si coinciden, devuelve i. Al terminar el bucle
//      sin coincidencias, devuelve -1.
//
// EJEMPLOS (entrada -> salida)
//   string_find("hola mundo", "mundo") -> 5   ("mundo" empieza en la posición 5)
//   string_find("abcabc", "bc")        -> 1   (hay dos, se devuelve la primera)
//   string_find("abc", "abc")          -> 0
//   string_find("abc", "xyz")          -> -1  (no aparece)
//   string_find("abc", "abcd")         -> -1  (la subcadena es más larga que el texto)

// ESCRIBE TU FUNCIÓN AQUÍ
