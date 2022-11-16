/*
Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar
un procedimiento que genere otra cola COLAB por apareo del campo ARRIBO del
registro (define orden creciente en ambas). Nota: COLA y COLB dejan de ser útiles
después​ ​ del​ ​ apareo.
*/

#include <iostream>
#include "string.h"
using namespace std;

struct ST_DATO
{
    int arribo;
};

struct STR_NODO
{
    ST_DATO dato;
    STR_NODO *ste;
};

struct STR_QUEUE
{
    STR_NODO *frente;
    STR_NODO *fin;
};

void create(STR_QUEUE *queue)
{
    queue->fin = NULL;
    queue->frente = NULL;
}

bool isEmpty(STR_QUEUE queue)
{
    return queue.fin == NULL && queue.frente == NULL;
}

void add(STR_QUEUE *queue, ST_DATO valor)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->ste = NULL;

    if (queue->frente == NULL)
    {
        queue->frente = nodo;
    }
    else
    {
        queue->fin->ste = nodo;
    }

    queue->fin = nodo;
    return;
}

ST_DATO remove(STR_QUEUE *queue)
{
    STR_NODO *aux = queue->frente;
    ST_DATO dato = aux->dato;
    queue->frente = aux->ste;

    if (queue->frente == NULL)
    {
        queue->fin = NULL;
    }

    free(aux);
    return dato;
}

void print(STR_QUEUE *queue)
{
    while (!isEmpty(*queue))
    {
        ST_DATO valor = remove(queue);
        printf("%d\n", valor.arribo);
    }
}

void apareo(STR_QUEUE *COLA, STR_QUEUE *COLB, STR_QUEUE COLAB)
{

    STR_QUEUE aux;
    create(&aux);
    ST_DATO datoA;
    ST_DATO datoB;

    if (COLA != NULL && COLB != NULL)
    {
        datoA = remove(COLA);
        datoB = remove(COLB);
    }

    while (COLA != NULL && COLB != NULL)
    {
        if (datoA.arribo >= datoB.arribo)
        {
            add(&COLAB, datoB);
            if(COLB != NULL){
                datoB = remove(COLB);
            }
        }
        else
        {
            add(&COLAB, datoA);
            if(COLA != NULL){
                datoA = remove(COLA);
            }
        }
    }

    while (COLA != NULL)
    {
        add(&COLAB, datoA);
        datoA = remove(COLA);
    }

    while (COLB != NULL)
    {
        add(&COLAB, datoB);
        datoA = remove(COLB);
    }
}

int main()
{

    STR_QUEUE COLA;
    STR_QUEUE COLB;
    STR_QUEUE COLAB;
    create(&COLA);
    create(&COLB);
    create(&COLAB);

    for (int i = 0; i < 10; i++)
    {
        ST_DATO valor = {i * 2};
        add(&COLA, valor);
    }

    for (int i = 1; i <= 10; i++)
    {
        ST_DATO valor = {(i * 2) - 1};
        add(&COLB, valor);
    }

    apareo(&COLA, &COLB, COLAB);

    print(&COLAB);

    return 0;
}
