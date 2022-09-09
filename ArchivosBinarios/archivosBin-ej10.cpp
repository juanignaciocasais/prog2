/*
Dado el archivo binario generado en el ejercicio 7, desarrolle un programa que genere 
un archivo ordenado por número de legajo (cada registro debe tener los campos legajo 
y apellido y nombre) para todos los alumnos que se inscribieron una o más veces. Cada 
legajo debe ocupar una posición única y predecible en el archivo. El intervalo de los 
legajos es 80001 a 110000. Pueden no presentarse todos los legajos

Estrategia:
- Abrir en archivo DIAFINALES.DAT en modo lectura
- Crear el archivo ALUMNOS.DAT en modo escritura y crear su estructura de datos.
- Recorrerlo guardando los datos en Legajo = 0 para facilitar el ejercicio 11
- Recorrer el archivo DIAFINALES.DAT y leyendo cada legajo:
    guardarlo en la nueva estructura y luego, segùn su legajo ubicarlo con PUP
    en la posición correspondiente de archivo ALUMNOS:DAT
- Cerrar los archivos
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int legajo;
    int codMateria;
    int dia;
    int mes;
    int anio;
    char nombreApellido[26];
} ST_INSCRIPCION;

typedef struct
{
    int legajo;
    char nombreApellido[26];
} ST_ALUMNO;

int main()
{
    system("clear");

    ST_INSCRIPCION registro;
    ST_ALUMNO alumno;

    FILE *diaFinales = fopen("DIAFINALES2.DAT", "rwb");

    if (diaFinales == NULL)
    {
        printf("Error al abrir el archivo1");
        exit(EXIT_FAILURE);
    }

    FILE *archivoAlumnos = fopen("ALUMNOS.DAT", "wb");

    //int posInicial = ftell(archivoAlumnos);

    if (archivoAlumnos == NULL)
    {
        printf("Error al abrir el archivo2");
        exit(EXIT_FAILURE);
    }

    alumno.legajo = 0;

    for(int i = 80001; i >=110000; i++)
    {
        fwrite(&alumno, sizeof(ST_ALUMNO),1,archivoAlumnos);
    }

    fread(&registro,sizeof(ST_INSCRIPCION), 1, diaFinales);
    while(!feof(diaFinales))
    {
        alumno.legajo = registro.legajo;
        strcpy(alumno.nombreApellido, registro.nombreApellido);

        fseek(archivoAlumnos, sizeof(ST_ALUMNO) * alumno.legajo - 80001, SEEK_SET);
        fwrite(&alumno, sizeof(ST_ALUMNO),1,archivoAlumnos);
        printf("%d : %s\n", alumno.legajo, alumno.nombreApellido);

        fread(&registro,sizeof(ST_INSCRIPCION), 1, diaFinales);
    }

    fclose(archivoAlumnos);
    fclose(diaFinales);

    return 0;
}