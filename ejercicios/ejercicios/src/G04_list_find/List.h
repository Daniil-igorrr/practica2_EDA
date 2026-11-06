// CLASE List - ejercicio G04: devolver un puntero al dato
//
// La clase List es una LISTA SIMPLEMENTE ENLAZADA de enteros. Cada elemento vive en
// un Node reservado con new; el nodo guarda el valor y un puntero 'next' al
// siguiente. El atributo head_ apunta al primero y el último tiene next == nullptr:
//
//    head_ --> [3| ]--> [5| ]--> [7|/]        (/ = nullptr)
//
// Este fichero (.h) es la DECLARACIÓN de la clase: dice qué atributos y métodos
// tiene, y es lo único que se da hecho porque es lo que usan las pruebas. Ya viene
// escrito y no hay que modificarlo. TODA la implementación la escribes tú en el
// fichero List.cc de esta misma carpeta, que llega vacío.
//
// #ifndef / #define / #endif (el "guard") evitan que el fichero se incluya dos veces
// en la misma compilación, lo que daría error de "clase redefinida".
#ifndef LIST_H
#define LIST_H

class List {
public:
    List();
    ~List();
    List(const List&) = delete;      // sin copias en este ejercicio
    List& operator=(const List&) = delete;

    int count() const;             // número de elementos
    int at(int pos) const;         // valor en la posición pos (0 si no existe)
    const int* find(int x) const;  // puntero al valor x, o nullptr
    void push_front(int x);        // inserta x al principio
    void push_back(int x);         // añade x al final

private:
    // Cada nodo guarda un valor y un puntero al siguiente (nullptr en el último).
    class Node {
    public:
        int value;
        Node* next;
        Node(int v) {
            value = v;
            next = nullptr;
        }
    };

    Node* head_;    // primer nodo (nullptr si la lista está vacía)
};

#endif
