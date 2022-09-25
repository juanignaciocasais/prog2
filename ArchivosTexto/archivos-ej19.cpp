/*
Dado un archivo de productos codificados de 1 a 100, sin ningún orden, con el siguiente diseño:
código de producto (1..100) precio unitario (single)
y un conjunto de pedidos, y de cada uno se conoce: código de producto, y cantidad de unidades pedidas
(long). Los pedidos finalizan con un código de producto igual a 0.
Se pide:
 informar de cada pedido código de producto, unidades, precio unitario e importe
 al final del proceso:
o informar los códigos de productos que no fueron vendidos
o grabar un archivo de texto con el siguiente listado

    Listado de Facturación por producto
Código de Producto      Total facturado
        999                 99999.99

ESTRATEGIA
- Abrir archivo de productos en modo LEctura, recorrerlo y agregar los productos a un vector por
PUP ordenados por el cod de producto.
- Generar un vector por consola con los pedidos 
- Recorrer los pedidos, e ir tomando el precio para imprimir por consola lo pedido y a su vez 
    sumar el valor de lo facturado para el informe final
- Recorremos una vez el vector y Grabamos el archivo e imprimimos por consola la info pedida

*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define MAX_PRODUCTOS 5

typedef struct 
{
    int codigo;
    float precio;
    float totalFacturado; 
}ST_PRODUCTO;

typedef struct 
{
    int codigoProducto;
    int cantidadPedida;
}ST_PEDIDO;

FILE *abrirArchivo(char *fileName, char *mode)
{
    FILE *file = fopen(fileName, mode);
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", fileName);
        EXIT_FAILURE;
    }
    return file;
}

void pasarProductosAMemoria(FILE *file, ST_PRODUCTO vector[MAX_PRODUCTOS]){

    int i = 0;
    int codigoProducto = 0;
    ST_PRODUCTO producto;
    char buffer[255];
    while (fgets(buffer, 255, file) != NULL)
    {
        codigoProducto = atoi(strtok(buffer, ";"));
        vector[codigoProducto - 1].codigo = codigoProducto;
        vector[codigoProducto - 1].precio =  atoi(strtok(NULL, "\n"));  
        vector[codigoProducto - 1].totalFacturado = 0;
        i++;
    }
    return;
}

int main () {
    system("clear");

    FILE *archivoProductos = abrirArchivo("productos.txt", "r+");
    FILE *archivoListado = abrirArchivo("listado.txt", "wt");

    ST_PRODUCTO productos;
    ST_PEDIDO pedidos;
    ST_PRODUCTO vectorProductos[MAX_PRODUCTOS];
    float precioProducto = 0;

    pasarProductosAMemoria(archivoProductos, vectorProductos);
    
    fclose(archivoProductos);

    printf("Ingrese el código de producto: ");
    scanf("%d",&pedidos.codigoProducto);

    while(pedidos.codigoProducto != 0){

        printf("Ingrese cantidad pedida: ");
        scanf("%d",&pedidos.cantidadPedida);

        precioProducto = vectorProductos[pedidos.codigoProducto - 1].precio;
        vectorProductos[pedidos.codigoProducto - 1].totalFacturado += precioProducto * pedidos.cantidadPedida;

        printf("Cód. Prod: %d \tCant. Unid: %d \tPrecio Unid: %.2f\tImporte Total: %.2f\n", pedidos.codigoProducto, pedidos.cantidadPedida, precioProducto, precioProducto * pedidos.cantidadPedida);
        
        printf("Ingrese el código de producto: ");
        scanf("%d",&pedidos.codigoProducto);
    }

    fprintf(archivoListado,"\tListado de Facturación por producto\n");
    fprintf(archivoListado,"Código de Producto\tTotal facturado\n");

    printf("Código de Productos que no fueron vendidos\n");

    for(int i = 0; i < MAX_PRODUCTOS; i++) {

        if(vectorProductos[i].totalFacturado > 0){
            fprintf(archivoListado,"%d\t\t%.2f\n", i + 1, vectorProductos[i].totalFacturado);
        } else {
            printf("%d\n", vectorProductos[i].codigo );
        }
    }

    fclose(archivoListado);

    return 0;
}