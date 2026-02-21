#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
 * RETO: CALCULADORA CIBERPUNK (Funciones y Modularidad)
 *
 * En este ejercicio vamos a aprender a:
 * 1. Declarar prototipos de funciones ANTES del main.
 * 2. Llamar funciones desde el cuerpo del programa.
 * 3. Definir las funciones DESPUÉS del main.
 * 4. Pasar parámetros por VALOR.
 * 5. Trabajar con funciones void (sin retorno) y float (con retorno).
 */

// 1. DECLARACIÓN DE PROTOTIPOS (El índice del libro)
void mostrar_menu(void);
float sumar(float a, float b);
float restar(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);

int main(void)
{
    // Caracteres especiales Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int opcion;
    float num1, num2, resultado;

    do
    {
        // 2. LLAMAR A LA FUNCIÓN (Usarla)
        mostrar_menu();
        
        printf("Elige una opción [1-5]: ");
        // Protección 1: Verificar que scanf lee realmente un número
        if (scanf("%d", &opcion) != 1)
        {
            // Limpiar el buffer del teclado de la "basura" introducida
            while (getchar() != '\n');
            printf("❌ Entrada no válida. Se ha detectado un carácter corrupto.\n");
            continue; // Volver al inicio del bucle do-while
        }

        if (opcion >= 1 && opcion <= 4)
        {
            printf("\nIntroduce el primer número: ");
            if (scanf("%f", &num1) != 1)
            {
                while (getchar() != '\n');
                printf("❌ Error al leer el número. Operación cancelada.\n");
                continue;
            }
            
            printf("Introduce el segundo número: ");
            if (scanf("%f", &num2) != 1)
            {
                while (getchar() != '\n');
                printf("❌ Error al leer el número. Operación cancelada.\n");
                continue;
            }

            switch (opcion)
            {
            case 1:
                resultado = sumar(num1, num2);
                printf("⚡ Resultado: %.2f + %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 2:
                resultado = restar(num1, num2);
                printf("⚡ Resultado: %.2f - %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 3:
                resultado = multiplicar(num1, num2);
                printf("⚡ Resultado: %.2f * %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 4:
                if (num2 != 0)
                {
                    resultado = dividir(num1, num2);
                    printf("⚡ Resultado: %.2f / %.2f = %.2f\n", num1, num2, resultado);
                }
                else
                {
                    printf("⚠️ ¡ERROR CRÍTICO! División por cero denegada por el sistema.\n");
                }
                break;
            }
            printf("\n");
        }
        else if (opcion != 5)
        {
            printf("❌ Opción no reconocida por el terminal.\n\n");
        }

    } while (opcion != 5);

    printf("\nApagando terminal... ¡Mantente offline, hacker!\n");
    
    // Pausa Fantasma Final
    printf("\n[Pulsa Enter para salir]");
    fflush(stdin);
    getchar();

    return 0;
}

// 3. DEFINICIÓN DE FUNCIONES (El contenido real)

void mostrar_menu(void)
{
    printf("\n");
    printf("================================\n");
    printf("   📟 CALCULADORA CIBERPUNK    \n");
    printf("================================\n");
    printf(" 1. Ejecutar Suma\n");
    printf(" 2. Ejecutar Resta\n");
    printf(" 3. Ejecutar Multiplicación\n");
    printf(" 4. Ejecutar División\n");
    printf(" 5. Desconectar\n");
    printf("--------------------------------\n");
}

float sumar(float a, float b)
{
    return a + b;
}

float restar(float a, float b)
{
    return a - b;
}

float multiplicar(float a, float b)
{
    return a * b;
}

float dividir(float a, float b)
{
    // Ya validamos la división entre cero en main
    return a / b;
}
