#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. Declaración de un Array (una lista de 5 números enteros)
    int notas[5];
    int i;
    float suma = 0;
    float media;

    printf("--- GESTIÓN DE NOTAS (ARRAYS) ---\n\n");

    // 2. Llenar el Array usando un bucle FOR
    for (i = 0; i < 5; i++)
    {
        printf("Introduce la nota del alumno %d: ", i + 1);
        scanf("%d", &notas[i]);
        suma += notas[i]; // Vamos sumando para luego hacer la media
    }

    // 3. Mostrar los datos guardados
    printf("\n--- RESULTADOS ---\n");
    printf("Notas introducidas: ");
    for (i = 0; i < 5; i++)
    {
        printf("[%d] ", notas[i]);
    }

    // 4. Calcular y mostrar la media
    media = suma / 5;
    printf("\n\nLa nota media de la clase es: %.2f\n", media);

    // 5. Ejemplo de acceso directo
    printf("La primera nota fue: %d\n", notas[0]);
    printf("La última nota fue: %d\n", notas[4]);

    printf("\nPulsa Enter para salir");
    fflush(stdin);
    getchar();
    getchar();

    return 0;
}
