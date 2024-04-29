## Instrucciones

- Escribe las funciones que se piden en el archivo `llist.hpp`.
- Ya están los encabezados de las funciones escritos: sólo tienes que escribir el cuerpo de las mismas.
- La definición de los nodos de la lista es la siguiente:

``` C++
struct Node {
  int value;
  Node *next;
};
```

- Para probar tu programa, en la consola, escribe el comando `check`.
- Si quieres compilar y probar manualmente el programa, este es el comando que tienes que escribir para compilar:
  ```bash
  g++ main.cpp -o main
  ```
  Luego, puedes probarlo así en la consola: `./main`
- El programa `main` te permite ejecutar manualmente las funciones `push`, `insert_at_index`, `pop` y `remove_at_index`. Las otras sólo se pueden probar con `check`, aunque lo normal será que las funciones `insert_at_index` y `remove_at_index` utilicen `insert_after` y `remove_after`, respectivamente, por lo que si las primeras funcionan, las segundas también lo harán.
- Para entregar la práctica, usa el botón `Marcar como completado` que está al final de la guía.

### insert_after

Inserta el nodo apuntado por el parámetro `new_node` detrás del nodo apuntado por el parámetro `node`.

Devuelve un puntero al nodo recién insertado, o `nullptr` si `node` o `new_node` son `nullptr`.

### push

Inserta el nodo apuntado por el parámetro `new_node` al principio de la lista apuntada por el parámetro `list`. Si `new_node` es `nullptr`, no inserta nada.

En todos los casos, devuelve un puntero a lista apuntada por el parámetro `list`.

### insert_at_index

Crea un nuevo elemento con el valor `value`, y lo inserta en la posición `index` (las posiciones de los elementos se numeran desde `0`) dentro de la lista apuntada por `list`. Si la posición `index` no existe (la lista tiene menos de `index + 1` elementos), no se inserta nada.

En todos los casos, devuelve un puntero a la lista apuntada por `list`.

#### Ayuda

Puedes utilizar la función `element_at_index`, que se proporciona ya definida, para obtener un puntero al elemento que está en la posición `index - 1`, y luego usar `insert_after` para insertar el elemento detrás del elemento devuelto por `element_at_index`.

### remove_after

Elimina el elemento que está a continuación del nodo apuntado por el parámetro `node` y devuelve un puntero a dicho elemento. Si `node` es `nullptr` o no tiene un elemento siguiente, no se elimina nada, y devuelve `nullptr`.

#### Ayuda

Puedes utilizar la función `remove_at_index`, que se proporciona ya definida, para obtener un puntero al elemento que está en la posición `index - 1`, y luego usar `remove_after` para eliminar el elemento detrás del elemento devuelto por `element_at_index`.

### pop

Elimina el primer elemento de la lista apuntada por `list`, y devuelve un puntero al elemento eliminado. Si la lista está vacía, no elimina nada, y devuelve `nullptr`.

### remove_at_index

Elimina el elemento de la lista apuntada por `list` que se encuentra en la posición `index` (las posiciones se numeran empezando en `0`). Devuelve un puntero al elemento eliminado. Si no existe la posición `index`, no se elimina nada y devuelve `nullptr`.
