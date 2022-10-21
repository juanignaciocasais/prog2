/*
Desarrollar un procedimiento que ingrese por teclado un conjunto de Apellidos y
Nombre de alumnos y los imprima en orden inverso al de ingreso. (Definir
parámetros y codificar).
*/

#include <iostream>
#include "string.h"
using namespace std;

typedef struct {
    char nombre[40];
    char apellido[40];
}ST_ALUMNO;

struct STR_NODO
{
    ST_ALUMNO dato;
    STR_NODO *ste;
};

void create(STR_NODO **pila)
{
    *pila = NULL;
}

bool isEmpty(STR_NODO *pila)
{
    return pila == NULL;
}

void push(STR_NODO **pila, ST_ALUMNO valor)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->ste = NULL;

    nodo->ste = *pila;
    *pila = nodo;
    return;
}

ST_ALUMNO pop(STR_NODO **pila)
{
    ST_ALUMNO dato = (*pila)->dato;
    STR_NODO *aux = *pila;
    *pila = (*pila)->ste;

    free(aux);
    return dato;
}

void clear(STR_NODO **pila)
{
    ST_ALUMNO alumno;
    while (!isEmpty(*pila))
    {
        alumno = pop(pila);
        printf("---------\nNombre: %s\nApellido: %s\n", alumno.nombre, alumno.apellido);
    }
}

void cargarAlumnos(STR_NODO **pila) {

    ST_ALUMNO alumno;
    printf("Ingrese Nombre: ");
    scanf("%s", &alumno.nombre);

    while(strcmp(alumno.nombre,"FIN") != 0) {

        printf("Ingrese Apellido: ");
        scanf("%s", &alumno.apellido);

        push(pila, alumno);

        printf("Ingrese Nombre: ");
        scanf("%s", &alumno.nombre);
    }
}

int main()
{

    STR_NODO *pila = NULL;

    cargarAlumnos(&pila);

    clear(&pila);

    return 0;
}