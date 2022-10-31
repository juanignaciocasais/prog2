#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
using namespace std;

#define MAX_BUFFER 150

// Estructura para leer/escribir en los archivos
typedef struct
{
    int legajo;
    char apellidoYNombre[31];
    char domicilio[21];
    int codigoPostal;
    char telefono[11];
    int anioIngreso;
    char codigoOperacion[2];
} STR_DATO;

// Funciones de archivos
FILE *abrir(const char *fileName, const char *modo);
void cerrar(FILE *file);
int escribir(STR_DATO registro, FILE * file);
int leer(FILE *file, STR_DATO *registro);
int readAt(FILE *file, STR_DATO *registro, int posicion);
STR_DATO parsear(char *cadena);
void generarArchivo(const char *entrada, const char *salida);

int main () {
    
    generarArchivo("novedades.txt", "novedades.dat"); // Genera el archivo de entrada, se puede comentar si ya lo tienen
    
    return 0;
}

FILE *abrir(const char *fileName, const char *modo)
{
    FILE *file = fopen(fileName, modo);
    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    return file;
}

void cerrar(FILE *file)
{
    fclose(file);
    file = NULL;
}

int escribir(STR_DATO registro, FILE * file) {
    return fwrite(&registro, sizeof(STR_DATO), 1, file);
}

STR_DATO parsear(char *cadena) {
    STR_DATO dato;
    dato.legajo = atoi(strtok(cadena, ";"));
    strcpy(dato.apellidoYNombre,strtok(NULL, ";"));
    strcpy(dato.domicilio,strtok(NULL, ";"));
    dato.codigoPostal = atoi(strtok(NULL, ";"));
    strcpy(dato.telefono,strtok(NULL, ";"));
    dato.anioIngreso = atoi(strtok(NULL, "\n"));
    return dato;
}

void generarArchivo(const char *entrada, const char *salida) {
    FILE *datoBin = abrir(salida, "wb");
    FILE *datoTxt = abrir(entrada, "rt+");

    char buffer[MAX_BUFFER];
    fgets(buffer, MAX_BUFFER, datoTxt);
    while(!feof(datoTxt)) {
        escribir(parsear(buffer), datoBin);
        fgets(buffer, MAX_BUFFER, datoTxt);
    }

    cerrar(datoTxt);
    cerrar(datoBin);

    return;
}