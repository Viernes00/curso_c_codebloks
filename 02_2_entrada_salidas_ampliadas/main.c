#include <stdio.h>
#include <windows.h>

/**
 * RETO: EL FORMATEADOR MAESTRO (Entradas y Salidas Ampliadas)
 *
 * En este ejercicio nos relajamos del nivel experto para pulir los básicos:
 * 1. Dominar printf(): Redondeo de decimales y padding (relleno de ceros).
 * 2. Dominar scanf(): Limitar la cantidad de caracteres que el usuario puede meter.
 * 3. Leer múltiples variables a la vez con un solo scanf.
 */

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Variables para el Ejemplo
    float hacker_coin = 1250.789123f;
    int id_agente = 7;
    
    char inicial1, inicial2;
    int pin_seguridad;
    
    char contraseña_corta[6]; // Caben 5 letras + el '\0'

    printf("--- 🖨️ EL FORMATEADOR MAESTRO ---\n\n");

    // ==========================================
    // PARTE 1: MAGIA CON PRINTF
    // ==========================================
    printf(">> 1. TRUCOS DE IMPRESIÓN (printf) <<\n\n");

    // Truco 1: Limitar decimales a 2 (%.2f)
    printf("Valor bruto HC : %f\n", hacker_coin);
    printf("Valor HC (x.xx) : %.2f\n", hacker_coin);

    // Truco 2: Rellenar con ceros a la izquierda (%0Xd)
    // El '4' significa que ocupará 4 espacios. El '0' que rellenará con ceros.
    printf("\nAgente bruto   : %d\n", id_agente);
    printf("Agente formateado: 00%d (A mano)\n", id_agente);
    printf("Agente Hacker    : %04d (Dinámico)\n\n", id_agente);

    // ==========================================
    // PARTE 2: MAGIA CON SCANF
    // ==========================================
    printf(">> 2. TRUCOS DE LECTURA (scanf) <<\n\n");

    // Truco 3: Leer varios datos de golpe separados por espacios o guiones
    printf("Escribe tus iniciales y PIN en formato 'A-B-1234': ");
    // Escaneamos sabiendo que en medio habrá guiones literales
    if (scanf("%c-%c-%d", &inicial1, &inicial2, &pin_seguridad) == 3)
    {
        printf("¡Datos robados! Iniciales: %c%c | PIN: %04d\n", inicial1, inicial2, pin_seguridad);
    }
    else
    {
        printf("Error: No seguiste el formato.\n");
    }

    // Limpiamos el buffer del Enter para el siguiente scanf
    while(getchar() != '\n'); 

    // Truco 4: Limitar la cantidad máxima de texto a leer (%5s)
    printf("\nEscribe una clave (Max 5 letras): ");
    // Aunque el usuario escriba 20 letras, scanf SOLO cogerá las 5 primeras
    scanf("%5s", contraseña_corta);
    
    printf("La clave guardada sin desbordar memoria es: %s\n", contraseña_corta);

    // Pausa Fantasma Final
    printf("\n[Pulsa Enter para salir]");
    fflush(stdin);
    while(getchar() != '\n'); // Limpiamos la basura extra del último scanf
    getchar();

    return 0;
}
