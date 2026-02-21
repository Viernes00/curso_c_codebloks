#include <stdio.h>
#include <string.h>
#include <windows.h>

/**
 * RETO: EL CREADOR DE PERSONAJES (Structs y Typedef)
 *
 * En este ejercicio vamos a aprender a:
 * 1. Diseñar nuestro propio tipo de dato (struct).
 * 2. Usar 'typedef' para no tener que escribir "struct" todo el rato.
 * 3. Crear variables complejas que guarden dentro múltiples valores a la vez.
 * 4. Modificar y leer esos valores usando el punto (.).
 */

// 1. DEFINICIÓN DEL STRUCT (El Molde / Blueprint)
// Creamos una "tarjeta" que puede almacenar dentro diferentes tipos de variables.
struct Personaje_Original {
    char nombre[50];
    char clase[30];
    int nivel;
    float vida_maxima;
    int poder_ataque;
};

// 2. EL TRUCO HACKER: TYPEDEF
// Escribir "struct Personaje_Original" cada vez que queremos hacer un héroe es aburrido.
// 'typedef' nos permite ponerle un Mote (Alias) a nuestro molde.
// Ahora la palabra "Heroe" es oficialmente un TIPO DE DATO (igual que int, float, char...)
typedef struct Personaje_Original Heroe;

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    printf("--- 🎲 CREADOR DE PERSONAJES RPG ---\n\n");

    // 3. CREANDO VARIABLES COMPLEJAS
    // 'p1' y 'p2' no son simples números, son Cajas Grandes que contienen todo el molde de 'Heroe'.
    Heroe p1;
    Heroe p2;

    // 4. ASIGNANDO DATOS (Modificador de Punto)
    // Usamos el PUNTO (.) para acceder a las variables internas de nuestro struct.
    
    // Para arrays de letras (Strings) usamos strcpy (String Copy) porque no podemos hacer "p1.nombre = 'Guerrero'" directamente en C.
    strcpy(p1.nombre, "Lord Viernes");
    strcpy(p1.clase, "Ciber-Paladín");
    p1.nivel = 99;
    p1.vida_maxima = 1500.5f;
    p1.poder_ataque = 300;

    // Personaje 2
    strcpy(p2.nombre, "Bob el Goblin");
    strcpy(p2.clase, "Saco de Boxeo");
    p2.nivel = 1;
    p2.vida_maxima = 50.0f;
    p2.poder_ataque = 2;

    // 5. MOSTRANDO LOS DATOS
    printf("📊 FICHAS GENERADAS:\n\n");
    
    printf(">>> PERSONAJE 1 <<<\n");
    printf("Nombre: %s\n", p1.nombre);
    printf("Clase : %s\n", p1.clase);
    printf("Lvl   : %d\n", p1.nivel);
    printf("HP    : %.1f\n", p1.vida_maxima);
    printf("ATK   : %d\n\n", p1.poder_ataque);

    printf(">>> PERSONAJE 2 <<<\n");
    printf("Nombre: %s\n", p2.nombre);
    printf("Clase : %s\n", p2.clase);
    printf("Lvl   : %d\n", p2.nivel);
    printf("HP    : %.1f\n", p2.vida_maxima);
    printf("ATK   : %d\n\n", p2.poder_ataque);

    printf("¡Pelea generada con éxito en la RAM del sistema!\n");

    // Pausa Fantasma Final
    printf("\n[Pulsa Enter para salir]");
    fflush(stdin);
    getchar();

    return 0;
}
