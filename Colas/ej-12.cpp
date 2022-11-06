#include <iostream>
#include "string.h"
using namespace std;

struct STR_DATO
{
    char apellido[21];
    char nombre[21];
};

struct STR_NODO
{
    STR_DATO dato;
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

void add(STR_QUEUE *queue, STR_DATO valor)
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

STR_DATO remove(STR_QUEUE *queue) {
    STR_NODO *aux = queue->frente;
    STR_DATO dato = aux->dato;
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
        STR_DATO valor = remove(queue);
        printf("%s, %s\n", valor.apellido, valor.nombre);
    }
}

void anexar(STR_QUEUE *queueA, STR_QUEUE *queueB, STR_QUEUE *queueAB) {
    while(!isEmpty(*queueA)) {
        add(queueAB, remove(queueA));
    }

    while(!isEmpty(*queueB)) {
        add(queueAB, remove(queueB));
    }
}

int main()
{

    STR_QUEUE queueA;
    create(&queueA);

    STR_DATO alumno;

    printf("Complete la COLA A\n");
    printf("Ingrese un Apellido (Fin para terminar):");
    scanf("%s", &alumno.apellido);
    while (strcmp(alumno.apellido, "Fin") != 0)
    {
        printf("Ingrese un Nombre:");
        scanf("%s", &alumno.nombre);

        add(&queueA, alumno);

        printf("Ingrese un Apellido (Fin para terminar):");
        scanf("%s", &alumno.apellido);
    }

    STR_QUEUE queueB;
    create(&queueB);
    printf("Complete la COLA B\n");
    printf("Ingrese un Apellido (Fin para terminar):");
    scanf("%s", &alumno.apellido);
    while (strcmp(alumno.apellido, "Fin") != 0)
    {
        printf("Ingrese un Nombre:");
        scanf("%s", &alumno.nombre);

        add(&queueB, alumno);

        printf("Ingrese un Apellido (Fin para terminar):");
        scanf("%s", &alumno.apellido);
    }

    STR_QUEUE queueAB;
    create(&queueAB);

    anexar(&queueA, &queueB, &queueAB);
    print(&queueAB);

    return 0;
}