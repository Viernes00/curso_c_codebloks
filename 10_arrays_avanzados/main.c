#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
 * RETO: HACKER STATS (Arrays Avanzados)
 * 
 * En este ejercicio vamos a aprender a:
 * 1. Recorrer un array para encontrar el valor máximo.
 * 2. Recorrer un array para encontrar el valor mínimo.
 * 3. Calcular la media aritmética de los elementos.
 * 4. Gestionar un número fijo de entradas.
 */

int main(void)
{
    // Configuración para caracteres especiales en Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int num_datos = 5;
    int datos[5];
    int i;
    int maximo, minimo;
    int suma = 0;
    float media;

    printf("--- 📊 HACKER STATS: ANALIZADOR DE DATOS ---\n\n");
    printf("Por favor, introduce %d números enteros:\n", num_datos);

    // 1. Lectura de datos
    for (i = 0; i < num_datos; i++)
    {
        printf("Dato [%d]: ", i + 1);
        scanf("%d", &datos[i]);
    }

    // 2. Inicialización de los extremos
    // ¡TRUCO DE HACKER! Asumimos que el primer elemento es tanto
    // el más grande como el más pequeño temporalmente.
    maximo = datos[0];
    minimo = datos[0];
    suma = datos[0];

    // 3. Algoritmo de búsqueda de Máximo, Mínimo y Suma
    for (i = 1; i < num_datos; i++)
    {
        // Si encontramos un número mayor al que creíamos el máximo...
        if (datos[i] > maximo)
        {
            maximo = datos[i];
        }

        // Si encontramos un número menor al que creíamos el mínimo...
        if (datos[i] < minimo)
        {
            minimo = datos[i];
        }

        // Acumulamos para la media
        suma += datos[i];
    }

    // 4. Calcular la media
    media = (float)suma / (float)num_datos;

    // 5. Mostrar resultados
    printf("\n--- 📈 RESULTADOS DEL ANÁLISIS ---\n");
    printf("Lista completa: ");
    for (i = 0; i < num_datos; i++)
    {
        printf("[%d] ", datos[i]);
    }

    printf("\n\n✅ El valor MÁXIMO encontrado es: %d", maximo);
    printf("\n❌ El valor MÍNIMO encontrado es: %d", minimo);
    printf("\n📊 La MEDIA aritmética es: %.2f\n", media);

    printf("\nPulsa Enter para salir");
    fflush(stdin);
    getchar();
    getchar();

    return 0;
}
