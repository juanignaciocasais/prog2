/**
 * Abrir archivo de episodios de series
 *
 * Leer registro de episodio
 * Mientras haya registros
 *   Guardar id de serie
 *   Mientras haya registros y sea la misma serie
 *     Guardar temporada
 *     Mientras haya registros y sea la misma serie y misma temporada
 *       Acumular descargas de temporada
 *       Imprmir registro en el listado
 *       Leer registro de episodio
 *     Fin Mientras
 *     Imprimir totales por temporada
 *     Acumular totales por serie
 *   Fin Mientras
 *   Imprimir totales por serie
 *   Acumular total general
 * Fin Mientras
 * Imprimir total general
 *
 */
#include <iostream>
#include "string.h"
using namespace std;

struct Fecha
{
    char dia;
    char mes;
    short anio;
};

struct Episodio
{
    int idSerie;
    char nroTemporada;
    long int descargas;
    char titulo[21];
    unsigned char nroEpisodio;
    int fechaUltimaDescarga; // AAAAMMDD
};

FILE *abrir(const char *fileName, const char *modo);
void cerrar(FILE *file);
Episodio leer(FILE *file);
Episodio leerScanf(FILE *episodios);
int escribir(Episodio registro, FILE *file);
Fecha obtenerFecha(int fecha);

int main()
{
    FILE *episodios = abrir("episodios.txt", "r");
    Episodio episodio;
    int cantEpisodiosTotal = 0;
    int cantDescargasTotal = 0;
    episodio = leer(episodios);
    while (!feof(episodios))
    {
        int idSerie = episodio.idSerie;
        int cantEpisodiosSerie = 0;
        int cantDescargasSerie = 0;
        printf("Serie: %d\n", idSerie);
        while (!feof(episodios) && episodio.idSerie == idSerie)
        {
            printf("Temporada: %d\n", episodio.nroTemporada);
            printf("Nro. Episodio\tTitulo\tDescargas\tFecha\n");
            int nroTemporada = episodio.nroTemporada;
            int cantEpisodiosTemporada = 0;
            int cantDescargasTemporada = 0;
            while (!feof(episodios) && episodio.idSerie == idSerie && episodio.nroTemporada == nroTemporada)
            {
                Fecha fecha = obtenerFecha(episodio.fechaUltimaDescarga);
                printf("%d\t%s\t%d\t%02d/%02d/%04d\n", episodio.nroEpisodio, episodio.titulo, episodio.descargas, fecha.dia, fecha.mes, fecha.anio);
                cantEpisodiosTemporada++;
                cantDescargasTemporada += episodio.descargas;

                episodio = leer(episodios);
            }
            printf("-----------\nCant Episodios Temp: %d \n Cant Descargas Temp: %d\n", cantEpisodiosTemporada, cantDescargasTemporada);
            cantEpisodiosSerie += cantEpisodiosTemporada;
            cantDescargasSerie += cantDescargasTemporada;
        }
        printf("----------------\nCant Episodios Serie: %d \n Cant Descargas Serie: %d\n", cantEpisodiosSerie, cantDescargasSerie);

        cantEpisodiosTotal += cantEpisodiosSerie;
        cantDescargasTotal += cantDescargasSerie;
    }

    printf("----------------\nCant Episodios Total: %d \n Cant Descargas Total: %d\n", cantEpisodiosTotal, cantDescargasTotal);

    return 0;
}

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

void cerrar(FILE *file)
{
    fclose(file);
    file = NULL;
}

Episodio leer(FILE *episodios)
{
    Episodio episodio;
    char buffer[255];
    if (fgets(buffer, 255, episodios) != NULL)
    {
        episodio.idSerie = atoi(strtok(buffer, ","));
        episodio.nroTemporada = atoi(strtok(NULL, ","));
        episodio.descargas = atoi(strtok(NULL, ","));
        strcpy(episodio.titulo, strtok(NULL, ",\n"));
        // strncpy(episodio.titulo, strtok(NULL, ",\n"), 20);
        // strcpy(&episodio.titulo[20], "\0");
        episodio.nroEpisodio = atoi(strtok(NULL, ","));
        episodio.fechaUltimaDescarga = atoi(strtok(NULL, ","));
        Fecha fecha = obtenerFecha(episodio.fechaUltimaDescarga);
    }
    return episodio;
}

Episodio leerScanf(FILE *episodios)
{
    // No anda porque hay texto y espacios en el archivo
    Episodio episodio;
    char buffer[255];
    fscanf(episodios, "%d,%d,%d,%s,%d,%d", 
        &episodio.idSerie, 
        &episodio.nroTemporada, 
        &episodio.descargas, 
        episodio.titulo, 
        &episodio.nroEpisodio, 
        &episodio.fechaUltimaDescarga);
    return episodio;
}

int escribir(Episodio registro, FILE *file)
{
    return fwrite(&registro, sizeof(Episodio), 1, file);
}

Fecha obtenerFecha(int fechaEntero)
{
    Fecha fecha;
    fecha.anio = fechaEntero / 10000;
    fecha.mes = (fechaEntero % 10000) / 100;
    fecha.dia = fechaEntero % 100;
    return fecha;
}