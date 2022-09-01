/*
Declarar un struct que defina una variable del tipo vector de caracteres, llamada nombre, y otra
que sea del tipo entero, llamada edad y ...
a) En la función main, asigne el valor “Kokumo” y “30” para nombre y edad respectivamente.
b) Luego, invoque una función que reciba el struct por parámetro y que imprima el valor de
ambas variables del struct.
c) Dentro de esa misma función, cambie los valores de las variables en cuestión y muestre
nuevamente sendos valores.
d) De regreso en el main, e inmediatamente después de la llamada a la función, imprima los
valores del struct; analice qué valores se imprimieron en pantalla.
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;

typedef struct {
    char nombre[20];
    int edad;
}ST_PERSONA;

void imprimirPorCopia(ST_PERSONA persona) {
    printf("%s\n%d\n", persona.nombre, persona.edad);
    persona.edad = 25;
    strcpy(persona.nombre,"CARLOS");
}

void imprimirPorReferencia(ST_PERSONA &persona) {
    printf("%s\n%d\n", persona.nombre, persona.edad);
    persona.edad = 25;
    strcpy(persona.nombre,"MARIA");
}

void imprimirPorPuntero(ST_PERSONA *ptrPersona){
    printf("%s\n%d\n", (*ptrPersona).nombre, (*ptrPersona).edad);
    (*ptrPersona).edad = 10;
    strcpy((*ptrPersona).nombre,"PEDRO");
}

int main()
{
    ST_PERSONA persona;

    printf("Ejercicio 4\n");

    persona.edad = 30;
    strcpy(persona.nombre,"Kokumbo");

    imprimirPorCopia(persona);
    printf("-----------\n");

    printf("%s\n%d\n\n", persona.nombre, persona.edad);

    printf("Ejercicio 5\n");

    imprimirPorReferencia(persona);
    printf("-----------\n");
    printf("%s\n%d\n", persona.nombre, persona.edad);

    printf("Ejercicio 5 con punteros\n");

    ST_PERSONA *ptrPersona = &persona;

    imprimirPorPuntero(ptrPersona);
    printf("-----------\n");
    printf("%s\n%d\n", (*ptrPersona).nombre, (*ptrPersona).edad);

    return 0;
}