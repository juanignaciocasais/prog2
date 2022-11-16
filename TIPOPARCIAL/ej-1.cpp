/*
Un corralón recibe en horario de oficina material de construcción que entrega durante los fines de semana.
Diariamente un empleado da de alta los artículos en el sistema respetando el orden de llegada, para lo cual
imputa el código de la ubicación temporal en la playa, código de barra y precio de ventas; la carga queda en
memoria.
En una etapa posterior, fuera de horario de oficina, los empleados trasladan a la ubicación definitiva cada uno
de estos artículos recibidos; para asistirse, imprimen la nómina de bultos en el orden inverso al que fueron
recibidos, con los tres datos relevados oportunamente.
Los sábados por la mañana un empleado recibe los pedidos que los clientes realizan telefónicamente; ingresa
al sistema el nombre, dirección, código postal, código del artículo (únicamente puede comprar un sólo tipo) y
la cantidad.
Todo queda en memoria hasta que por la tarde, cuando dejan de recibirse llamados, se imprime el listado de
clientes en el mismo orden que fueron recibidos, para realizar el delivery.
a. Desarrollar la estrategia y estructuras para el problema enunciado y para los puntos siguientes:
b. Realizar la carga de un artículo recibido.
c. Realizar la impresión de los artículos.
d. Realizar el alta de un pedido.
e. Realizar la impresión del listado para el delivery
*/

#include <iostream>
using namespace std;

/*
a - ESTRATEGIA
    Armo la funcion para la carga de un artículo utilizando una pila para que al finalizar
    la carga luego pueda imprimir la lista de manera inversa a la ingresada.
    Armo la funcion para cargar pedidos en una cola y luego al imprimirlos queden el el mismo 
    orden al ingresado
*/

typedef struct Nodo{
    char codPlaya[11];
    int codBarras;
    float precio;
}ST_ARTICULO;

typedef struct {
    Nodo dato;
    ST_NODO_P *ste;
}ST_NODO_P;

typedef struct {
    char nombre[11];
    char direccion[11];
    int codPostal;
    int codBarras;
    int cantArticulos;
}ST_PEDIDO;

typedef struct {
    ST_NODO_C *frente;
    ST_NODO_C *fin;
}ST_QUEUE;

typedef struct {
    ST_PEDIDO dato;
    ST_QUEUE *ste;
}ST_NODO_C;

void push(ST_NODO_P **pila, ST_ARTICULO valor)
{
    ST_NODO_P *nodo = (ST_NODO_P *)malloc(sizeof(ST_NODO_P));
    nodo->dato = valor;
    nodo->ste = NULL;

    nodo->ste = *pila;
    *pila = nodo;
    return;
}

ST_ARTICULO pop(ST_NODO_P **pila)
{
    ST_ARTICULO dato = (*pila)->dato;
    ST_NODO_P *aux = *pila;
    *pila = (*pila)->ste;

    free(aux);
    return dato;
}

void add(ST_QUEUE *queue, ST_PEDIDO valor)
{
    ST_NODO_C *nodo = (ST_NODO_C *)malloc(sizeof(ST_NODO_C));
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

ST_PEDIDO remove(ST_QUEUE *queue) {
    ST_NODO_C *aux = queue->frente;
    ST_PEDIDO dato = aux->dato;
    queue->frente = aux->ste;

    if(queue->frente == NULL) {
        queue->fin = NULL;
    }

    free(aux);
    return dato;
}

bool isEmpty(ST_QUEUE queue)
{
    return queue.fin == NULL && queue.frente == NULL;
}

void cargarArticulo (ST_NODO_P *pila) {
    ST_ARTICULO articulo;

    printf("Ingrese Código Ubicación:");
    scanf("%s", articulo.codPlaya);

    printf("Ingrese Código de Barras:");
    scanf("%d", articulo.codBarras);

    printf("Ingrese precio:");
    scanf("%f", articulo.precio);

    push(&pila, articulo);
}

void imprimirArticulos(ST_NODO_P *pila) {
    ST_ARTICULO articulo;

    printf("Ubicación temporal - Código de barra - Precio de ventas\n");

    while(pila != NULL) {
        articulo = pop(&pila);
        printf("%s \t %d \t %f", articulo.codPlaya, articulo.codBarras, articulo.precio);
    }
}

void cargarPedido(ST_QUEUE *cola) {
    ST_PEDIDO pedido;

    printf("Ingrese Nombre:");
    scanf("%s", pedido.nombre);

    printf("Ingrese Dirección:");
    scanf("%s", pedido.direccion);

    printf("Ingrese Código Artículo:");
    scanf("%d", pedido.codBarras);

    printf("Ingrese Cantidad pedido:");
    scanf("%d", pedido.cantArticulos);

    add(cola, pedido);
}

void imprimirPedido(ST_QUEUE *cola) {
    ST_PEDIDO pedido;

    printf("Nombre - Dirección - Cod Artículo - Cantidad\n");

    while(!isEmpty(*cola)){
        pedido = remove(cola);
        printf("%s %s %d %d\n", pedido.nombre, pedido.direccion, pedido.codBarras, pedido.cantArticulos);
    }
}