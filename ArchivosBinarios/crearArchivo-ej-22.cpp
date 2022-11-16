#include <iostream>
#include "string.h"
using namespace std;

struct Destino {
    int numDeDestino;
    float distanciaEnKM;
};

struct Viaje {
    char patente[7];
    int numDeDestino;
    int numDeChofer;
};

struct Chofer {
    int numChofer;
    char nombre[26];
};

FILE *abrir(char *fileName, char *mode)
{
    FILE *file = fopen(fileName, mode);
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", fileName);
        EXIT_FAILURE;
    }
    return file;
}

/*
void cargarChoferes (FILE *file) {
    Chofer choferes = {};

    choferes.numChofer = 1;
    strcpy(choferes.nombre, "pedro");
    fwrite(&choferes, sizeof(choferes), 1, file);

    choferes.numChofer = 2;
    strcpy(choferes.nombre, "pablo");
    fwrite(&choferes, sizeof(choferes), 1, file);

    choferes.numChofer = 3;
    strcpy(choferes.nombre, "martin");
    fwrite(&choferes, sizeof(choferes), 1, file);

    choferes.numChofer = 4;
    strcpy(choferes.nombre, "mariano");
    fwrite(&choferes, sizeof(choferes), 1, file);

    choferes.numChofer = 5;
    strcpy(choferes.nombre, "leandro");
    fwrite(&choferes, sizeof(choferes), 1, file);

    choferes.numChofer = 6;
    strcpy(choferes.nombre, "joaquin");
    fwrite(&choferes, sizeof(choferes), 1, file);

    choferes.numChofer = 7;
    strcpy(choferes.nombre, "jose");
    fwrite(&choferes, sizeof(choferes), 1, file);

    choferes.numChofer = 8;
    strcpy(choferes.nombre, "agustin");
    fwrite(&choferes, sizeof(choferes), 1, file);

    choferes.numChofer = 9;
    strcpy(choferes.nombre, "leo");
    fwrite(&choferes, sizeof(choferes), 1, file);
   

    return;
}*/
void cargarDestinos (FILE *archDestino) {
    Destino destinos = {};

    destinos.numDeDestino = 1;
    destinos.distanciaEnKM = 10;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 2;
    destinos.distanciaEnKM = 110;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 3;
    destinos.distanciaEnKM = 210;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 4;
    destinos.distanciaEnKM = 510;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 5;
    destinos.distanciaEnKM = 100;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 6;
    destinos.distanciaEnKM = 300;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 7;
    destinos.distanciaEnKM = 410;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 8;
    destinos.distanciaEnKM = 710;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 9;
    destinos.distanciaEnKM = 1110;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 10;
    destinos.distanciaEnKM = 1000;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 11;
    destinos.distanciaEnKM = 1020;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 100;
    destinos.distanciaEnKM = 10;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 101;
    destinos.distanciaEnKM = 110;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 102;
    destinos.distanciaEnKM = 210;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 103;
    destinos.distanciaEnKM = 510;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 104;
    destinos.distanciaEnKM = 100;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 105;
    destinos.distanciaEnKM = 300;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 106;
    destinos.distanciaEnKM = 410;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 107;
    destinos.distanciaEnKM = 710;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 108;
    destinos.distanciaEnKM = 1110;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 109;
    destinos.distanciaEnKM = 1000;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    destinos.numDeDestino = 116;
    destinos.distanciaEnKM = 1020;
    fwrite(&destinos, sizeof(destinos), 1, archDestino);

    return;
}
void cargarArchivoViajes(FILE *file)
{
    Viaje viajes;

    strcpy(viajes.patente, "abc123");
    viajes.numDeDestino = 109;
    viajes.numDeChofer = 1;

    fwrite(&viajes, sizeof(viajes), 1, file);

    strcpy(viajes.patente, "diw194");
    viajes.numDeDestino = 116;
    viajes.numDeChofer = 2;

    fwrite(&viajes, sizeof(viajes), 1, file);

    strcpy(viajes.patente, "koe279");
    viajes.numDeDestino = 107;
    viajes.numDeChofer = 3;

    fwrite(&viajes, sizeof(viajes), 1, file);

    strcpy(viajes.patente, "wjc294");
    viajes.numDeDestino = 108;
    viajes.numDeChofer = 4;

    fwrite(&viajes, sizeof(viajes), 1, file);

    strcpy(viajes.patente, "sfb132");
    viajes.numDeDestino = 104;
    viajes.numDeChofer = 5;

    fwrite(&viajes, sizeof(viajes), 1, file);

    strcpy(viajes.patente, "sdf345");
    viajes.numDeDestino = 105;
    viajes.numDeChofer = 6;

    fwrite(&viajes, sizeof(viajes), 1, file);

    strcpy(viajes.patente, "fdg234");
    viajes.numDeDestino = 103;
    viajes.numDeChofer = 7;

    fwrite(&viajes, sizeof(viajes), 1, file);

    strcpy(viajes.patente, "shm462");
    viajes.numDeDestino = 100;
    viajes.numDeChofer = 8;

    fwrite(&viajes, sizeof(viajes), 1, file);

    strcpy(viajes.patente, "rju674");
    viajes.numDeDestino = 101;
    viajes.numDeChofer = 9;

    fwrite(&viajes, sizeof(viajes), 1, file);

    strcpy(viajes.patente, "sdg243");
    viajes.numDeDestino = 116;
    viajes.numDeChofer = 10;

    fwrite(&viajes, sizeof(viajes), 1, file);

    return;
}

int main () {

    FILE *archivoDestinos = abrir("Destinos.dat", "wb");
    FILE *archivoViajes = abrir("Viajes.dat", "wb");

    cargarDestinos(archivoDestinos);
    cargarArchivoViajes(archivoViajes);

    fclose(archivoDestinos);
    fclose(archivoViajes);

    return 0;
}