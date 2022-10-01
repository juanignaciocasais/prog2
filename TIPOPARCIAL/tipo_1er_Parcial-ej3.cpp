/*
Se dispone del archivo de texto binarios.txt el cual posee en cada línea números codificados
en sistema binario (sólo ceros y unos). Cada número tendrá una longitud máxima de 31
caracteres y están todos los caracteres.
Se solicita generar el archivo binario decimales.dat el cual contendrá el número decimal
equivalente.
Ejemplo:
10101 -> genera 21
10001 -> genera 17
*/

#include <iostream>
#include "string.h"
#include <math.h>
using namespace std;

FILE *abrir(const char * filename, const char * mode){
    
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Error al abrir el archivo %s\n", filename);
        EXIT_FAILURE;
    }
    return file;
    
}

char obtenerDecimal(const char *binario){
    int decimal;
    for(int i = 0; i < 32; i++){
        decimal += binario[i] * pow(2, 5 - i);
    }

    return decimal;
}

int main () {

    FILE *archivoBinario = abrir("Binarios.txt", "rt");
    FILE *archivoDecimal = abrir("Decimales.dat", "wb");

    char binario[32];
    while(fgets(binario, 32, archivoBinario)){
        int decimal = obtenerDecimal(binario);
        printf("%s => %d\n", binario, decimal);
        fwrite(&decimal,sizeof(decimal), 1, archivoDecimal);
    }

    fclose(archivoBinario);
    fclose(archivoDecimal);

    return 0;
}