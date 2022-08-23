#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "alumno.h"

ST_ALUMNO mejorPromedio(ST_ALUMNO alumnos[], int cantAlumnos) {

    int pos = 0;
    float mejorPromedio = alumnos[0].promedio;

    for(int i = 1; i < cantAlumnos; i++ ){
        if (alumnos[i].promedio > mejorPromedio){
            mejorPromedio = alumnos[i].promedio;
            pos = i;
        }
    }

    return alumnos[pos];
}

void ingresarAlumnos(ST_ALUMNO vector[], int cantAlumnos){

    for (int i = 0; i < cantAlumnos; i++){
        printf("Ingrese nombre del alumno: ");
        scanf("%s", vector[i].nombre);

        printf("Ingrese el promedio del alumno: ");
        scanf("%f", &vector[i].promedio);

        printf("Ingrese la fecha de inicio del alumno (DD-MM-AAAA): ");
        scanf("%d-%d-%d", &vector[i].fechaInicio.dia, &vector[i].fechaInicio.mes, &vector[i].fechaInicio.anio);
    }

    return;
}
