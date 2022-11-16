/*
Dado el archivo binario libros.dat, que posee datos desordenados sobre libros 
valiosos con la siguiente estructura:
ISBN Nombre Año edición Valor
Entero (10 dígitos) Char(40) Entero (1600 - 1700) Float (2 decimales)
Se desea obtener un listado agrupado por ISBN ordenado por año indicando: ISBN, Nombre y Valor Promedio.
Restricciones:
● No posee memoria estática suficiente para almacenar el archivo en memoria.
● No dispone de espacio suficiente en disco para duplicar el archivo.

*/

#include <iostream>
#include "string.h"

using namespace std;

typedef struct dato
{
    int isbn;
    char nombre[40];
    int anioEdicion;
    float precio;
} STR_DATO;

typedef struct nodo
{
    STR_DATO dato;
    struct nodo *ste;
} STR_NODO;

typedef struct
{
    STR_NODO *frente;
    STR_NODO *fin;
} STR_QUEUE;

void discardChars();
//***** FUNCIONES ARCHIVOS *************************
FILE *abrir(const char *fileName, const char *modo);
void cerrar(FILE * file);
int leer(STR_DATO *registro, FILE * file);
int escribir(STR_DATO registro, FILE * file);
//***** FUNCIONES PILAS *************************
void create(STR_NODO **pila);
bool isEmpty(STR_NODO *head);
void push(STR_NODO **head, STR_DATO dato);
STR_DATO pop(STR_NODO **head);
void clear(STR_NODO **head);
void createCola(STR_QUEUE *queue);
//***** FUNCIONES COLAS *************************
void add(STR_QUEUE *queue, STR_DATO dato);
STR_DATO remove(STR_QUEUE *queue);
bool isEmptyCola(STR_QUEUE *queue);
//***** FUNCIONES LISTAS *************************
STR_NODO *insertInFront(int valor, STR_NODO **lista);
STR_NODO *insertAtEnd(int valor, STR_NODO **lista);
STR_NODO *insertOrdered(STR_DATO valor, STR_NODO **lista);
void clearList(STR_NODO **lista);
STR_NODO *search(STR_NODO *lista, int valor);
STR_DATO deleteFirst(STR_NODO **lista);
void sort(STR_NODO **lista);
int count(STR_NODO *listaAux);
void cargarLista(STR_NODO **lista, int desde, int hasta);
void print(STR_NODO *listaAux);


void cargaDato(STR_NODO **pila);
void imprimirArticulos(STR_NODO *pila);
void cargarPedido(STR_QUEUE *queue);
void imprimirCola(STR_QUEUE *cola);

int main()
{
    FILE * archivoLibros = abrir("libros.dat", "rb");
    STR_NODO *lista;
    STR_DATO libro;
    create(&lista);

    leer(&libro,archivoLibros);

    while(!feof(archivoLibros)){
        insertOrdered(libro,&lista);
        leer(&libro,archivoLibros);
    }

    cerrar(archivoLibros);
    
    int anioEdicion = 0;
    
    if(!isEmpty(lista)){
        libro = deleteFirst(&lista);
    }
    
    while(!isEmpty(lista)){
        
        anioEdicion = libro.anioEdicion;

        printf("Año de Edición: %d", libro.anioEdicion);
        
        while(!isEmpty(lista) && anioEdicion == libro.anioEdicion){
            printf("%d\t%s\t%d\t%0.2f\n", libro.isbn, libro.nombre, libro.precio);
            libro = deleteFirst(&lista);
        }
    }

    return 0;
}

//***** FUNCIONES ARCHIVOS *************************

FILE *abrir(const char *fileName, const char *modo)
{
    FILE *file = fopen(fileName, modo);
    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }

    return file;
}

void cerrar(FILE * file) {
    fclose(file);
    file = NULL;
}

int leer(STR_DATO *registro, FILE * file) {
    return fread(registro, sizeof(STR_DATO), 1, file);
}

int escribir(STR_DATO registro, FILE * file) {
    return fwrite(&registro, sizeof(STR_DATO), 1, file);
}

//***** FUNCIONES PILAS *************************

void create(STR_NODO **pila){
    *pila = NULL;
}

bool isEmpty(STR_NODO *head)
{
    return head == NULL;
}

void push(STR_NODO **head, STR_DATO dato){
    //creacion del nodo
    STR_NODO *nodo = (STR_NODO*)(malloc(sizeof(STR_NODO)));
    nodo->dato = dato;
    nodo->ste = NULL;

    //insertamos el nuevo nodo en la pila
    nodo->ste = *head;
    *head = nodo;
    return; 
}

STR_DATO pop(STR_NODO **head){
    STR_DATO valor = (*head)->dato;
    STR_NODO *aux = *head;
    *head = (*head)->ste;

    free(aux);

    return valor;
}

void clear(STR_NODO **head){
    while(!isEmpty(*head)){
        pop(head);
    }
    *head = NULL;
}

//***** FUNCIONES COLAS *************************

void createCola(STR_QUEUE *queue)
{
    queue->frente = NULL;
    queue->fin = NULL;
}

void add(STR_QUEUE *queue, STR_DATO dato)
{

    STR_NODO *nodo = (STR_NODO *)(malloc(sizeof(STR_NODO)));
    nodo->dato = dato;
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

STR_DATO remove(STR_QUEUE *queue)
{
    STR_NODO *aux = queue->frente;
    STR_DATO valor = aux->dato;
    queue->frente = aux->ste;
    if (queue->frente == NULL)
    {
        queue->fin = NULL;
        free(aux);
    }
    return valor;
}

bool isEmptyCola(STR_QUEUE *queue)
{
    return queue->frente == NULL && queue->fin == NULL;
}

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

void cargaDato(STR_NODO **pila){
    
    STR_DATO articulo;

    printf("Ingrese numero en pila: \n");
    scanf ("%d",&articulo.dato);
    
    discardChars();
       
    push(pila, articulo);

    return;
}

void imprimirArticulos(STR_NODO *pila){
    
    STR_DATO articulo;

    while(!isEmpty(pila)){
        articulo = pop(&pila);
        printf("%d\n", articulo.dato);
    }
}

void cargarPedido(STR_QUEUE *queue){

    STR_DATO pedido;
    printf("Ingrese numero en cola: \n");
    scanf ("%d",&pedido.dato);
    
    discardChars();
       
    add(queue, pedido);

    return;
}

void imprimirCola(STR_QUEUE *cola){
    STR_DATO pedido;

    while(!isEmptyCola(cola)){
        pedido = remove(cola);
        printf("%d\n",pedido.dato);
    }

}

//******** FUNCIONES LISTAS *************************

STR_NODO *insertInFront(int valor, STR_NODO **lista)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato.dato = valor;
    nodo->ste = *lista;

    *lista = nodo;
    return nodo;
}

STR_NODO *insertAtEnd(int valor, STR_NODO **lista)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato.dato = valor;
    nodo->ste = NULL;

    if (isEmpty(*lista))
    {
        *lista = nodo;
    }
    else
    {
        STR_NODO *listaAux = *lista;
        while (listaAux->ste != NULL)
        {
            listaAux = listaAux->ste;
        }
        listaAux->ste = nodo;
    }

    return nodo;
}

STR_NODO *insertOrdered(STR_DATO valor, STR_NODO **lista)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato.isbn = valor.isbn;
    nodo->ste = NULL;

    STR_NODO *listaAux = *lista;
    STR_NODO *nodoAnt = NULL;
    while (listaAux != NULL && listaAux->dato.anioEdicion < valor.isbn)
    {
        nodoAnt = listaAux;
        listaAux = listaAux->ste;
    }

    if (nodoAnt == NULL)
    {
        *lista = nodo;
    }
    else
    {
        nodoAnt->ste = nodo;
    }

    nodo->ste = listaAux;
    return nodo;
}

void clearList(STR_NODO **lista)
{
    STR_NODO *aux = NULL;
    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->ste;
        free(aux);
    }
}

STR_NODO *search(STR_NODO *lista, int valor)
{
    STR_NODO *listaAux = lista;
    while (listaAux != NULL && listaAux->dato.dato != valor)
    {
        listaAux = listaAux->ste;
    }
    return listaAux;
}

STR_DATO deleteFirst(STR_NODO **lista)
{
    int dato = (*lista)->dato;
    STR_NODO *aux = *lista;
    *lista = (*lista)->ste;
    free(aux);
    return dato;
}

void sort(STR_NODO **lista)
{
    STR_NODO *listaAux;
    create(&listaAux);
    int dato;
    while (*lista != NULL)
    {
        dato = deleteFirst(lista);
        insertOrdered(dato, &listaAux);
    }

    *lista = listaAux;
}

int count(STR_NODO *listaAux)
{
    int cant = 0;
    while (listaAux != NULL)
    {
        listaAux = listaAux->ste;
        cant++;
    }

    return cant;
}

void print(STR_NODO *listaAux)
{
    while (listaAux != NULL)
    {
        printf("%d   ", listaAux->dato.dato);
        listaAux = listaAux->ste;
    }
    printf("\n");
    return;
}   
