/*
El dueño de un local de venta de juegos para distintas consolas necesita desarrollar un algoritmo
que grabe un archivo, JuegosPorConsola.dat, ordenado por consola, con un solo registro por consola
según el siguiente diseño:
a) Consola (10 caracteres) b) Cantidad de juegos ( 4 dígitos )
Para obtener la información solicitada se cuenta con el archivo Juegos.dat, ordenado por consola, 
con un registro por cada juego que se encuentra en el local, con el siguiente diseño:
1) Código del juego ( 6 dígitos )
3) Stock en el local (char)
2) Titulo del Juego (30 caracteres)
4) Consola (10 caracteres)

ESTRATEGIA
- Abrir el archivo binario Juegos.dat en modo Lectura.
- Abrir el archivo binario JuegosPorConsola.dat en modo escritura.
- Recorrer el archivo Juegos.dat e ir sumando los juegos que hay por cada consola.
- Al momento de detectar un cambio de consola grabar los datos de esa consola ne el archivo nuevo.
- Cerrar los 2 archivos
*/

#include <stdlib.h>
#include <stdio.h>
#include "string.h"

typedef struct 
{
    char consola[11];
    int cantJuegos;
}ST_CONSOLA;

typedef struct 
{
    int codigo;
    char stock;
    char titulo[31];
    char consola[11];
}ST_JUEGO;

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

int main() {

    FILE *juegos = abrirArchivo("Juegos.dat", "rb");
    FILE *juegosPorConsola = abrirArchivo("JuegosPorConsola.dat", "wb");

    ST_JUEGO st_juego;
    ST_CONSOLA st_consola;

    char consola[11];
    int cantJuegos = 0;

    fread(&st_juego,sizeof(ST_JUEGO),1,juegos);
    while(!feof(juegos)) {

        strcpy(consola, st_juego.consola);

        while(!feof(juegos) && strcmp(consola, st_juego.consola)) {
            cantJuegos++;
            fread(&st_juego,sizeof(ST_JUEGO),1,juegos);
        }
        
        strcpy(st_consola.consola, consola);
        st_consola.cantJuegos = cantJuegos;

        fwrite(&st_consola, sizeof(ST_CONSOLA),1,juegosPorConsola);
    }

    fclose(juegos);
    fclose(juegosPorConsola);

    return 0;
}