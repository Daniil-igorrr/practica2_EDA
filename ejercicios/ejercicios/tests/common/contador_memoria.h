// Cuenta las reservas y liberaciones de memoria dinámica:
//   - g_bloques_array:  new[] / delete[]   (arrays)
//   - g_bloques_objeto: new   / delete     (objetos sueltos, p. ej. nodos)
// Se incluye UNA sola vez, en el fichero de la prueba. Permite comprobar en las
// pruebas que una clase libera la memoria que reserva, sin depender de valgrind.
//
// Uso: long antes = g_bloques_objeto; ... crear/destruir objetos ...;
//      long despues = g_bloques_objeto;  y comparar. Guarda los contadores en
//      variables ANTES de usar CHECK, porque doctest también reserva memoria.
//      Dentro de la zona medida no uses string ni vector (reservan memoria
//      con new y alterarían la cuenta).
#ifndef CONTADOR_MEMORIA_H
#define CONTADOR_MEMORIA_H

#include <cstddef>
#include <cstdlib>
#include <new>

static long g_bloques_array = 0;
static long g_bloques_objeto = 0;

void* operator new[](std::size_t n) {
    void* p = std::malloc(n == 0 ? 1 : n);
    if (p == nullptr) {
        throw std::bad_alloc();
    }
    ++g_bloques_array;
    return p;
}

void operator delete[](void* p) noexcept {
    if (p != nullptr) {
        --g_bloques_array;
        std::free(p);
    }
}

void* operator new(std::size_t n) {
    void* p = std::malloc(n == 0 ? 1 : n);
    if (p == nullptr) {
        throw std::bad_alloc();
    }
    ++g_bloques_objeto;
    return p;
}

void operator delete(void* p) noexcept {
    if (p != nullptr) {
        --g_bloques_objeto;
        std::free(p);
    }
}

#endif
