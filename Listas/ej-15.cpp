/*
Dado un archivo de registros de alumnos, donde cada registro contiene: a) Apellido y
Nombre del alumno (35 caracteres) b) Número de legajo (7 dígitos) c) División
asignada (1 a 100) ordenado por número de legajo, desarrollar el algoritmo y
codificación del programa que imprima el listado de alumnos por división, ordenado
por división y número de legajo crecientes, a razón de 55 alumnos por hoja.
*/

#include <iostream>
using namespace std;

typedef struct 
{
    char apellidoYNombre[36];
    int legajo;
    int division;
}ST_ALUMNO, STR_DATO;

typedef struct Nodo
{
    STR_DATO dato;
    Nodo *siguiente;
} STR_NODO;

void create(STR_NODO **lista);
bool isEmpty(STR_NODO *lista);
STR_NODO *insertInFront(STR_DATO valor, STR_NODO **lista);
STR_NODO *insertAtEnd(STR_DATO valor, STR_NODO **lista);
STR_NODO *insertOrdered(STR_DATO valor, STR_NODO **lista);
void clearList(STR_NODO **lista);
STR_NODO *search(STR_NODO *lista, STR_DATO valor);
STR_DATO deleteFirst(STR_NODO **lista);
void sort(STR_NODO **lista);
void print(STR_NODO *listaAux);

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

int main()
{
    FILE * alumnos = abrirArchivo("alumnos.dat", "rb");
    ST_ALUMNO alumno;

    STR_NODO *lista;
    create(&lista);

    fread(&alumno, sizeof(alumno), 1, alumnos);

    while(!feof(alumnos)) {
        insertOrdered(alumno, &lista);
        fread(&alumno, sizeof(alumno), 1, alumnos);
    }

    print(lista);

    return 0;
}

void create(STR_NODO **lista)
{
    *lista = NULL;
    return;
}

bool isEmpty(STR_NODO *lista)
{
    return lista == NULL;
}

STR_NODO *insertInFront(STR_NODO **lista, STR_DATO valor)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = *lista;

    *lista = nodo;
    return nodo;
}

STR_NODO *insertAtEnd(STR_DATO valor, STR_NODO **lista)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = NULL;

    STR_NODO *listaAux = *lista;
    while (listaAux != NULL && listaAux->siguiente != NULL)
    {
        listaAux = listaAux->siguiente;
    }

    if (listaAux == NULL)
    {
        *lista = nodo;
    }
    else
    {
        listaAux->siguiente = nodo;
    }

    return nodo;
}

STR_NODO *insertOrdered(STR_DATO valor, STR_NODO **lista)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = NULL;

    STR_NODO *listaAux = *lista;
    STR_NODO *nodoAnt = NULL;
    while (listaAux != NULL && listaAux->dato.division < valor.division)
    {
        nodoAnt = listaAux;
        listaAux = listaAux->siguiente;
    }

    if (nodoAnt == NULL)
    {
        *lista = nodo;
    }
    else
    {
        nodoAnt->siguiente = nodo;
    }

    nodo->siguiente = listaAux;
    return nodo;
}

STR_NODO *search(STR_NODO *lista, STR_DATO valor)
{
    STR_NODO *listaAux = lista;
    while (listaAux != NULL && listaAux->dato.division != valor.division)
    {
        listaAux = listaAux->siguiente;
    }
    return listaAux;
}

STR_DATO deleteFirst(STR_NODO **lista)
{
    STR_NODO *aux = *lista;
    *lista = (*lista)->siguiente;
    STR_DATO dato = aux->dato;
    free(aux);
    return dato;
}

void clearList(STR_NODO **lista)
{
    STR_NODO *aux = NULL;
    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->siguiente;
        free(aux);
    }
}

void sort(STR_NODO **lista)
{
    STR_NODO *listaAux;
    create(&listaAux);
    STR_DATO dato;
    while (*lista != NULL)
    {
        dato = deleteFirst(lista);
        insertOrdered(dato, &listaAux);
    }

    *lista = listaAux;
}

void print(STR_NODO *listaAux)
{
    printf("\n");
    while (listaAux != NULL)
    {
        printf("%s  %d  %d\n", listaAux->dato.apellidoYNombre, listaAux->dato.division, listaAux->dato.legajo);
        listaAux = listaAux->siguiente;
    }
    printf("\n");
}