/*
Dado el archivo binario generado en el ejercicio 6, desarrollar la codificación en C 
o C++ que graba un archivo de texto, LISTADO.TXT, de los alumnos inscriptos de acuerdo 
al siguiente diseño.

Legajo Nombre y Apellido Fecha Código de materia
99999999 xxxxxxxxxxxxxxxxxxxx dd/mm/aa 999999
99999999 xxxxxxxxxxxxxxxxxxxx dd/mm/aa 999999

Realice la estrategia de resolución, la representación gráfica del algoritmo, y 
dibuje el diseño del registro

Estrategia:
- Definir Estructura
- Abrir archivo DIAFINALES.DAT en modo lectura
- Abrir archivo LISTADO.TXT en modo escritura
- Escribir el tìtulo del listado.
- Recorrer el archivo DIAFINALES.DAT e ir imprimiendo en el LISTADO.TXT
- Cerrar archivos
*/

#include<stdio.h>
#include<stdlib.h>
#include"string.h"

typedef struct 
{
    int legajo;
    int codMateria;
    int dia;
    int mes;
    int anio;
    char nombreApellido[26]; 
}ST_INSCRIPCION;

FILE * abrirArchivo(const char *fileName, const char *mode);

int main() {

    ST_INSCRIPCION inscripcion;

    FILE *diaFinales = abrirArchivo("DIAFINALES2.DAT", "rb");
    FILE *listado = abrirArchivo("LISTADO.TXT", "wt");

    fprintf(listado,"Legajo Nombre y Apellido Fecha Código de materia\n");

    fread(&inscripcion,sizeof(ST_INSCRIPCION), 1, diaFinales);

    while(!feof(diaFinales)) {
        fprintf(listado,"%d \t\t %s \t\t %d/%d/%d \t  %d\n", 
            inscripcion.legajo, inscripcion.nombreApellido, inscripcion.dia, inscripcion.mes, inscripcion.anio, inscripcion.codMateria);
    
        fread(&inscripcion,sizeof(ST_INSCRIPCION), 1, diaFinales);
    }

    return 0;
}

FILE * abrirArchivo(const char *fileName, const char *mode) {

    FILE * file = fopen(fileName, mode);
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    return file;
}
