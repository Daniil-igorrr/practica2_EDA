#!/bin/bash

# Script para preparar la entrega del examen
# Este script ejecuta las pruebas del examen (grupo X), comprime sus
# salidas en un fichero aparte y empaqueta todo (código fuente, archivos
# necesarios y salidas de los tests) en el tgz de entrega.
# Uso: ./entrega.sh

FILES="AUTHOR.txt src/Track.h src/Track.cc src/Playlist.h src/Playlist.cc src/main.cc run_tests.sh"

clear

# Comprueba si todos los archivos necesarios existen
for file in $FILES; do
    if [ ! -f "$file" ]; then
        echo ""
        echo "❌ El archivo '$file' no existe. Por favor, asegúrate de que todos los archivos necesarios estén presentes antes de ejecutar este script."
        echo ""
        exit 1
    fi
done

# Comprueba si AUTHOR.txt tiene contenido
if [ ! -s AUTHOR.txt ]; then
    echo ""
    echo "❌ El archivo AUTHOR.txt está vacío. Por favor, añade tu nombre completo y DNI."
    echo ""
    exit 1
fi

# Ejecuta las pruebas del examen (grupo X); genera informe.txt, nota.txt
# y la salida de cada prueba en tests/output/
echo ""
echo "🧪 Ejecutando las pruebas del examen (grupo X)..."
echo ""
./run_tests.sh X

# Variables
NOMBRE_PROYECTO="p2"
ARCHIVO_ENTREGA="${NOMBRE_PROYECTO}_entrega.tgz"
RESULTADOS_TESTS="resultados_tests.tgz"

# Comprime las salidas de los tests (informe, nota y salida de cada
# prueba) en un único fichero, que se incluirá en la entrega. Se excluyen
# los binarios compilados (tests/output/bin, obj, classes), que no son
# salidas de los tests y solo aumentarían el tamaño del paquete.
rm -f "$RESULTADOS_TESTS"
TESTS_OUTPUT_FILES="informe.txt tests/output"
[ -f nota.txt ] && TESTS_OUTPUT_FILES="$TESTS_OUTPUT_FILES nota.txt"
COPYFILE_DISABLE=1 tar --exclude='._*' --exclude='*/._*' \
    --exclude='tests/output/bin' --exclude='tests/output/obj' --exclude='tests/output/classes' \
    -czf "$RESULTADOS_TESTS" $TESTS_OUTPUT_FILES

# Limpiar entregas anteriores
if [ -f "$ARCHIVO_ENTREGA" ]; then
    rm "$ARCHIVO_ENTREGA"
fi

# Crear el archivo tgz incluyendo AUTHOR.txt, src y las salidas de los tests
echo ""
echo "📦 Creando el archivo de entrega..."
COPYFILE_DISABLE=1 tar --exclude='._*' --exclude='*/._*' -czf "$ARCHIVO_ENTREGA" AUTHOR.txt src/ "$RESULTADOS_TESTS"
echo ""
echo "✅ Archivo de entrega creado: $ARCHIVO_ENTREGA"
echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Recuerda subir el archivo al servidor de prácticas"
echo "  URL: https://pracdlsi.dlsi.ua.es"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo ""
