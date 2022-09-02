/*
Ej. 6: Se dispone de un conjunto de boletas de inscripción de alumnos a examen en el mes de mayo.
Cada boleta tiene los siguientes datos: nombre y apellido, número de legajo, código de materia,
día, mes y año del examen. Los datos finalizan con un nombre y apellido nulo.
Desarrollar un programa que a partir del ingreso de las boletas mencionadas, por teclado, genere
un archivo binario de inscripción de alumnos a exámenes finales DIAFINALES.DAT, según el siguiente
diseño:
a.1 Nro. de legajo (8 dígitos)
a.2 Código de materia (6 dígitos)
a.3 Día del examen (1..31)
a.4 Mes del examen (1..12)
a.5 Año del examen (4 dígitos)
a.6 Nombre-Apellido (25caract)
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
} ST_ALUMNO;

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

int main()
{
    system("clear");

    ST_ALUMNO alumno;

    printf("Ingrese el Nombre y apellido del alumno: ");
    fgets(alumno.nombreApellido, sizeof(alumno.nombreApellido), stdin);
    fflush(stdin);

    FILE *archivoBinario = fopen("DIAFINALES.DAT", "wb");
    if (archivoBinario == NULL)
    {
        printf("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    while (strcmp(alumno.nombreApellido, "Fin") != 0)
    {

        printf("Código de Materia: ");
        scanf("%d", &alumno.codMateria);

        printf("Legajo: ");
        scanf("%d", &alumno.codMateria);

        printf("Ingrese el día, mes y año (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &alumno.dia, &alumno.mes, &alumno.anio);

        fwrite(&alumno, sizeof(ST_ALUMNO),1,archivoBinario);

        printf("Ingrese el Nombre y apellido del alumno: ");
        scanf("%s", alumno.nombreApellido);
    }

    fclose(archivoBinario);
    return 0;
}