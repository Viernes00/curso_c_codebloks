#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Para los caracteres especiales en Windows

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int contador = 1;
    int limite;

    printf("--- EL BUCLE WHILE (MIENTRAS) ---\n\n");

    printf("¿Hasta qué número quieres contar? ");
    scanf("%d", &limite);

    printf("\n¡Empezamos la cuenta!\n");

    // El bucle WHILE se repite MIENTRAS la condición sea verdadera.
    // OJO: Si la condición siempre es verdadera, tendrás un BUCLE INFINITO.
    while (contador <= limite)
    {
        printf("Número: %d\n", contador);

        // ¡FUNDAMENTAL! Hay que cambiar algo para que la condición acabe siendo falsa.
        // Aquí incrementamos el contador en 1 cada vez.
        // contador = contador + 1; // Forma larga
        contador++; // Forma corta de hacker (incremento)
    }

    printf("\n¡Hecho! He contado hasta %d.\n", limite);

    printf("\nPulsa Enter para salir");
    fflush(stdin);
    getchar();
    getchar();

    return 0;
}
