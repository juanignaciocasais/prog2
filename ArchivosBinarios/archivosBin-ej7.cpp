/*
Dado el archivo binario generado en el ejercicio 7, desarrolle un programa que solicitando por
teclado un código de materia permita seleccionar todos los registros que se anotaron para rendirla y los
grabe en otro archivo (MATFINALES.DAT), con el mismo diseño.

Estrategia
- Abrir archivo DIAFINALES modo lectura
- Abrir archivo MATFINALES modo escritura
-
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;

typedef struct
{
    int legajo;
    int codMateria;
    int dia;
    int mes;
    int anio;
    char nombreApellido[26];
} ST_INSCRIPCION;

int main()
{
    system("clear");

    ST_INSCRIPCION registro;

    FILE *diaFinales = fopen("DIAFINALES.DAT", "rwb");

    if (diaFinales == NULL)
    {
        printf("Error al abrir el archivo1");
        exit(EXIT_FAILURE);
    }

    FILE *matFinales = fopen("MATFINALES.DAT", "wb");
    if (matFinales == NULL)
    {
        printf("Error al abrir el archivo2");
        exit(EXIT_FAILURE);
    }

    int codMateria = 0;

    printf("Ingrese el Codigo de Materia: ");
    scanf("%d", &codMateria);

    fread(&registro, sizeof(ST_INSCRIPCION), 1, diaFinales);
    while (!feof(diaFinales))
    {
        if (registro.codMateria == codMateria)
        {
            fwrite(&registro, sizeof(ST_INSCRIPCION),1,matFinales);
            printf("%d\n", registro.codMateria);
        }

        fread(&registro, sizeof(ST_INSCRIPCION), 1, diaFinales);
    }

    fclose(diaFinales);
    fclose(matFinales);

    return 0;
}