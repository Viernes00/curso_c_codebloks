#include <stdio.h>
#include <stdlib.h>

int main(void) // Punto de entrada del programa
{
    int edad; // Variable para almacenar un número entero (años)
    float altura; // Variable para almacenar un número decimal (metros)
    char inicial; // Variable para almacenar un solo carácter

    printf("--- EJEMPLO DE LECTURA Y IMPRESION ---\n\n");

    // LECTURA DE UN ENTERO
    printf("Introduce tu edad: ");
    // scanf pide datos al usuario. El '%d' indica que esperamos un entero.
    // El '&' es FUNDAMENTAL: le dice a scanf la dirección de memoria de la variable 'edad'.
    scanf("%d", &edad); 

    // LECTURA DE UN DECIMAL
    printf("Introduce tu altura (ejemplo: 1.75): ");
    // '%f' se usa para leer floats. De nuevo, usamos '&' para la dirección.
    scanf("%f", &altura);

    // LECTURA DE UN CARACTER
    printf("Introduce la inicial de tu nombre: ");
    // OJO: He puesto un espacio antes de '%c' (" %c").
    // Esto sirve para que scanf se salte cualquier espacio o 'Enter' que haya quedado en el teclado de antes.
    scanf(" %c", &inicial); 

    printf("\n--- DATOS REGISTRADOS ---\n");
    printf("Edad: %d anos\n", edad); // Imprimimos el entero
    printf("Altura: %.2f metros\n", altura); // '%.2f' para mostrar solo 2 decimales
    printf("Inicial: %c\n", inicial); // Imprimimos el carácter

    printf("\nPulsa Enter para terminar");
    
    // Estos getchar sirven para pausar el programa antes de que se cierre la consola
    getchar(); 
    getchar(); 

    return 0; // Fin del programa con éxito
}
