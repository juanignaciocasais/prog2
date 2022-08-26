/*
1) Dado una cadena, cuya longitud máxima es de 80 caracteres, y utilizando sólo sintaxis de
punteros, determinar si la cadena es o no un palíndromo. Ejemplo:
NEUQUEN → verdadero
CHUBUT → falso
2) Repita el ejercicio 1 utilizando funciones de la biblioteca <string.h>
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;

int main()
{
    printf("-----------PUNTO 1-----------\n");
    char cadena[81];

    printf("Ingrese una palabra de no mas de 80 caracteres: ");
    scanf("%s", &cadena);

    int largoCadena = 0;
    int i = 0;

    while (*(cadena + largoCadena) != '\0')
    {
        largoCadena++;
    }

    while (*(cadena + i) == *(cadena + largoCadena - (i + 1)) && i < largoCadena)
    {
        i++;
    }

    if (i == largoCadena)
    {
        printf("La palabra ingresada es Palíndromo\n");
    }
    else
    {
        printf("La palabra ingresada NO es Palíndromo\n\n");
    }

    printf("-----------PUNTO 2-----------\n");

    largoCadena = strlen(cadena);
    i = 0;

    while (*(cadena + i) == *(cadena + largoCadena - (i + 1)) && i < largoCadena)
    {
        i++;
    }

    if (i == largoCadena)
    {
        printf("La palabra ingresada es Palíndromo\n");
    }
    else
    {
        printf("La palabra ingresada NO es Palíndromo\n");
    }

    return 0;
}