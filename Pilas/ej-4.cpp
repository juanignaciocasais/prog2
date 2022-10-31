/*
Dada una pila y dos valores X e I, desarrollar un procedimiento que inserte el valor X
en la posición I de la pila si es posible. (Definir parámetros y codificar).
*/

#include <iostream>
using namespace std;

struct STR_NODO
{
    int dato;
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

void push(STR_NODO **pila, int valor)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->ste = NULL;

    nodo->ste = *pila;
    *pila = nodo;
    return;
}

int pop(STR_NODO **pila)
{
    int dato = (*pila)->dato;
    STR_NODO *aux = *pila;
    *pila = (*pila)->ste;

    free(aux);
    return dato;
}

void clear(STR_NODO **pila)
{
    while (!isEmpty(*pila))
    {
        printf("%d->", pop(pila));
    }
    printf("NULL");
}

void pushEnPosicion(STR_NODO *pila, int x, int i)
{
    STR_NODO *aux = NULL;
    int valor = 0;
    int pos = 0;

    while(pila != NULL && pos != i) {       
        valor = pop(&pila);
        push(&aux, valor);
        pos++;
    }

    push(&pila, x);

    while(aux != NULL)  {
        valor = pop(&aux);
        push(&pila, valor);
    }

}

int main()
{

    STR_NODO *pila = NULL;

    create(&pila);

    push(&pila, 1);
    push(&pila, 2);
    push(&pila, 3);
    push(&pila, 4);
    push(&pila, 5);
    push(&pila, 6);

    pushEnPosicion(pila, 99, 1);

    clear(&pila);

    return 0;
}