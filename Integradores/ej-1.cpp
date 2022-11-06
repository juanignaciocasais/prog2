/*
Ejercicio 1
Una empresa desea realizar el resumen mensual de las horas trabajadas y horas de ausencia de sus
empleados. Para realizar el cálculo cuenta con un archivo binario “HORAS_DIARIAS.dat” donde cada
registro se compone de los siguientes datos:
● Legajo del empleado: 10 caracteres
● Día del mes: número de 1 a 31
● Horas: número entero de 1 a 24
● Ausencia: 1 o 0 (si es 1: las Horas son horas de ausencia, si es 0: las Horas son horas
trabajadas)
El archivo se encuentra desordenado y por haber distintos turnos puede haber más de un registro
por día de un mismo empleado. Se solicita:
a. Definir la estrategia y estructuras necesarias para la lectura del archivo y realización
de los puntos b. y c.
b. Imprimir por pantalla el listado de las horas imputadas por cada empleado para el
mes, ordenado por legajo en forma creciente. imprimiendo:
    Legajo  Hs.     Trabajadas      Hs. Ausencia    % Ausentismo (HA / HT + HA)
c. Indicar el día del mes con mayor cantidad de Horas de Ausencia
d. Indicar el legajo con mayor Ausentismo
*/

#include <iostream>
#include "string.h"
using namespace std;

typedef struct Nodo
{
    char legajo[11];
    int diaDelMes;
    int horas;
    bool ausencia;
} STR_EMPLEADO;

typedef struct Nodo
{
    char legajo[11];
    int hsTrabajadas;
    int hsAusentes;
} STR_DATO;

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
STR_DATO deleteNode(STR_NODO **lista, STR_DATO valor);
void sort(STR_NODO **lista);
int count(STR_NODO *listaAux);
STR_NODO *insertWithoutDuplicate(STR_DATO valor, STR_NODO **lista);
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

    FILE *empleados = abrirArchivo("HORAS_DIARIAS.DAT", "rb");
    STR_EMPLEADO empleado;
    STR_NODO *lista;

    STR_DATO registroEmpleado;

    create(&lista);

    int diasDelMes[31] = {0};

    fread(&empleado, sizeof(empleado), 1, empleados);

    while (!feof(empleados))
    {
        strcpy(registroEmpleado.legajo, empleado.legajo);
        registroEmpleado.hsAusentes = 0;
        registroEmpleado.hsTrabajadas = 0;
        STR_NODO *nodoEmpleado = search(lista, registroEmpleado);

        if (nodoEmpleado == NULL)
        {
            nodoEmpleado = insertOrdered(registroEmpleado, &lista);
        }
        if (empleado.ausencia)
        {
            nodoEmpleado->dato.hsAusentes += registroEmpleado.hsAusentes;
            diasDelMes[empleado.diaDelMes - 1] += empleado.horas;
        }
        else
        {
            nodoEmpleado->dato.hsTrabajadas += registroEmpleado.hsTrabajadas;
        }
        fread(&empleado, sizeof(empleado), 1, empleados);
    }

    printf("Legajo - Hs.Trabajadas - Hs. Ausencia - Ausentismo\n");

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

STR_NODO *insertAtEnd(STR_NODO **lista, STR_DATO valor)
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
    while (listaAux != NULL && listaAux->dato.legajo < valor.legajo)
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
    while (listaAux != NULL && strcmp(listaAux->dato.legajo, valor.legajo) == 0)
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

STR_DATO deleteNode(STR_NODO **lista, STR_DATO valor)
{
    STR_NODO *aux = *lista;
    STR_NODO *nodoAnt = NULL;

    while (aux == NULL && aux->dato.legajo != valor.legajo)
    {
        nodoAnt = aux;
        aux = aux->siguiente;
    }

    if (nodoAnt == NULL)
    {
        *lista = (*lista)->siguiente;
    }

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

int count(STR_NODO *listaAux)
{
    int cant = 0;
    while (listaAux != NULL)
    {
        listaAux = listaAux->siguiente;
        cant++;
    }

    return cant;
}

STR_NODO *insertWithoutDuplicate(STR_DATO valor, STR_NODO **lista)
{
    STR_NODO *nodo = search(*lista, valor);
    if (nodo == NULL)
    {
        nodo = insertOrdered(valor, lista);
    }

    return nodo;
}

void print(STR_NODO *listaAux)
{
    while (listaAux != NULL)
    {
        printf("%d   ", listaAux->dato.legajo);
        listaAux = listaAux->siguiente;
    }
    printf("\n");
    return;
}