// QUÉ DEBE HACER
// La memoria dinámica se reserva con new y se libera con delete. Todo objeto creado con
// new debe borrarse EXACTAMENTE una vez: si no se borra hay una fuga de memoria, y si
// se borra dos veces el programa falla (doble liberación).
//
// Implementa las tres funciones declaradas en Token.h (la clase ya está hecha):
//   1. Token* create_token(int valor): crea una Token en memoria dinámica y devuelve el
//      puntero a ella.
//   2. void destroy_token(Token* f): libera la ficha apuntada. Si f es nullptr no hace
//      nada (borrar nullptr es válido, pero conviene tenerlo presente).
//   3. int consume_token(Token* f): devuelve el valor de la ficha y la libera. Debe
//      leer el valor ANTES de borrarla (usar un objeto después del delete es un error).
//
// IDEA DE SOLUCIÓN
//   create_token:     return new Token(valor);
//   destroy_token:  delete f;
//   consume_token:  int v = f->value();  delete f;  return v;
//
// EJEMPLOS
//   Token* f = create_token(7);   // f apunta a una ficha nueva con valor 7
//   f->value()                   -> 7
//   destroy_token(f);           // memoria liberada; f ya no debe usarse
//   Token* g = create_token(3);
//   int v = consume_token(g);   // v vale 3 y la ficha está liberada
//
// No cambies los nombres ni las firmas de la clase y sus métodos: las pruebas los usan tal y como están declarados.
#include "Token.h"

Token::Token(int valor) {
    value_ = valor;
}

int Token::value() const {
    return value_;
}

Token* create_token(int valor) {
    // TODO: implementar
    return nullptr;
}

void destroy_token(Token* f) {
    // TODO: implementar
}

int consume_token(Token* f) {
    // TODO: implementar
    return 0;
}
