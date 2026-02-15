#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float num1, num2;
    float suma, resta, multi, divi;
    int resto; // El resto de la división (módulo) solo funciona con ENTEROS

    printf("--- SUPER CALCULADORA EN C ---\n\n");

    printf("Introduce el primer numero: ");
    scanf("%f", &num1);
    printf("Introduce el segundo numero: ");
    scanf("%f", &num2);

    // OPERACIONES
    suma = num1 + num2;
    resta = num1 - num2;
    multi = num1 * num2;
    
    // OJO: Hay que tener cuidado con dividir por cero (ya lo veremos más adelante)
    divi = num1 / num2;

    // Para el resto (módulo %), necesitamos convertir a int (Casting)
    // El símbolo '%' te da lo que sobra de una división entera
    resto = (int)num1 % (int)num2;

    printf("\n--- RESULTADOS ---\n");
    printf("Suma: %.2f\n", suma);
    printf("Resta: %.2f\n", resta);
    printf("Multiplicacion: %.2f\n", multi);
    printf("Division: %.2f\n", divi);
    printf("Resto de la division entera (aprox): %d\n", resto);

    printf("\nPulsa Enter para salir");
    fflush(stdin); // Intento de limpiar el buffer (aunque a veces falla, ya sabes...)
    getchar();
    getchar();

    return 0;
}
