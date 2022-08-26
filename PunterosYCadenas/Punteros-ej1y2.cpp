/*
1) Declarar una variable entera, un vector de caracteres de diez posiciones y una variable con
soporte de decimales y ...
a) Asignarle valores.
b) Imprimir el valor de cada una.
c) Imprimir la dirección de memoria de cada una.

2) Declarar una variable que sea puntero a un número entero y luego ...
a) Imprimir por pantalla la dirección de memoria.
b) Imprimir su valor.
c) Asignar dinámicamente espacio en memoria.
d) Imprimir nuevamente su valor.
e) Imprimir el valor que se encuentra en el espacio asignado dinámicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;

int main()
{

    // PUNTO 1
    int entero;
    char vector[10];
    float decimal;

    entero = 10;
    int entero2 = 10;
    strcpy(vector, "PROGRAMAS");
    decimal = 5.5;

    printf("Valor variable: int %d\nchar %s\nfloat %.2f\n", entero, vector, decimal);
    printf("Posición física int %p\nchar %p\nfloat %p\n\n", &entero, *vector, &decimal);

    // PUNTO 2

    int *ptrEntero;
    printf("Posición de memoria del puntero %p\nValor actual %p\nContenido %d\n\n", &ptrEntero, ptrEntero, *ptrEntero);
    ptrEntero = (int *)malloc(sizeof(int));
    // ptrEntero = new(float); //Opcion simplificada de c++ equivalente a malloc
    printf("Posición de memoria del puntero %p\nValor actual %p\nContenido %d\n\n", &ptrEntero, ptrEntero, *ptrEntero);

    free(ptrEntero);
    // delete(ptrEntero); //Opcion simplificada de c++ equivalente a free
    ptrEntero = NULL;

    return 0;
}