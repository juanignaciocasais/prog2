/*
Dado el archivo “ALUMNOS.dat” con los datos personales de alumnos ordenado por legajo, con
el siguiente diseño:
a.1 Legajo (8 dígitos) a.2 Apellido y nombre ( 30 caracteres)
a.3 Domicilio (20 caracteres) a.4 Código postal (4 dígitos)
a.5 Teléfono (10 caracteres) a.6 Año de ingreso (4 dígitos)
Y otro archivo con el mismo orden que el mencionado llamado “NOVEDADES.dat”, con las
actualizaciones (altas, bajas, y modificaciones) a ser aplicadas, donde cada registro contiene además de
todos los campos de Alumnos.dat un código de operación (“A”= Alta, “B”= Baja, “M”= Modificación).
a- Desarrollar todos los pasos necesarios para realizar un programa que genere un archivo actualizado
“ALUMACTU.dat” con el mismo diseño.
b- Rehacer el ejercicio considerando que el archivo NOVEDADES es de texto separado por tabs en
lugar de binario.

ESTRATEGIA
- abrir Archivo binario ALUMNOS.dat en modo lectura.
- abrir Archivo binario NOVEDADES.dat en modo lectura.
- abrir Archivo binario ALUMACTU.dat en modo escritura.
- Recorrer el archivo de Novedades y Alumno y a medida que tomamos un legajo
  verificamos si está en los dos archivos y vemos el cod de operacion
    Si es Alta, agregamos el alumno nuevo al archivo ALUMACTU.dat
    Si es Baja lo salteamos y no se agrega en el archivo.
    Si es Modificación cargamos esa info de Novedades en el archivo ALUMACTU.dat
    y Si no existe en novedades pero si el Alumnos.dat. Lo agregamos a ALUMACTU.dat
- Cerramos los archivos
*/

#include <stdlib.h>
#include <stdio.h>
#include "string.h"

typedef struct
{
    int legajo;
    char apellidoYNombre[31];
    char domicilio[21];
    int codigoPostal;
    char telefono[11];
    int anioIngreso;
} ST_ALUMNO;

typedef struct
{
    int legajo;
    char apellidoYNombre[31];
    char domicilio[21];
    int codigoPostal;
    char telefono[11];
    int anioIngreso;
    char codigoOperacion[2];
} ST_NOVEDADES_ALUMNO;

FILE *abrirArchivo(char *fileName, char *mode)
{
    FILE *file = fopen(fileName, mode);
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", fileName);
        EXIT_FAILURE;
    }
    return file;
}

ST_ALUMNO actualizarDato(ST_NOVEDADES_ALUMNO datos)
{

    ST_ALUMNO nuevoDato;
    nuevoDato.legajo = datos.legajo;
    strcpy(datos.apellidoYNombre, nuevoDato.apellidoYNombre);
    strcpy(datos.domicilio, nuevoDato.domicilio);
    nuevoDato.codigoPostal = datos.codigoPostal;
    strcpy(datos.telefono, nuevoDato.telefono);
    nuevoDato.anioIngreso = datos.anioIngreso;

    return nuevoDato;
}

int main()
{

    FILE *archivoAlumnos = abrirArchivo("ALUMNOS.dat", "rb");
    FILE *archivoNovedades = abrirArchivo("NOVEDADES.dat", "rb");
    FILE *archivoActualizado = abrirArchivo("ALUMACTU.dat", "wb");

    ST_ALUMNO alumnos;
    ST_NOVEDADES_ALUMNO novedades;
    ST_ALUMNO modificado;

    fread(&alumnos, sizeof(alumnos), 1, archivoAlumnos);
    fread(&novedades, sizeof(alumnos), 1, archivoNovedades);

    while (!feof(archivoAlumnos) && !feof(archivoNovedades))
    {
        if (alumnos.legajo == novedades.legajo)
        {
            if (strcmp(novedades.codigoOperacion, "M"))
            {
                modificado = actualizarDato(novedades);
                fwrite(&modificado, sizeof(modificado), 1, archivoActualizado);
                fread(&alumnos, sizeof(alumnos), 1, archivoAlumnos);
                fread(&novedades, sizeof(alumnos), 1, archivoNovedades);
            }

            if (strcmp(novedades.codigoOperacion, "B"))
            {
                fread(&alumnos, sizeof(alumnos), 1, archivoAlumnos);
                fread(&novedades, sizeof(alumnos), 1, archivoNovedades);
            }
        }

        if (alumnos.legajo < novedades.legajo)
        {
            fwrite(&alumnos, sizeof(alumnos), 1, archivoActualizado);
            fread(&alumnos, sizeof(alumnos), 1, archivoAlumnos);
        }

        if (alumnos.legajo > novedades.legajo)
        {
            fwrite(&alumnos, sizeof(alumnos), 1, archivoActualizado);
            fread(&alumnos, sizeof(alumnos), 1, archivoAlumnos);
        }
    }

    while (!feof(archivoAlumnos))
    {
        fwrite(&alumnos, sizeof(alumnos), 1, archivoActualizado);
        fread(&alumnos, sizeof(alumnos), 1, archivoAlumnos);
    }

     while (!feof(archivoNovedades))
    {
        if (strcmp(novedades.codigoOperacion, "A"))
            {
            modificado = actualizarDato(novedades);
            fwrite(&modificado, sizeof(modificado), 1, archivoActualizado);
            }            
        fread(&alumnos, sizeof(alumnos), 1, archivoNovedades);
    }

    return 0;
}