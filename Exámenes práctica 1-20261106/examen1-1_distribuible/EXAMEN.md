# Examen práctico — Práctica 1 (Propuesta 1): Renombrado de etiquetas

**Duración máxima: 1 h 45 min.** Sin Internet ni asistentes de IA.

Dispones de:

- Tu implementación de la práctica 1.
- Las 16 pruebas completas de la práctica.
- Las 10 pruebas del grupo **X** correspondientes a este examen.
- Seminario de C++ en [https://www.dlsi.ua.es/asignaturas/eda/seminario-c++-parte1.pdf](https://www.dlsi.ua.es/asignaturas/eda/seminario-c++-parte1.pdf)
- Copia del manual de referencia de C++ en [https://www.dlsi.ua.es/asignaturas/eda/cpp](https://www.dlsi.ua.es/asignaturas/eda/cpp)

Ejecuta `./run_tests.sh X` para ejecutar las pruebas del examen y ver tu calificación.

## Ampliación: renombrar etiquetas

Con el tiempo, las etiquetas del catálogo quedan obsoletas y es necesario
renombrarlas de forma masiva (por ejemplo, `cpp` pasa a llamarse
`cplusplus`).

Todos los métodos de esta ampliación son **añadidos**: no puedes cambiar ninguna
firma de la práctica (los grupos A, B y C deben seguir pasando). Recuerda declarar
los métodos nuevos en `Resource.h` y `Catalog.h`.

### 1. Método `Resource::renameTag`

```cpp
bool renameTag(const string& oldTag, const string& newTag);
```

- Normaliza `oldTag` a minúsculas (sin ninguna otra transformación, igual
  que `removeTag`).
- Normaliza `newTag` con las mismas reglas que `addTag` (recorte de
  espacios, minúsculas, caracteres válidos).
- Si el recurso **no** contiene `oldTag`: devuelve `false`.
- Si `newTag` no es una etiqueta válida: devuelve `false` y el recurso no
  se modifica.
- Si ambas etiquetas normalizadas son **iguales**: devuelve `false` (no hay
  nada que renombrar).
- En caso contrario: elimina `oldTag` y añade `newTag` **si no estaba ya**:
  - Si `newTag` ya existía sólo hay que eliminar `oldTag` y se considera que el cambio es correcto.
  - Si `newTag` no existía, se elimina `oldTag` y se crea la nueva etiqueta, manteniendo el vector ordenado   lexicográficamente.
  
Devuelve `true` si se ha hecho el cambio correctamente o `false` en caso contrario.

### 2. Método `Catalog::renameTag`

```cpp
vector<string> renameTag(const string& oldTag, const string& newTag, int minYear);
```

- Aplica el renombrado (con las reglas de `Resource::renameTag`) **solo** a
  los recursos cuyo `year` sea mayor o igual que `minYear`. Los recursos con
  `year < minYear` no se modifican, aunque contengan `oldTag`.
- Devuelve los `id` de los recursos efectivamente **modificados**, ordenados
  **lexicográficamente** (no en el orden en que aparecen en el catálogo).

### 3. Comando `RETAG <old> <new> <year>`

- Si no se modifica ningún recurso: imprime `OK 0`.
- Si se modifica al menos uno: imprime `OK <n> <id1>,<id2>,...,<idN>`, donde
  `n` es el número de recursos modificados y los ids van ordenados
  lexicográficamente y separados por comas sin espacios.
- Si faltan argumentos: `INVALIDCMD`.

Ejemplo:

```
LOAD data/sample_ok.txt
OK 6
RETAG craft artesania 1995
OK 1 bk01
FINDTAG artesania
COUNT 1
bk01 (1999) Clean Code [artesania,software]
```

(`bk04` también tiene `craft`, pero es de 1994, anterior a `minYear=1995`,
así que no se renombra.)

## Evaluación

- Nota = número de pruebas pasadas.
- El código debe compilar sin errores ni warnings.
- No se puede modificar la carpeta `tests/`.
