// CLASE Token - ejercicio F04: reservar y liberar un objeto con new y delete
//
// Este fichero (.h) es la DECLARACIÓN de la clase: dice qué atributos y métodos tiene.
// Ya viene escrito y no hay que modificarlo. Lo que hay que programar está en el
// fichero .cc de esta misma carpeta.
//
// #ifndef / #define / #endif (el "guard") evitan que el fichero se incluya dos veces
// en la misma compilación, lo que daría error de "clase redefinida".
#ifndef TOKEN_H
#define TOKEN_H

class Token {
public:
    Token(int valor);
    int value() const;

private:
    int value_;
};

// Funciones que gestionan fichas en memoria dinámica:
Token* create_token(int valor);
void destroy_token(Token* f);
int consume_token(Token* f);

#endif
