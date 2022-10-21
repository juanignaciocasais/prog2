/*
Una empresa que distribuye mercadería hacia distintas localidades del interior dispone de los
siguientes archivos:
Un archivo “Destinos.dat”, con información de la distancia a cada uno de los destinos y con
el siguiente diseño de registro:
a.1) número de destino (3 dígitos) a.2) distancia en kilómetros (float)
También se dispone de otro archivo “Viajes.dat”, con los viajes realizados por cada camión y 
con el siguiente diseño de registro:
b.1) patente del camión (6 caracteres, no son más de 200 camiones) b.2) número de destino 
b.3) número de chofer (1..150)
Se pide desarrollar la metodología necesaria para realizar un programa que informe:
1. Cantidad de viajes realizados a cada destino
2. Número de chofer con menor cantidad de km recorridos
3. Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.

ESTRATEGIA
- Abrir archivo Destinos.dat y pasar la distancia en kms con pup a un vector de 999 posiciones
 con un dato extra de cantidad de Viajes.
- Generar otro Vector de 150 posiciones para sumar los km realizados por cada chofer
- Y otro vector con las patentes de los camionies que viajearon al destino 116
- Abrir el archivo viajes para recorrerlo e ir completando los otros vectores.
    · Tomando el número de destino, sumar un viaje, e ir a buscar el km y sumarlo al vector 
      de choferes.
    · Si viajó al destino 116, agregar la patente al vector de patentes
- Informo resultados: 
- Al finalizar el archivo recorrer el vector de destinos informando la cantidad de viajes a 
    cada destino
- Recorrer el vector de choferes para sacar el de menor kilometraje e informar
- Recorrer el vector patentes para informar los camiones que viajaron al destino 116.
*/

#include <iostream>
#include "string.h"
using namespace std;

#define MAX_CHOFERES 150

typedef struct {
    int destino;
    float distanciaEnKm;
} ST_DESTINO;

typedef struct {
    int destino;
    float distanciaEnKm;
    int cantViajes;
} ST_DESTINO_AUX;

typedef struct {
    char patente[7];
    int destino;
    int chofer;
} ST_VIAJE;

typedef struct {
    char patente[7];
} ST_PATENTE;

FILE *abrir(const char *fileName, const char *mode)
{
    FILE *file = fopen(fileName, mode);
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", fileName);
        EXIT_FAILURE;
    }
    return file;
}

void leer(ST_DESTINO *destino, FILE *archivo) {
    fread(destino, sizeof(ST_DESTINO), 1, archivo);
}

void leer(ST_VIAJE *viaje, FILE *archivo) {
    fread(viaje, sizeof(ST_VIAJE), 1, archivo);
}

int buscarChoferMenorRecorrido(float choferes[MAX_CHOFERES]) {

    float kmRecorridos = choferes[0];
    int posChoferMenorRecorrido = 0; 

    for (int i = 1; i < MAX_CHOFERES; i++) {

        if(kmRecorridos > choferes[i]) {
            kmRecorridos = choferes[i];
            posChoferMenorRecorrido = i;
        }
    }

    return posChoferMenorRecorrido + 1;
}

int main () {

    FILE *archivoDestinos = abrir("Destinos.dat", "rb");
    FILE *archivoViajes = abrir("Viajes.dat", "rb");

    ST_DESTINO_AUX vectorDestino[999] = {0};
    ST_DESTINO destino;

    ST_VIAJE viaje;

    float choferes[MAX_CHOFERES];
    ST_PATENTE patentesAlDestino116[200];

    //leer(&destino, archivoDestinos);
    fread(&destino, sizeof(destino), 1, archivoDestinos);
    fwrite(&destino, sizeof(destino), 1, archivoDestinos);
    while(!feof(archivoDestinos)) {

        vectorDestino[destino.destino - 1].destino = destino.destino;
        vectorDestino[destino.destino - 1].distanciaEnKm = destino.distanciaEnKm;
        vectorDestino[destino.destino - 1].cantViajes = 0;
     
        leer(&destino, archivoDestinos);
    }
    fclose(archivoDestinos);

    float distanciaEnKm;
    leer(&viaje, archivoViajes);

    int i = 0;

    while(!feof(archivoViajes)) {

        vectorDestino[viaje.destino - 1].cantViajes++;
        
        distanciaEnKm = vectorDestino[viaje.destino - 1].distanciaEnKm;
        choferes[viaje.chofer - 1] += distanciaEnKm;

        if(viaje.destino == 116) {
            strcpy(patentesAlDestino116[i].patente, viaje.patente);
            i++;
        }

        leer(&viaje, archivoViajes);
    }

    fclose(archivoViajes);

    printf("Cantidad de viajes realizados a cada destino\n");
    
    for(int j = 0; j < 999; j++) {

        if(vectorDestino[j].cantViajes > 0){
            printf("Destino: %d  => %d viajes\n", vectorDestino[j].destino, vectorDestino[j].cantViajes);
        }
    }
    
    printf("Número de chofer con menor cantidad de km recorridos => %d\n", buscarChoferMenorRecorrido(choferes));

    printf("Patente de los camiones que viajaron al destino 116: \n");

    for(int k = 0; k < i; k++) {

        printf("%s\n", patentesAlDestino116[k]);
    }

    return 0;
}