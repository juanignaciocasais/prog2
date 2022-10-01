/*
Dado un conjunto de N cursos ( <=20) de una materia, se tiene un archivo “CURSOS.DAT” con
la información de cada uno de ellos: código de curso ( 4 caracteres) y cantidad de alumnos. Además se
tiene en otro archivo “ALUMNOS.DAT” con el curso, legajo y nota (1 a 10) de cada alumno.
Se pide:
 informar de la cantidad de alumnos que tuvieron como nota 0, 1, ...,9, 10
 informar al final del proceso el código de curso, el % de aprobados y el de insuficientes de cada
curso.

ESTRATEGIA
- Abrir archivo CURSOS.DAT modo lectura y pasarlo a un vector con una nueva estructura agregando 2 contadores
    uno que sume los que obtuvieron notas >= 6 y otra lso que no cumplioeron esa condición.
- Abrir y recorrer el archivo ALUMNOS.DAT y a medida que leemos un alumno modificamos el vector 
    (dependiendo la nota) realizando búsqueda secuencial ya que son como mucho 20 cursos. 
- AL final imprimir la cantidad de alumnos con nota y el codgigo de curso y los porcentajes de cada uno

*/

#include <iostream>
#include "string.h"
using namespace std;

#define MAX_CURSOS 20

typedef struct 
{
    char codigo[5];
    int cantAlumnos;
}ST_CURSO;

typedef struct 
{
    char codigo[5];
    int cantAlumnos;
    int cantAprobados;
    int cantDesaprobados;
}ST_CURSOVECTOR;

typedef struct 
{
    char codigo[5];
    int legajo;
    int nota;
}ST_ALUMNO;

FILE *abrir(char *filename, char *modo);
int leer(FILE *filemane, ST_CURSO curso);
int leer(FILE *filemane, ST_ALUMNO alumno);
ST_CURSOVECTOR pasarEstructura(ST_CURSO curso);
int buscarCurso(char *codigo, ST_CURSOVECTOR vector[]);

int main () {
    int alumnosTotal = 0;

    FILE *archivoCurso = abrir("CURSOS.DAT", "rb");
    FILE *archivoAlumnos = abrir("ALUMNOS.DAT", "rb");
    ST_ALUMNO alumno;
    ST_CURSO curso;
    ST_CURSOVECTOR cursos[MAX_CURSOS];
    ST_CURSOVECTOR cursoVector;
    int cantCursos = 0;

    leer(archivoCurso, curso);
    while(!feof(archivoCurso)) {
        cursoVector = pasarEstructura(curso);
        cursos[cantCursos]= cursoVector;
        cantCursos++;
        leer(archivoCurso, curso);
    }
    fclose(archivoCurso);

    leer(archivoAlumnos, alumno);
    while(!feof(archivoAlumnos)){
        int pos = buscarCurso(alumno.codigo, cursos);
        if(alumno.nota >= 6 ) {
            cursos[pos].cantAprobados++;
        }else {
            cursos[pos].cantDesaprobados++;
        }
        alumnosTotal++;
        leer(archivoAlumnos, alumno);
    }

    fclose(archivoCurso);

    printf("La cantidad de alumnos que tuvieron nota es: %d\n", alumnosTotal);

    for(int i = 0; i < cantCursos; i++) {
        printf("Porcentaje Aprobados: %.2f\n", (cursos[i].cantAprobados*100)/cursos[i].cantAlumnos);
        printf("Porcentaje Desaprobados: %.2f\n", (cursos[i].cantDesaprobados*100)/cursos[i].cantAlumnos);
    }

    return 0;
}

FILE *abrir(char *filename, char *modo){

    FILE *file = fopen(filename, modo);
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", filename);
        EXIT_FAILURE;
    }
    return file;
}
int leer(FILE *filemane, ST_CURSO curso){
    return fread(&curso, sizeof(ST_CURSO), 1, filemane);
}

int leer(FILE *filemane, ST_ALUMNO alumno){
    return fread(&alumno, sizeof(ST_ALUMNO), 1, filemane);
}

ST_CURSOVECTOR pasarEstructura(ST_CURSO curso){
    
    ST_CURSOVECTOR cursoNuevo;
    strcpy(cursoNuevo.codigo,curso.codigo);
    cursoNuevo.cantAlumnos = curso.cantAlumnos;
    cursoNuevo.cantAprobados = 0;
    cursoNuevo.cantDesaprobados = 0;

    return cursoNuevo;
}

int buscarCurso(char *codigo, ST_CURSOVECTOR vector[MAX_CURSOS]){

    for(int i = 0; i < MAX_CURSOS; i++) {
        if (strcmp(vector[i].codigo, codigo) == 0 ) {
            return i;
        }
    }

    return -1;
}