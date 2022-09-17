/*
Dado el archivo binario generado en el ejercicio 6, que contiene todas las inscripciones 
del día, y otro con el mismo diseño que contiene las inscripciones anteriores 
(FINALES.DAT), desarrolle un programa que agregue al archivo de inscripciones anteriores 
el contenido del archivo del día. Al final del proceso emita un listado del archivo de 
los registros agregados al archivo.

Estrategia:
- Abrir archivos DIAFINALES.DAT en modo Lectura y FINALES.DAT en modo Lectura/escritura  
- Ubicarse al final del archivo de inscripciones anteriores
- Recorrer secuencialmente el archivo de inscripciones del día
- Leer registro archivo de inscripciones del día
- Grabar registro en archivo de inscripciones anteriores
- Ubicarse en el primer registro de los agregados
- Recorrer secuencialmente el archivo de inscripciones anteriores desde donde fue ubicado
- Leer registro archivo de inscripciones anteriores
- Listar datos del registro
- Cerrar archivos
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

FILE * abrirArchivo(const char *fileName, const char *mode);

int main()
{
    system("clear");

    ST_INSCRIPCION inscripcion;

    FILE *diafinales = abrirArchivo("DIAFINALES.DAT", "rb");
    FILE *finales = abrirArchivo("FINALES.DAT", "rwb");

    fseek(finales, 0, SEEK_END);
    int posFinal = ftell(finales);

    fread(&inscripcion, sizeof(ST_INSCRIPCION), 1, diafinales);

    while(!feof(diafinales)) {

        fwrite(&inscripcion, sizeof(ST_INSCRIPCION), 1, finales);

        fread(&inscripcion, sizeof(ST_INSCRIPCION), 1, diafinales);
    }

    fseek(finales, posFinal, SEEK_SET);

    fread(&inscripcion, sizeof(ST_INSCRIPCION), 1, diafinales);

    while(!feof(diafinales)) {

        printf("%d - %d - %d - %d - %d , ", inscripcion.legajo, 
            inscripcion.codMateria, inscripcion.dia, inscripcion.mes, 
            inscripcion.anio, inscripcion.nombreApellido);

        fread(&inscripcion, sizeof(ST_INSCRIPCION), 1, diafinales);
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