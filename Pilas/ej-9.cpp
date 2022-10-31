/*
Dada una pila desarrollar un procedimiento que ordene la misma de acuerdo al valor
de sus nodos y la retorne. Solo se deben usar pilas. (Definir parámetros y codificar).
*/

#include <iostream>
using namespace std;

struct STR_NODO
{
    char dato;
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

char pop(STR_NODO **pila)
{
    char dato = (*pila)->dato;
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

int main()
{
    STR_NODO *pila;
    STR_NODO *pila2;
    STR_NODO *ordenado;

    int popA;
    int popB;
    int aux;

    create(&pila);
    create(&pila2);
    create(&ordenado);

    push(&pila, 1);
    push(&pila, 5);
    push(&pila, 7);
    push(&pila, 6);
    push(&pila, 9);
    push(&pila, 2);
    push(&pila, 10);
    push(&pila, 3);
    push(&pila, 8);
    push(&pila, 4);

    printf("Pila original \n");

    while (!isEmpty(pila))
    {
        aux = pop(&pila);
        printf("%d\n", aux);
        push(&pila2, aux);
    }
    
    while (!isEmpty(pila2))
    {
        while (!isEmpty(pila2))
        {
            popA = pop(&pila2);

            if (!isEmpty(pila2))
            {
                popB = pop(&pila2);
                if (popB > popA)
                {
                    push(&pila2, popA);
                    push(&pila, popB);
                }
                else
                {
                    push(&pila, popA);
                    push(&pila2, popB);
                }
            }
        }

        push(&ordenado, popA);

        while (!isEmpty(pila))
        {
            push(&pila2, pop(&pila));
        }
    }

    printf("\nPila ordenada \n");

    while (!isEmpty(ordenado))
    {
        printf("%d\n", pop(&ordenado));
    }

    return 0;
}