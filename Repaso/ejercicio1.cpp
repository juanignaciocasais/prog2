/*
1) Desarrollar un algoritmo que defina un vector de 10 posiciones y...
a) Asigne a cada una de las posiciones el valor que resulta de: posición_actual x
posición_anterior.
b) Imprimir en pantalla la posición y su valor.
c) Invertir el orden del vector e imprimir por pantalla la posición y su valor.
*/
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;

void completarVectores(int vector[10])
{
    for (int i = 0; i < 10; i++)
    {
        vector[i] = rand() % 100;
    }

    return;
}

void imprimirVector(int vector[10])
{

    for (int i = 0; i < 10; i++)
    {
        printf("%d: %d ", i, vector[i]);
    }
    printf("\n");
    return;
}

void reasignarVector(int vector[10])
{
    int copiaVector[10];
    
    for (int i = 0; i < 10; i++)
    {
        copiaVector[i] = vector[i];
    }

    for (int i = 1; i < 10; i++)
    {
        vector[i] = copiaVector[i] * copiaVector[i - 1];
    }

    return;
}

void invertirVector(int vector[10]) {

    int copiaVector[10];

    for (int i = 0; i < 10; i++)
    {
        copiaVector[i] = vector[9 - i];
    }

    for (int i = 0; i < 10; i++)
    {
        vector[i] = copiaVector[i];
    }

    return;
}

int main()
{
    int vector[10];
    int copiaVector[10];

    completarVectores(vector);

    imprimirVector(vector);

    reasignarVector(vector);

    imprimirVector(vector);

    invertirVector(vector);

    imprimirVector(vector);

    return 0;
}