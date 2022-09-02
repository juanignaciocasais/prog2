/*
Se conoce de cada alumno de un curso los siguientes datos: legajo (8dígitos) y las notas de 2
parciales (0..10), que finaliza con un legajo negativo.
Se pide desarrollar un programa que ingrese los datos de los alumnos por teclado y grabe un
archivo de texto CURSO.TXT con una línea por cada alumno, con el número de legajo y su promedio
(real).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    float nota1;
    float nota2;
    float promedio;
} ST_ALUMNO;

int main()
{
    ST_ALUMNO alumno;

    FILE *archivoAlumnos = fopen("CURSO.TXT", "w");
    if (archivoAlumnos == NULL)
    {
        printf("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    fprintf(archivoAlumnos, "Legajo\tPromedio\n");

    printf("Ingrese el legajo del Alumno ó -1 para terminar: ");
    scanf("%d", &alumno.legajo);

    while (alumno.legajo >= 0)
    {
        printf("Ingrese la 1er Nota: ");
        scanf("%f", &alumno.nota1);

        printf("Ingrese la 2da Nota: ");
        scanf("%f", &alumno.nota2);

        alumno.promedio = (alumno.nota1 + alumno.nota2)/2;

        fprintf(archivoAlumnos, "%d\t%.2f\n", alumno.legajo, alumno.promedio);

        printf("Ingrese el legajo del Alumno o 0 para terminar: ");
        scanf("%d", &alumno.legajo);
    }

    fclose(archivoAlumnos);

    return 0;
}