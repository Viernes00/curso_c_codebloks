#include <stdio.h>
#include <string.h>
#include <windows.h>

/**
 * RETO: DESCIFRADOR DE MENSAJES (Cadenas / Strings)
 *
 * En este ejercicio vamos a aprender a:
 * 1. Declarar y usar arrays de caracteres (strings).
 * 2. Recorrer una cadena carácter a carácter.
 * 3. Aplicar un cifrado César (desplazar letras).
 * 4. Usar funciones de <string.h> como strlen().
 */

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char mensaje[100];
    int desplazamiento;
    int longitud;
    int i;

    printf("--- 🔐 DESCIFRADOR CÉSAR ---\n\n");
    printf("Escribe un mensaje (solo letras minúsculas, sin acentos):\n> ");
    fgets(mensaje, 100, stdin);

    // Eliminar el salto de línea que mete fgets
    longitud = (int)strlen(mensaje);
    if (longitud > 0 && mensaje[longitud - 1] == '\n')
    {
        mensaje[longitud - 1] = '\0';
        longitud--;
    }

    printf("¿Cuántas posiciones desplazar? (1-25): ");
    scanf("%d", &desplazamiento);

    // Asegurar que el desplazamiento esté en rango
    desplazamiento = desplazamiento % 26;

    printf("\n--- PROCESO DE CIFRADO ---\n");
    printf("Original:  \"%s\"\n", mensaje);

    // Cifrado César: desplazar cada letra
    for (i = 0; i < longitud; i++)
    {
        if (mensaje[i] >= 'a' && mensaje[i] <= 'z')
        {
            // Desplazar dentro del rango a-z
            mensaje[i] = (char)(((mensaje[i] - 'a' + desplazamiento) % 26) + 'a');
        }
        else if (mensaje[i] >= 'A' && mensaje[i] <= 'Z')
        {
            mensaje[i] = (char)(((mensaje[i] - 'A' + desplazamiento) % 26) + 'A');
        }
        // Los espacios y números se quedan igual
    }

    printf("Cifrado:   \"%s\"\n", mensaje);

    // Descifrar (invertir el desplazamiento)
    for (i = 0; i < longitud; i++)
    {
        if (mensaje[i] >= 'a' && mensaje[i] <= 'z')
        {
            mensaje[i] = (char)(((mensaje[i] - 'a' - desplazamiento + 26) % 26) + 'a');
        }
        else if (mensaje[i] >= 'A' && mensaje[i] <= 'Z')
        {
            mensaje[i] = (char)(((mensaje[i] - 'A' - desplazamiento + 26) % 26) + 'A');
        }
    }

    printf("Descifrado: \"%s\"\n", mensaje);

    printf("\n✅ ¡Cifrado y descifrado completados!\n");

    printf("\nPulsa Enter para salir");
    fflush(stdin);
    getchar();

    return 0;
}
