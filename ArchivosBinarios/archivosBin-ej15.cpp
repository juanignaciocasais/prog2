/*
El dueño de un local de venta de libros desea relevar el stock que posee en el local y en el
depósito, para realizar las compras del mes.
Para ello cuenta con dos archivos:
a) StockEnLocal.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el local, con el siguiente diseño:
a.1) Código de libro ( 4 dígitos )
a.3) Autor (20 caracteres)
a.6) Stock en el local (char)
a.2) Título del libro (30 caracteres)
a.4) Editorial (20 caracteres)
a.7) Genero ( 10 caracteres)
b) StockEnDeposito.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el depósito, con el siguiente diseño:
b.1) Código de libro ( 4 dígitos ) b.2) Stock en depósito (unsigned char)
Se pide desarrollar la metodología necesaria para escribir un algoritmo que emita un listado ordenado por
código de libro, con un renglón por cada libro que tenga faltante en stock sea en depósito, local o en
ambos lugares, con el siguiente formato:

    Libros faltantes
Código      Observación
9999        Falta en depósito
9999        Falta en local
9999        Falta en local y en depósito

    Total de libros en falta: 9999999
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int codigo;
    char autor[21];
    char stock[21];
    char titulo[31];
    char editorial[21];
    char genero[11];
} ST_LOCAL;

typedef struct
{
    int codigo;
    unsigned char stock;
} ST_DEPOSITO;

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

void apareoArchivos(FILE *local, FILE *deposito)
{
    ST_LOCAL stockLocal;
    ST_DEPOSITO stockDeposito;

    int totalFaltantes = 0;

    fread(&stockLocal, sizeof(ST_LOCAL), 1, local);
    fread(&stockDeposito, sizeof(ST_DEPOSITO), 1, deposito);

    while (!feof(local) && !feof(deposito))
    {
        if (stockLocal.codigo == stockDeposito.codigo)
        {
            if (stockLocal.stock == 0 && stockDeposito.stock == 0)
            {
                printf("%s\tFalta en local y en depósito", stockLocal.codigo);
                totalFaltantes++;
            }

            if (stockLocal.stock == 0 && stockDeposito.stock > 0)
            {
                printf("%s\tFalta en local", stockLocal.codigo);
                totalFaltantes++;
            }

            if (stockLocal.stock > 0 && stockDeposito.stock == 0)
            {
                printf("%s\tFalta en depósito", stockLocal.codigo);
                totalFaltantes++;
            }

            fread(&stockLocal, sizeof(ST_LOCAL), 1, local);
            fread(&stockDeposito, sizeof(ST_DEPOSITO), 1, deposito);
        }
        else if (stockLocal.codigo < stockDeposito.codigo)
        {
            if (stockLocal.stock == 0)
            {
                printf("%s\tFalta en local y en depósito", stockLocal.codigo);
                totalFaltantes++;
            }
            fread(&stockLocal, sizeof(ST_LOCAL), 1, local);
        }
        else
        {
            if (stockDeposito.stock == 0)
            {
                printf("%d\tFalta en Depósito\n", stockDeposito.codigo);
                totalFaltantes++;
            }
            fread(&stockDeposito, sizeof(ST_DEPOSITO), 1, deposito);
        }
    }

    while (!feof(local))
    {
        if (stockLocal.stock == 0)
        {
            printf("%d\tFalta en Local\n", stockLocal.codigo);
            totalFaltantes++;
        }
        fread(&stockLocal, sizeof(ST_LOCAL), 1, local);
    }

    while (!feof(deposito))
    {
        if (stockDeposito.stock == 0)
        {
            printf("%d\tFalta en Depósito\n", stockDeposito.codigo);
            totalFaltantes++;
        }
        fread(&stockDeposito, sizeof(ST_DEPOSITO), 1, deposito);
    }
    printf("Total de libros en falta: %d", totalFaltantes);
}

int main()
{
    system("clear");
    
    FILE *local = abrirArchivo("local.dat", "rb");
    FILE *deposito = abrirArchivo("deposito.dat", "rb");

    printf("Libros Faltantes\n");
    printf("Código\tObservaciòn\n");

    apareoArchivos(local, deposito);

    fclose(local);
    fclose(deposito);

    return 0;
}