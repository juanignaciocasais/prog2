/*
Dado el archivo del EJ. 1 grabe otro archivo APROB.TXT que contenga una primer línea con el
siguiente título “Listado de alumnos aprobados”, y a continuación una por cada alumno con el 
legajo y promedio de aquellos alumnos cuyo promedio sea >= 6.

Pasos
-Abrir archivo CURSO.TXT y crear APROB.TXT e imprimir el tìtulo
-Parsear los datos y comparar si el número es mayor que 6 
    imprimirlo en APROB:TXT
- Cerra archivos
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {
    
    FILE *archivoAlumnos = fopen("CURSO.TXT", "r+");
    if (archivoAlumnos == NULL)
    {
        printf("Error al abrir el archivo CURSO.TXT\n");
        exit(EXIT_FAILURE);
    }

    FILE *archivoAprobados = fopen("APROB.TXT", "wt");
    if (archivoAprobados == NULL)
    {
        printf("Error al abrir el archivo APROB.TXT\n");
        exit(EXIT_FAILURE);
    }

    fprintf(archivoAprobados, "Listado de alumnos aprobados\n");

    int legajo = 0;
    float promedio = 0;
    char titulo[10];

    fscanf(archivoAlumnos,"%s", &titulo);
    printf("%s\n", titulo);
    fscanf(archivoAlumnos,"%s", &titulo);
    printf("%s\n", titulo);
    
    while(fscanf(archivoAlumnos,"%d %f", &legajo, &promedio) != EOF) {
        if(promedio >= 6){
            fprintf(archivoAprobados, "%d %.2f\n", legajo, promedio);
        }
    };

    fclose(archivoAlumnos);
    fclose(archivoAprobados);

    return 0;
}