/*
- Cargar 3 Alumnos. 
- Alumno tiene: Nombre, promedio, fecha Inicio. 
- Llamando a una funcion, (mejor promedio) muestre que alumno tiene el mejor promedio.
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "alumno.h"
using namespace std;

#define MAX_ALUMNOS 100

int main () {

    ST_ALUMNO alumnos[MAX_ALUMNOS];
    int cantAlumnos = 0;

    printf("Ingrese la cantidad de alumnos a cargar: ");
    scanf("%d", &cantAlumnos);

    ingresarAlumnos(alumnos, cantAlumnos);

    ST_ALUMNO mejorAlumno = mejorPromedio(alumnos, cantAlumnos);
    
    printf("El alumno con mejor promedio es %s con %2.2f.\n", mejorAlumno.nombre, mejorAlumno.promedio);
    
    return 0;
}
