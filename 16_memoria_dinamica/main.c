#include <stdio.h>
#include <stdlib.h> // IMPRESCINDIBLE para malloc() y free()
#include <windows.h>

/**
 * RETO: EL LADRÓN DE RAM (Memoria Dinámica)
 *
 * En este ejercicio vamos a aprender:
 * 1. Qué es la Memoria Dinámica (Stack vs Heap).
 * 2. pedilre RAM al Sistema Operativo en tiempo de ejecución usando malloc().
 * 3. Devolver la memoria al Sistema Operativo usando free() para no crear memory leaks.
 */

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int cant_bots;
    int *escuadron_bots = NULL; // Puntero nulo por seguridad inicial

    printf("--- 🤖 CREADOR DE BOTNETS (Memoria Dinámica) ---\n\n");
    
    // Hasta ahora, los arrays tenían que tener un tamaño fijo: int array[5];
    // Pero, ¿qué pasa si no sabemos cuántos necesitaremos hasta que el usuario lo dice?
    printf("¿Cuántos bots necesitas para el ataque DDoSS?: ");
    if (scanf("%d", &cant_bots) != 1 || cant_bots <= 0)
    {
        while(getchar() != '\n');
        printf("Error: Cantidad no válida.\n");
        return 1; // Salir con error
    }

    printf("\n[SISTEMA] Solicitando memoria RAM al Sistema Operativo...\n");

    // 1. ASIGNACIÓN DINÁMICA (malloc = Memory Allocation)
    // Le decimos: "Oye SO, dame memoria equivalente a (cant_bots multiplicado por el tamaño de un int)"
    // El SO nos devuelve la DIRECCIÓN de memoria (un puntero) donde nos ha reservado ese espacio.
    escuadron_bots = (int *)malloc((size_t)cant_bots * sizeof(int));

    // Validar SIEMPRE que el Sistema nos ha dado la memoria (A veces no hay RAM libre)
    if (escuadron_bots == NULL)
    {
        printf("\n[ERROR CRÍTICO] Falta memoria RAM. Sistema Operativo denegó el acceso.\n");
        return 1;
    }

    printf("[SISTEMA] ¡Memoria asignada con éxito en la dirección: %p!\n\n", (void*)escuadron_bots);

    // 2. USO DEL ARRAY DINÁMICO
    // Como escuadron_bots es un puntero a esa memoria, lo podemos usar EXACTAMENTE igual que un array
    for (int i = 0; i < cant_bots; i++)
    {
        // Asignamos una ID a cada bot (ej: ID 1000, 1001, 1002...)
        escuadron_bots[i] = 1000 + i; 
        printf("Bot %d montado y operativo. ID: %d\n", i + 1, escuadron_bots[i]);
    }

    printf("\n[SISTEMA] Ataque completado. Destruyendo Botnet...\n");

    // 3. LIBERACIÓN DE MEMORIA (free)
    // TODO lo que pides con malloc, TIENES que borrarlo con free().
    // Si no lo haces y cierras el programa, tendrás una FUGA DE MEMORIA (Memory Leak).
    free(escuadron_bots);
    
    // Buena práctica hacker: apuntar el puntero a NULL una vez liberado
    escuadron_bots = NULL; 

    printf("[SISTEMA] Memoria RAM devuelta al SO de forma segura.\n\n");

    // Pausa Fantasma Final
    printf("[Pulsa Enter para salir]");
    fflush(stdin);
    getchar();
    getchar();

    return 0;
}
