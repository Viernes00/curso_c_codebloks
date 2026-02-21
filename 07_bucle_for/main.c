#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int i; // Variable de control del bucle

    printf("--- EL BUCLE FOR (PARA) ---\n\n");

    // La ventaja del FOR es que pone todo lo importante en una sola línea:
    // 1. Inicialización (i = 1)
    // 2. Condición (i <= 10)
    // 3. Incremento (i++)
    printf("Tabla del 7:\n");
    for (i = 1; i <= 10; i++)
    {
        printf("7 x %d = %d\n", i, 7 * i);
    }

    printf("\nPodemos contar hacia atras tambien:\n");
    for (i = 10; i >= 1; i--)
    {
        printf("%d... ", i);
    }
    printf("¡IGNICIÓN!\n");

    printf("\nPulsa Enter para salir");
    fflush(stdin);
    getchar();
    getchar();

    return 0;
}
