/*
Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con
un Nombre = “FIN”, informar el nombre de la persona de mayor edad.

REG
Nombre 20 caracteres
Fecha (AAAAMMDD) 8 digitos enteros
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {

    char nombre[21];
    char nombreMayor[21];
    int fecha = 0;
    int fechaNacimientoMayor = 0;

    FILE *archivoReg = fopen("REG.TXT", "rt");

    while(fscanf(archivoReg, "%s %d", &nombre, &fecha) != EOF) {

        if(fechaNacimientoMayor == 0 || fecha < fechaNacimientoMayor) {
            fechaNacimientoMayor = fecha;
            strcpy(nombreMayor, nombre);
        }
    }

    printf("La persona de mayor edad es %s\n", nombreMayor);

    fclose(archivoReg);
    return 0;
}