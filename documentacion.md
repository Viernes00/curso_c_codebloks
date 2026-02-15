# 🎓 Curso de Lenguaje C - Documentación del Hacker

¡Bienvenido a tu manual de referencia, pisha! Aquí tienes resumido todo lo que hemos montado y aprendido hasta ahora.

---

## 🛠️ 1. Entorno de Desarrollo (Build System)

Hemos configurado un sistema profesional en VS Code que imita a los grandes IDEs like Code::Blocks.

### Estructura de Carpetas

Cada proyecto debe tener esta estructura:

- `Proyecto/`
  - `main.c`: Tu código fuente.
  - `.vscode/tasks.json`: El "molde" de compilación.
  - `obj/`: Aquí van los archivos `.o` (código máquina intermedio).
  - `bin/Debug/`: Aquí va el delicioso `.exe` final.

### Cómo Compilar

1. Abre el archivo `.c` que quieras compilar.
2. Pulsa `Ctrl + Shift + B`.
3. Elige **"Build C (Professional Structure)"**.
4. Ejecuta el programa desde la terminal: `./bin/Debug/main.exe`.

---

## 🧠 2. Conceptos de C Aprendidos

### Variables y Tipos

- `int`: Números enteros.
- `float` / `double`: Números con decimales (usa `float n = 5.0f`).
- `char`: Un solo carácter ('A').
- `long long`: Números astronómicos.
- `unsigned`: Números solo positivos (llegan más alto).

### Entrada y Salida

- `printf("Formato", variable)`: Imprimir en pantalla.
- `scanf("%d", &variable)`: Leer del teclado. **¡IMPORTANTE el `&`!**

### Control de Flujo

- **Condicionales (`if` / `else`)**: Para tomar decisiones.
- **Bucle `while`**: Repite "mientras" se cumpla una condición.
- **Bucle `for`**: Repite un número fijo de veces (ideal para tablas o conteos).

---

## 🧙‍♂️ 3. Trucos Pro de Hacker

### El Parche de Caracteres Especiales (Windows)

Para que los acentos y la `¡` salgan bien, añade esto al principio de tu `main`:

```c
#include <windows.h>
// ... dentro de main ...
SetConsoleOutputCP(CP_UTF8);
SetConsoleCP(CP_UTF8);
```

### El Fantasma del Buffer

Si el programa se cierra solo, usa dos `getchar()` al final. El primero se come el "Enter" residual del teclado y el segundo pausa la consola.

### El Archivo `.o` (Objeto)

Es código máquina ya traducido pero sin "enlazar" con las bibliotecas externas. El Linker lo coge y crea el `.exe`.

---

## 🎲 4. Reto del Hacker: Aleatoriedad

Para crear juegos o programas impredecibles, usamos la generación de números aleatorios.

### Conceptos Clave

- **`#include <time.h>`**: Necesaria para obtener la hora del sistema.
- **`srand(time(NULL))`**: Inicializa la "semilla". Hazlo una sola vez al principio del `main` para que los números cambien en cada partida.
- **`rand() % 100 + 1`**:
  - `rand()`: Genera un número enorme al azar.
  - `% 100`: Limita el número entre 0 y 99.
  - `+ 1`: Ajusta el rango para que sea de 1 a 100.

---

## 📊 5. Arrays (Arreglos / Listas)

Los arrays permiten guardar múltiples valores del mismo tipo bajo un solo nombre.

### Puntos clave

- **Declaración**: `int notas[5];` reserva espacio para 5 números.
- **Índices**: Empezamos siempre en **0**. Las posiciones serían: `0, 1, 2, 3, 4`.
- **Acceso**: `notas[0] = 10;` guarda un 10 en la primera posición.
- **Bucle FOR**: Es la herramienta perfecta para recorrer arrays (pedir datos o imprimirlos).

---

¡A seguir dándole caña al código! 🚀🦾
