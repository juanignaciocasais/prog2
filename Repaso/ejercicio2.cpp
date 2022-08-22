/*
2) Implementar un sistema que solicite indefinidamente números por pantalla hasta que se
ingrese un valor de corte e...
a) Imprimir el número más alto.
b) Imprimir el número más bajo.
c) Imprimir el promedio.
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;

float obtenerMasAlto(float masAlto, float actual)
{

    if (masAlto > actual)
    {
        return masAlto;
    }
    else
    {
        return actual;
    }
}

float obtenerMasBajo(float masBajo, float actual)
{

    if (masBajo > actual)
    {
        return actual;
    }
    else
    {
        return masBajo;
    }
}

float obtenerPromedio(float promedio, float actual)
{
    return (promedio + actual) / 2;
}

int main()
{
    float actual = 0;
    float masAlto = 0;
    float masBajo = 0;
    float promedio = 0;
    float anterior = 0;

    printf("Ingrese un número:");
    scanf(" %f", &actual);
    masAlto = actual;
    masBajo = actual;
    promedio = actual;
    anterior = actual;

    printf("Ingrese otro número ó 0 para finalizar:");
    scanf(" %f", &actual);

    while (actual != 0)
    {

        masAlto = obtenerMasAlto(masAlto, actual);

        masBajo = obtenerMasBajo(masBajo, actual);

        promedio = obtenerPromedio(promedio, actual);

        printf("Ingrese otro número ó 0 para finalizar:");
        scanf(" %f", &actual);
    }

    printf("El número ingresado mas Alto es: %5.2f\n", masAlto);
    printf("El número ingresado mas Bajo es: %5.2f\n", masBajo);
    printf("El Promedio es: %5.2f\n", promedio);

    return 0;
}
