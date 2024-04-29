## Instrucciones

- Escribe las funciones que se piden en el archivo `hex.hpp`.
- Para probar tu programa, en la consola, escribe el comando `check`.
- Si quieres compilar y probar manualmente el programa, este es el comando que tienes que escribir para compilar:
  ```bash
  g++ main.cpp -o main
  ```
  Luego, puedes probarlo así en la consola: `./main`
- Para entregar la práctica, usa el botón `Marcar como completado` que está al final de la guía.

## Convertir de hexadecimal a decimal

**Escribe una función que convierta a decimal el número hexadecimal pasado como argumento.**

- Nombre de la función: `hex2dec`.
- Parámetros:
  - el número hexadecimal que hay que convertir (tipo `string`);
- Tipo devuelto: `int`.

Escribe la definición dentro del archivo `hex.hpp`. No tienes que escribir el código necesario para leer la entrada ni para escribir la salida en el terminal.

La función debe admitir los dígitos hexadecimales tanto en minúsculas (`a`, `b`, `c`, `d`, `e`, `f`) como en mayúsculas (`A`, `B`, `C`, `D`, `E`, `F`).

### Ejemplo

_Sentencia_: `cout << hex2dec("a3");`

_Salida_: `163`

### Restricciones

- Sólo debes modificar el archivo `hex.hpp`.

### Ayuda

Escribe un bucle que recorra los caracteres del /string/ de entrada (el único parámetro). En una variable de tipo `int`, inicializada con el valor `0`, ve sumando los valores correspondientes a cada dígito (carácter) del número de entrada (el `string`). El valor de cada dígito depende de su posición. El contador que utilices para recorrer el `string` te dirá la posición, y con ella podrás calcular el valor correspondiente al dígito. El valor de un dígito $x$ es igual a dicho dígito multiplicado por una potencia de $16$ cuyo exponente es la posición, pero numerando las posiciones desde la derecha, y empezando en $0$. Un manera de "numerar" las posiciones desde la derecha es usar como posición la diferencia entre la longitud del `string` y la posición desde la izquierda. Por ejemplo (no es código C++ correcto):

```bash
string entrada {"56"};
int valor = entrada[0] * 16^(1 - 0) + entrada[1] * 16^(1 - 1) = 5 * 16^1 + 6 * 16^0 = 96
```

En general, el valor de un dígito sería `entrada[i] * 16^(entrada.size() - 1 - i)`.

Recuerda que no existe el operador /potencia/ o /exponenciación/ en C++. Por lo tanto, será conveniente definir una función que calcule potencias.

Otra opción sería recorrer el bucle en sentido inverso: desde el último elemento hasta el primero:

```C++
for (int i = entrada.size() - 1; i >= 0; i--) {
...
}
```

Para obtener los valores de los dígitos (el valor del dígito en sí, independiente de la posición), puedes usar una sentencia `if`, o, mejor, crear una /tabla/ implementada por un mapa, que relacione cada dígito con su valor. Por ejemplo, `{{'0', 0}, {'1', 1}, ..., {'a', 10}, {'b', 11},... {'A', 10}, {'B', 11},...}`. De esta forma, en la expresión que calcula el valor del dígito, en lugar de `entrada[i]`, habría que escribir `mapa[entrada[i]]`.

## Convertir de decimal a hexadecimal

**Define una función que convierta un número natural decimal a hexadecimal.**

- Nombre de la función: `dec2hex`.
- Parámetros:
  - el número decimal que hay que convertir (tipo `int`).
- Tipo devuelto: `string`.

Escribe la función dentro del archivo `hex.hpp`. No tienes que escribir el código necesario para leer la entrada ni para escribir la salida en el terminal.

Puedes usar letras minúsculas o mayúsculas para los dígitos hexadecimales.

### Ejemplo

_Sentencia_: `cout << dec2hex(100);`

_Salida_: `64` 

### Restricciones

- Sólo debes modificar el archivo `hex.hpp`.

### Ayuda

El proceso para convertir de decimal a hexadecimal es similar al que nos permitía convertir un número decimal en binario: divisiones sucesivas. La diferencia es sólo que en este caso dividiremos sucesivamente entre 16 e iremos añadiendo los restos al resultado.

La complicación es que los restos son de tipo `int`, y el resultado es un `string`, cuyos elementos son de tipo `char`. Así que, antes de añadir los restos al resultado hay que convertirlos en `char`. Una forma de hacerlo es con una sentencia `if`. Otra opción sería crear un vector de `char`, en el que colocamos cada /dígito/ en la posición correspondiente a su valor decimal. Por ejemplo, `{'0', '1', '2',..., 'a',...}`. Así, lo que tenemos que añadir al resultado es `vector[resto]`.

Recuerda que los restos se añaden en orden inverso al orden en que se obtienen. Una forma de resolver este problema es añadir los restos de esta manera: `resultado = vector[resto] + resultado`.

## Observación

En realidad, C++ permite trabajar directamente con números hexadecimales (y también binarios). Cuando escribimos un número entero (un /literal/) podemos escribirlo en hexadecimal, simplemente comenzando con `0x` (y en binario, comenzando con `ob`). Por ejemplo,

```C++
int d = 123;
int h = 0xa2f;
int b = 0b110011;
```

Sin embargo, tanto `cin` como `cout` utilizan, por defecto, el sistema decimal.
