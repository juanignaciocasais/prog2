/*
Definir una función INVERSA que evalúe dos conjuntos de caracteres separados por
un punto y retorne True si los conjuntos son inversos (ej: ABcDe.eDcBA) o False si
no lo son. Los conjuntos deben ingresarse por teclado. (Definir parámetros y
codificar).
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

bool inversa(STR_NODO *pila, char *cadena)
{

    int i = 0;

    while (*(cadena + i) != '.' && *(cadena + i) != '\0')
    {
        push(&pila, *(cadena + i));
        i++;
    }

    i++;
    char dato;

    if (!isEmpty(pila))
    {
        dato = pop(&pila);
    }
    else return false;

    while (*(cadena + i) == dato)
    {
        i++;
        if (!isEmpty(pila))
        {
            dato = pop(&pila);
        }
    }

    if (*(cadena + i) == '\0' && isEmpty(pila))
    {
        return true;
    }

    return false;
}

int main()
{

    STR_NODO *pila = NULL;
    char cadena[256];
    printf("Ingrese los conjuntois separados por un punto: ");
    scanf("%s", &cadena);

    if (inversa(pila, cadena))
    {
        printf("La cadena es inversa\n");
    }
    else {
        printf("La cadena No es inversa\n");
    }

    return 0;
}