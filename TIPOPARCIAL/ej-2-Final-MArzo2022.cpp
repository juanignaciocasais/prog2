#include <iostream>
#include "string.h"
#include <stdbool.h>
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

void push(STR_NODO **pila, int valor) {
    STR_NODO *nodo = (STR_NODO*)malloc(sizeof(STR_NODO));
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

bool esCapicua(STR_QUEUE *queue){

    STR_NODO *pila = NULL;

    STR_QUEUE cola;
    create(&cola);
    int largo = 0;
    while(!isEmpty(*queue)) {
       add(&cola,remove(queue));
       largo++;
    }

    int i = 1;
    float mitadLargo = (float)largo/2;  
    
    while(!isEmpty(cola) && mitadLargo >= i) {
        push(&pila, remove(&cola));
        i++;
    }

    if(largo % 2 != 0){
        remove(&cola);
    }

    while(!isEmpty(cola) && pila != NULL) {
        if(remove(&cola) != pop(&pila)){
            return false;
        }
    }

    return isEmpty(cola) && pila == NULL;
}

int main()
{

    STR_QUEUE queue;
    create(&queue);

    add(&queue, 3);
    add(&queue, 1);
    add(&queue, 2);
    add(&queue, 3);
    add(&queue, 2);
    add(&queue, 1);
    add(&queue, 3);

    if(esCapicua(&queue)){
        printf("TRUE\n");
    } else printf("FALSE\n");

    return 0;
}
