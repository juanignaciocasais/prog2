#include <iostream>
#include "string.h"
using namespace std;

struct STR_NODO
{
    int dato;
    STR_NODO *ste;
};

struct STR_QUEUE {
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

void add(STR_QUEUE *queue, int valor)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->ste = NULL;

    if(queue->frente == NULL) {
        queue->frente = nodo;
    } else {
        queue->fin->ste = nodo;
    }
    
    queue->fin = nodo;
    return;
}

int remove(STR_QUEUE *queue) {
    STR_NODO *aux = queue->frente;
    int dato = aux->dato;
    queue->frente = aux->ste;

    if(queue->frente == NULL) {
        queue->fin = NULL;
    }

    free(aux);
    return dato;
}


void print(STR_QUEUE *queue)
{
    while (!isEmpty(*queue))
    {
        int valor = remove(queue);
        printf("%d\n", valor);
    }
}

int main()
{

    STR_QUEUE queue;
    create(&queue);

    add(&queue, 1);
    add(&queue, 2);
    add(&queue, 3);
    add(&queue, 4);
    add(&queue, 5);

    print(&queue);

    return 0;
}