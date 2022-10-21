/*
Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada
valor igual a X que se encuentre en la pila por el valor Y retornando la pila
modificada. En caso de no haber ningún valor igual a X retornar la pila sin cambio.
(Definir parámetros y codificar).
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

void reemplazar(STR_NODO **pila, int valor, int porValor) 
{
    STR_NODO *pilaAux = NULL;
    int aux = 0;
    
    while(!isEmpty(*pila)) {
        aux = pop(pila);
        if(aux == valor){
            aux = porValor;
        }
        push(&pilaAux, aux);
    }

    while(!isEmpty(pilaAux)) {
        push(pila, pop(&pilaAux));
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

    reemplazar(&pila, 4, 555);

    clear(&pila);

    return 0;
}