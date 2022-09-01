/*
Declarar un puntero miPuntero de char[10], asignar dinámicamente espacio en memoria, asignarle
el valor “hola” y luego ...
a) Imprimir por pantalla el puntero con el formateador %s.
b) Imprimir la dirección de memoria del puntero.
c) Imprimir el valor del puntero.
d) Imprimir la dirección de memoria miPuntero[0] y relaciónelo con el punto anterior.
e) Imprimir el valor miPuntero[0], luego ejecute miPuntero++ y vuelva a imprimir miPuntero[0].
Analice el resultado y concluya.
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;

int main()
{
    char *miPuntero;
    
    miPuntero = (char *)malloc(sizeof(char)*10);

    miPuntero = "hola";

    //Punto a
    printf("Imprimir por pantalla el puntero con el formateador 's'.\n");
    printf("%s\n", miPuntero);
    
    //Punto b:
    printf("Dirección de memoria del puntero.\n");
    printf("%p\n", &miPuntero);

    //Punto c
    printf("Valor del puntero.\n");
    printf("%p\n", miPuntero);

    //Punto d
    printf("Dirección de memoria miPuntero[0].\n");
    printf("%p\n", &miPuntero[0]);

    //Punto e
    printf("Valor miPuntero[0].\n");
    printf("%c\n", miPuntero[0]);

    return 0;
}