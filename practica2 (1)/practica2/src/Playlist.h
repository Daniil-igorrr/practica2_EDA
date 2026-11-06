// Práctica 2 — Reproductor de música
// Plantilla: completa la declaración del TAD Playlist
// siguiendo la Sección 4 del enunciado.

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>

#include "Track.h"

using namespace std;

class Playlist {
    // friend ostream& operator<<(ostream& os, const Playlist& p);

  private:
    // La clase Node es privada: solo la Playlist puede acceder a los nodos.
    struct Node {
        Track track;
        Node* prev;
        Node* next;
        Node(const Track& t) : track(t), prev(nullptr), next(nullptr) {}
    };

    Node* head;      // primer nodo (nullptr si la lista está vacía)
    Node* tail;      // último nodo
    Node* current;   // pista "en reproducción"
    int count;       // número de pistas

    // TODO: métodos privados auxiliares que necesites

  public:
    // TODO: forma canónica (Sección 4.2)
    // TODO: métodos del TAD (Sección 4.3)
};

#endif // PLAYLIST_H
