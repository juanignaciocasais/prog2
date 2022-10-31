/*
Dada una lista (nodo = registro + puntero), desarrollar y codificar una función que
devuelva la cantidad de nodos que tiene.
*/

#include <iostream>
using namespace std;

typedef struct Nodo
{
    int dato;
    Nodo *siguiente;
} STR_NODO;

void create(STR_NODO **lista);
bool isEmpty(STR_NODO *lista);
STR_NODO *insertInFront(int valor, STR_NODO **lista);
STR_NODO *insertAtEnd(STR_NODO **lista, int valor);
STR_NODO *insertOrdered(int valor, STR_NODO **lista);
void clearList(STR_NODO **lista);
STR_NODO *search(STR_NODO *lista, int valor);
int deleteFirst(STR_NODO **lista);
int deleteNode(STR_NODO **lista, int valor);
void sort(STR_NODO **lista);
int count(STR_NODO *listaAux);
void cargarLista(STR_NODO **lista, int desde, int hasta);
void print(STR_NODO *listaAux);
void cargarListaConArray(STR_NODO **lista, int array[], int cant);
void unirListasOrdenadas(STR_NODO **listaA, STR_NODO **listaB, STR_NODO **listaC);
void apareoListasOrdenadas(STR_NODO **listaA, STR_NODO **listaB, STR_NODO **listaC);

int main()
{
    STR_NODO *listaA;

    create(&listaA);

    cargarLista(&listaA, 1, 10);

    print(listaA);

    printf("La lista tiene %d nodos.\n", count(listaA));

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

STR_NODO *insertInFront(STR_NODO **lista, int valor)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = *lista;

    *lista = nodo;
    return nodo;
}

STR_NODO *insertAtEnd(STR_NODO **lista, int valor)
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

STR_NODO *insertOrdered(int valor, STR_NODO **lista)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = NULL;

    STR_NODO *listaAux = *lista;
    STR_NODO *nodoAnt = NULL;
    while (listaAux != NULL && listaAux->dato < valor)
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

STR_NODO *search(STR_NODO *lista, int valor)
{
    STR_NODO *listaAux = lista;
    while (listaAux != NULL && listaAux->dato != valor)
    {
        listaAux = listaAux->siguiente;
    }
    return listaAux;
}

int deleteFirst(STR_NODO **lista)
{
    STR_NODO *aux = *lista;
    *lista = (*lista)->siguiente;
    int dato = aux->dato;
    free(aux);
    return dato;
}

int deleteNode(STR_NODO **lista, int valor)
{
    STR_NODO *aux = *lista;
    STR_NODO *nodoAnt = NULL;

    while (aux == NULL && aux->dato != valor)
    {
        nodoAnt = aux;
        aux = aux->siguiente;
    }

    if (nodoAnt == NULL) {
        *lista = (*lista)->siguiente;
    }

    int dato = aux->dato;
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
    int dato;
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

void cargarLista(STR_NODO **lista, int desde, int hasta)
{

    if (desde < hasta)
    {
        for (int i = desde; i <= hasta; i++)
        {
            insertAtEnd(lista, i);
        }
    }
    else
    {
        for (int i = desde; i >= hasta; i--)
        {
            insertAtEnd(lista, i);
        }
    }

    return;
}

void cargarListaConArray(STR_NODO **lista, int array[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        insertAtEnd(lista, array[i]);
    }
    return;
}

void print(STR_NODO *listaAux)
{
    while (listaAux != NULL)
    {
        printf("%d   ", listaAux->dato);
        listaAux = listaAux->siguiente;
    }
    printf("\n");
    return;
}