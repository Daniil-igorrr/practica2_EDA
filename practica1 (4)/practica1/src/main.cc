// Práctica 1 — Catálogo de Recursos
// Aplicación de línea de comandos (Sección 6 del enunciado).
//
// Lee comandos de la entrada estándar y escribe el resultado
// en la salida estándar, sin prompts ni mensajes adicionales.

#include <iostream>
#include <sstream>
#include <string>

#include "Catalog.h"

using namespace std;

int main() {
    Catalog catalog;
    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        string command;
        if (!(iss >> command)) {
            continue;   // línea vacía
        }

        if (command == "EXIT") {
            break;
        }

        // TODO: procesa el resto de comandos (LOAD, ADD, DEL, GET, FINDTAG)
        // Recuerda: si el comando no existe o faltan argumentos -> INVALIDCMD
    }

    return 0;
}
