#include <stdio.h>
#include <windows.h>
#include <string.h>

/**
 * RETO: EL FORJADOR DE CADENAS (Punteros y Strings)
 *
 * En este ejercicio vamos a aprender:
 * 1. Cómo pasar un Array (String) a una función.
 * 2. Que los Arrays SIEMPRE se pasan por referencia (como punteros).
 * 3. Cómo manipular y recorrer Cadenas de Texto usando Aritmética de Punteros
 *    hasta encontrar el carácter Nulo ('\0').
 */

// Prototipos que reciben Punteros a Caracteres (char*)
int medir_longitud_hacker(char *cadena);
void convertir_a_mayusculas(char *cadena);

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Un string normal y corriente. Recuerda: "mensaje" ya es un puntero a la 'H'
    char mensaje[100] = "Hola mundo hacker";
    int longitud_real;

    printf("--- 🗡️ EL FORJADOR DE CADENAS ---\n\n");
    printf("Mensaje Original: \"%s\"\n", mensaje);

    // 1. PASANDO STRINGS A FUNCIONES
    // Al pasar "mensaje", estamos enviando la dirección de memoria de la primera letra.
    longitud_real = medir_longitud_hacker(mensaje);
    printf("Longitud medida por nuestra función: %d caracteres.\n", longitud_real);

    // 2. MODIFICANDO STRINGS A DISTANCIA
    // Como le pasamos la dirección de memoria, esta función va a alterar el array original.
    convertir_a_mayusculas(mensaje);

    printf("Mensaje Forjado : \"%s\"\n\n", mensaje);

    // Pausa Fantasma Final
    printf("[Pulsa Enter para salir]");
    fflush(stdin);
    getchar();

    return 0;
}

// ==============================================
// FUNCIONES HACKER (Implementadas con Punteros)
// ==============================================

// Función que clona el comportamiento de strlen() de <string.h>
int medir_longitud_hacker(char *cadena)
{
    int contador = 0;
    
    // El bucle lee el contenido (*cadena). Si es distinto de Nulo ('\0'), entra.
    while (*cadena != '\0') 
    {
        contador++;
        cadena++; // Avanzamos el puntero a la siguiente letra (Aritmética de Punteros)
    }
    
    return contador;
}

// Función que pasa minúsculas a MAYÚSCULAS modificando la memoria original
void convertir_a_mayusculas(char *cadena)
{
    while (*cadena != '\0')
    {
        // Si la letra actual está en el rango de minúsculas
        if (*cadena >= 'a' && *cadena <= 'z')
        {
            // En ASCII, la diferencia entre mayúscula y minúscula son exactamente 32 casillas
            *cadena = *cadena - 32; 
        }
        cadena++; // Siguiente letra
    }
}
