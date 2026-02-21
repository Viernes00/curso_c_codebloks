#include <stdio.h>
#include <windows.h>

/**
 * RETO: EL HACKER DE ARRAYS (Punteros y Aritmética)
 *
 * En este ejercicio vamos a aprender:
 * 1. La verdad oculta: Un Array es en realidad un Puntero.
 * 2. Cómo recorrer un Array sin usar índices (Aritmética de Punteros).
 * 3. Modificar datos de un Array apuntando directamente a la RAM.
 */

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. EL ARRAY NORMAL
    // Cada elemento (int) ocupa 4 bytes en memoria (normalmente).
    int contrasenas[5] = {10, 20, 30, 40, 50};
    
    // 2. EL PUNTERO
    // ¡Ojo al dato! El nombre de un array ("contrasenas") YA ES un puntero 
    // a su primer elemento (&contrasenas[0]).
    int *puntero = contrasenas;

    printf("--- 🕵️‍♂️ EL HACKER DE ARRAYS ---\n\n");
    
    printf("Posición en memoria del Array: %p\n", (void*)contrasenas);
    printf("Posición del primer elemento : %p\n\n", (void*)&contrasenas[0]);
    // Verás que las direcciones de arriba coinciden.

    // 3. RECORRER EL ARRAY AL ESTILO HACKER (Aritmética de Punteros)
    printf("Leyendo contraseñas saltando por la RAM:\n");
    for (int i = 0; i < 5; i++)
    {
        // En vez de usar contrasenas[i], usamos la aritmética de punteros
        // *(puntero + i) avanza "i" bloques de memoria del tipo int en la RAM
        printf("Posición %d (RAM: %p) = %d\n", i, (void*)(puntero + i), *(puntero + i));
    }

    printf("\n--- 💥 HACKEANDO EL SISTEMA ---\n");
    // Modificamos el tercer valor (el 30) saltando directamente por la RAM
    *(puntero + 2) = 9999;
    
    printf("El tercer valor ha sido corrompido.\n");
    printf("Nuevo valor en contrasenas[2]: %d\n\n", contrasenas[2]); // Debería salir 9999

    // Pausa Fantasma Final
    printf("[Pulsa Enter para salir]");
    fflush(stdin);
    getchar();

    return 0;
}
