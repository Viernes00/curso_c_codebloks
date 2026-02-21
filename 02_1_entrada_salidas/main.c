#include <stdio.h>
#include <stdlib.h>

int main(void) // Cambiado 'main()' por 'main(void)' para cumplir con el estándar moderno (evita el warning de prototipo)
{
    int numero = 5; // Variable entera estándar
    // float numer_real = 5.6789; // Original: causaba warning porque 5.6789 se interpreta como double (64 bits)
    float numer_real = 5.6789f; // Añadida 'f' al final para indicar que es un valor float (32 bits) y evitar pérdida de precisión
    
    char letra = 't'; // Variable de un solo carácter
    char cadena_de_letras[] = "varias palabras juntas en un texto"; // Array de caracteres (cadena de texto)
    
    // double numero64bits = -1589632651145223; // Original: causaba warning porque no se usaba en ninguna parte
    double numero64bits = -1589632651145223.0; // Cambiado a double con decimal para claridad, la usaremos abajo
    
    // --- MÁS TIPOS DE VARIABLES PARA TENER EN CUENTA ---
    
    short pequeno = 32767; // Entero corto (normalmente 16 bits). Rango pequeño.
    long long gigante = 9223372036854775807LL; // Entero extra largo (64 bits). Para números astronómicos.
    unsigned int positivo = 4000000000U; // Entero sin signo. Solo valores positivos, pero llega al doble de alto que un 'int' normal.
    
    // En C99 y superiores, se usa <stdbool.h> para booleanos, pero aquí te enseño la forma clásica:
    int es_verdad = 1; // En C, 0 es Falso y cualquier otra cosa (normalmente 1) es Verdadero.

    printf("Esta variable %d imprime numeros\n",numero); // %d se usa para enteros (int)
    printf("Esta variable imprime numeros decimales  %f\n",numer_real); // %f se usa para decimales (float/double)
    printf("Esta variable imprime solo un caracter %c\n",letra); // %c se usa para un solo carácter (char)
    printf("Esta variable una cadena de texto %s\n",cadena_de_letras); // %s se usa para cadenas de texto (string)
    printf("El numero de 64 bits es: %f\n", numero64bits); // Usamos %f aunque sea double
    
    // Mostrando los nuevos tipos:
    printf("Short (corto): %hd\n", pequeno); // %hd para short
    printf("Long Long (gigante): %lld\n", gigante); // %lld para long long
    printf("Unsigned (solo positivo): %u\n", positivo); // %u para unsigned int
    printf("¿Es verdad? (Booleano): %d\n", es_verdad); // Se imprime como entero
    
    printf("Pulsa Enter para continuar");
    getchar();
    return 0;
}
