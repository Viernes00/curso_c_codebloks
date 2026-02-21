#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Necesario para configurar la consola en Windows

int main(void)
{
    // Configuramos la consola para que entienda caracteres especiales (UTF-8)
    // Esto arregla los problemas con los acentos y la '¡'
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int edad;

    printf("--- CONTROL DE ACCESO (IF/ELSE) ---\n\n");

    printf("Introduce tu edad: ");
    // Acuérdate del & para el scanf, ¡no se te olvide!
    scanf("%d", &edad);

    // ESTRUCTURA CONDICIONAL
    // En los paréntesis va la condición: 'edad >= 18'
    if (edad >= 18)
    {
        // Esto se ejecuta SOLAMENTE si la condición es VERDADERA
        printf("¡Bienvenido al club! Eres mayor de edad.\n");
        printf("Disfruta de la fiesta con responsabilidad.\n");
    }
    else if (edad >= 15)
    {
        // Esto se mira solo si lo de arriba fue FALSO.
        // Si tienes entre 15 y 17, entras aquí.
        printf("Casi eres adulto, pero todavia no puedes entrar.\n");
        printf("Te faltan %d anos para la mayoria de edad.\n", 18 - edad);
    }
    else
    {
        // Esto es el "paracaídas": se ejecuta si todo lo anterior falló
        printf("Lo siento, eres demasiado joven. ¡A dormir!\n");
    }

    printf("\nPulsa Enter para salir");
    
    // El truco de los dos getchar para que no se cierre la consola
    fflush(stdin); 
    getchar();
    getchar();

    return 0;
}
