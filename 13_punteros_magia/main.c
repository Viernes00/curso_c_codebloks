#include <stdio.h>
#include <windows.h>

/**
 * RETO: EL TRILERO DE LA MEMORIA (Punteros)
 *
 * En este ejercicio vamos a aprender:
 * 1. Qué es una dirección de memoria (&).
 * 2. Qué es un puntero (*).
 * 3. Cómo modificar el valor de una variable desde otra función (Paso por Referencia).
 */

// Prototipo de la función Hacker que intercambia valores reales modificando la RAM.
// Fíjate que recibe PUNTEROS (direcciones), no valores normales.
void truco_del_trilero(int *moneda_izq, int *moneda_der);

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. LAS VARIABLES NORMALES
    int mano_izquierda = 100; // Tiene 100 euros
    int mano_derecha = 0;     // No tiene nada

    printf("--- 🎩 EL TRUCO DEL TRILERO ---\n\n");
    printf("ESTADO INICIAL:\n");
    printf("Mano Izquierda: %d€\n", mano_izquierda);
    printf("Mano Derecha: %d€\n\n", mano_derecha);

    // 2. MOSTRANDO LAS DIRECCIONES DE MEMORIA (&)
    // Con %p imprimimos en formato Hexadecimal la dirección física de la RAM.
    printf("¿Dónde están guardadas en la RAM?\n");
    printf("Dirección de Mano Izq: %p\n", (void*)&mano_izquierda);
    printf("Dirección de Mano Der: %p\n\n", (void*)&mano_derecha);

    printf("Realizando el truco de magia... (Pasando referencias)\n\n");
    
    // 3. LA LLAMADA PASANDO REFERENCIAS (&)
    // No le pasamos el "numero 100", le pasamos la UBICACIÓN de la caja "mano_izquierda".
    truco_del_trilero(&mano_izquierda, &mano_derecha);

    printf("ESTADO FINAL MAGIA:\n");
    printf("Mano Izquierda: %d€\n", mano_izquierda);
    printf("Mano Derecha: %d€\n\n", mano_derecha);

    printf("¡El dinero se ha teletransportado saltándose el scope de la función!\n");

    // Pausa Fantasma
    printf("\n[Pulsa Enter para salir]");
    fflush(stdin);
    getchar();

    return 0;
}

// 4. LA FUNCIÓN CON PUNTEROS (*)
// Al poner * delante, C sabe que lo que recibe son direcciones de memoria de otras cajas,
// y cuando lo usamos (*moneda_izq = ...), estamos abriendo esa caja y cambiando su contenido a distancia.
void truco_del_trilero(int *moneda_izq, int *moneda_der)
{
    // CUIDADO: Necesitamos una caja temporal para no perder el dinero al sobrescribirlo.
    int temporal;

    // 1. Guardamos el dinero de la izq en la caja temporal
    temporal = *moneda_izq;
    
    // 2. Metemos el dinero de la derecha en la caja izquierda
    *moneda_izq = *moneda_der;
    
    // 3. Metemos el dinero guardado en la caja temporal a la caja derecha
    *moneda_der = temporal;
}
