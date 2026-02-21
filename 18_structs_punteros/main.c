#include <stdio.h>
#include <string.h>
#include <windows.h>

/**
 * RETO: EL HEREDERO DE LA FLECHA (Punteros + Structs)
 *
 * En este ejercicio vamos a aprender a:
 * 1. Pasar un Struct entero a una función usando Punteros (Paso por Referencia).
 * 2. Por qué no debemos pasar Structs por valor (Copia masiva de memoria = Lento).
 * 3. Usar el operador "Flecha" (->) para modificar datos de un Struct a distancia.
 */

// 1. EL MOLDE Y SU ALIAS
typedef struct {
    char nombre[50];
    int nivel;
    float vida_maxima;
    int poder_ataque;
} Heroe;

// 2. PROTOTIPOS LAS FUNCIONES HACKER
// ¡Fíjate bien! En lugar de "Heroe h", recibimos un PUNTERO al héroe: "Heroe *h"
void subir_nivel(Heroe *pj);
void curar_heroe(Heroe *pj, float cantidad);

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    printf("--- 🏹 EL HEREDERO DE LA FLECHA ---\n\n");

    // 3. CREAMOS AL RECLUTA
    Heroe recluta;
    strcpy(recluta.nombre, "Lord Viernes");
    recluta.nivel = 1;
    recluta.vida_maxima = 100.0f;
    recluta.poder_ataque = 15;

    printf("[ESTADO INICIAL]\n");
    printf("Héroe: %s | Nivel: %d | Vida: %.1f | Ataque: %d\n\n", 
           recluta.nombre, recluta.nivel, recluta.vida_maxima, recluta.poder_ataque);

    // 4. INVOCAMOS LA MAGIA DE LOS PUNTEROS
    // Como la función pide la dirección de memoria (*pj), nosotros le 
    // pasamos la llave de nuestro recluta (&recluta).
    printf("Entrenando en la Sala del Tiempo (Pasando Referencia)...\n");
    subir_nivel(&recluta);

    printf("Bebiendo Poción Curativa...\n");
    curar_heroe(&recluta, 50.0f);

    printf("\n[ESTADO TRAS EL ENTRENAMIENTO]\n");
    printf("Héroe: %s | Nivel: %d | Vida: %.1f | Ataque: %d\n\n", 
           recluta.nombre, recluta.nivel, recluta.vida_maxima, recluta.poder_ataque);

    // Pausa Fantasma Final
    printf("[Pulsa Enter para salir]");
    fflush(stdin);
    getchar();

    return 0;
}

// ==============================================
// 5. EL OPERADOR FLECHA (->)
// ==============================================

// Como 'pj' es un PUNTERO a un Struct (no es el Struct en sí), 
// C prohíbe usar el punto (pj.nivel).
// En su lugar, usamos la Flecha (pj->nivel) para "Caminar por el puntero y acceder al dato".
void subir_nivel(Heroe *pj)
{
    pj->nivel += 1;
    pj->vida_maxima += 25.0f;
    pj->poder_ataque += 10;
}

void curar_heroe(Heroe *pj, float cantidad)
{
    pj->vida_maxima += cantidad;
}
