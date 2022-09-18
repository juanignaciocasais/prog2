/*
Una aplicación para descargas de Series posee la información en un archivo binario,
Episodios.dat, con un registro por cada episodio, ordenado ascendente por Id_Serie y Número de
temporada, con el siguiente diseño:
1) Id_Serie ( 9 dígitos )
3) Número de temporada (1..12)
5) Cantidad de descargas (long)
2) Título del episodio (20 caracteres)
4) Número de episodio (unsigned char)
6) Fecha de última descarga (aaaammdd)
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int idSerie;
    int temporada;
    long cantDescargas;
    char titulo[21];
    int episodio;
    int fechaUltDescarga;
} ST_SERIE;

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

void corteDeControlArchivo(FILE * archivo)
{
    ST_SERIE serie;

    int idSerie = 0;
    int temporada = 0;
    int episodio = 0;

    int cantTotalDescargasSeries = 0;
    int cantTotalTemporadas = 0;
    int cantTotalSeries = 0;

    int cantDescargasTemporadas = 0;
    int cantEpisodios = 0;
    int cantTemporadas = 0;
    int cantTotalEpisodios = 0;

    printf("\t\tListado de Descargas de Series\n");

    fread(&serie, sizeof(ST_SERIE), 1, archivo);

    while (!feof(archivo))
    {
        idSerie = serie.idSerie;

        printf("Serie: %d\n", idSerie);

        while (!feof(archivo) && idSerie == serie.idSerie)
        {
            temporada = serie.temporada;
            cantEpisodios = 0;
            cantDescargasTemporadas = 0;
            cantTotalDescargasSeries = 0;

            printf("Temporada: %d\n", temporada);
            printf("N. de Episodio - Título del Episodio - Cant. descargas - Fecha de última descarga\n");
            
            while (!feof(archivo) && idSerie == serie.idSerie && temporada == serie.temporada)
            {

            printf("%d\t%s %d %d", serie.episodio, serie.titulo, serie.cantDescargas , serie.fechaUltDescarga);
            
            cantEpisodios++;
            cantDescargasTemporadas += serie.cantDescargas;
            cantTotalEpisodios += cantEpisodios;
            cantTotalDescargasSeries += serie.cantDescargas;
            fread(&serie, sizeof(ST_SERIE), 1, archivo);
            }
            cantTemporadas++;

            printf("Cant. de Episodios de la Serie: %d", cantEpisodios);
            printf("Total descargas de la temporada: %d", cantDescargasTemporadas);
        }
        printf("Cant. Total de Episodios de la Serie: %d", cantTotalEpisodios);
        printf("Cant. Total de Descargas de la Serie: %d", cantTotalDescargasSeries);
        cantTotalSeries++;
    }
    printf("***Total General de series: %d", cantTotalSeries);
}


int main(){

    system("clear");

    FILE *series = abrirArchivo("episodios.dat", "rb");

    corteDeControlArchivo(series);

    fclose(series);
    return 0;
}
