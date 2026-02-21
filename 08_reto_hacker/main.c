#include <stdio.h>
#include <stdlib.h>
#include <time.h>    // Necesaria para generar números aleatorios
#include <windows.h> // Para corregir caracteres en Windows

int main(void)
{
    // 1. Configuración inicial
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 2. Semilla para el número aleatorio (usa la hora actual)
    srand((unsigned int)time(NULL));

    // 3. Variables del juego
    int numero_secreto = rand() % 100 + 1; // Genera un número entre 1 y 100
    int intento_usuario;
    int intentos_realizados = 0;
    const int MAX_INTENTOS = 7; // El límite de intentos

    printf("--- 🕵️ RETo DEL HACKER: ADIVINA EL NÚMERO --- \n\n");
    printf("He pensado un número entre 1 y 100.\n");
    printf("Tienes %d intentos para descubrirlo. ¡Suerte!\n\n", MAX_INTENTOS);

    // 4. Bucle principal del juego
    // Se repite mientras no lo adivines y te queden intentos
    while (intentos_realizados < MAX_INTENTOS)
    {
        printf("Intento #%d: Introduce tu número: ", intentos_realizados + 1);
        scanf("%d", &intento_usuario);
        intentos_realizados++;

        if (intento_usuario == numero_secreto)
        {
            printf("\n🎉 ¡BRUTAL! ¡Lo has hackeado! El número era el %d.\n", numero_secreto);
            printf("Lo has conseguido en solo %d intentos.\n", intentos_realizados);
            break; // Rompemos el bucle porque ya hemos ganado
        }
        else if (intento_usuario < numero_secreto)
        {
            printf("❌ DEMASIADO BAJO. El número es mayor.\n\n");
        }
        else
        {
            printf("❌ DEMASIADO ALTO. El número es menor.\n\n");
        }

        // Si es el último intento y no hemos ganado...
        if (intentos_realizados == MAX_INTENTOS)
        {
            printf("\n💀 GAME OVER. Te has quedado sin intentos.\n");
            printf("El número secreto era el %d. ¡Mejor suerte la próxima!\n", numero_secreto);
        }
    }

    printf("\nPulsa Enter para salir");
    fflush(stdin);
    getchar();
    getchar();

    return 0;
}
