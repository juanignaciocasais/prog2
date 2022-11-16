/*
Dado el archivo de texto palabras.txt, donde cada línea contiene 1 palabra (máximo 80 caracteres),
genere un archivo binario con aquellas palabras que posean más consonantes que vocales.
a. Desarrolle la función int cuentaConsonantes(char *) que devuelve la cantidad de consonantes que
posee una palabra.
b. Desarrolle un programa que permita generar el archivo binario solicitado.
Restricción: para el punto “a” sólo puede utilizar sintaxis de puntero.
*/

#include <iostream>
#include "string.h"
using namespace std;

typedef struct {
    char palabra[81];
}ST_CHAR;

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

ST_CHAR leer(FILE * file) {
    ST_CHAR palabra;
    fgets(palabra.palabra,82,file);
    return palabra;   
}

int cuentaConsonantes(char *);

int main()
{
    FILE *archivoPalabras = abrir("Palabras.txt", "rt");
    FILE *archivoMasConsonantes = abrir("PalabrasConMasConsonantes.txt", "wb");
    ST_CHAR palabra;
    //char palabra[81];

    //strcpy(palabra,leer(archivoPalabras));

    int largoPalabra = 0;

    if(!feof(archivoPalabras)){
        palabra = leer(archivoPalabras);
    }

    while(!feof(archivoPalabras))
    {
        largoPalabra = strlen(palabra.palabra);
        if(largoPalabra < cuentaConsonantes(palabra.palabra))
        {
            fwrite(&palabra, sizeof(palabra), 1, archivoMasConsonantes);
        }

        if(!feof(archivoPalabras)){
            palabra = leer(archivoPalabras);
        }
    }

    fclose(archivoPalabras);
    fclose(archivoPalabras);

    return 0;
}

int cuentaConsonantes(char *palabra)
{
    int cantConsonantes = 0;
    int i = 0;

    while (*(palabra + i) != '\0')
    {
        if (*(palabra + i) == 'a' || *(palabra + i) == 'e' || *(palabra + i) == 'i' ||
            *(palabra + i) == 'o' || *(palabra + i) == 'u')
        {
            i++;
        } else
        {
            cantConsonantes++;
            i++;
        }
    }
    return cantConsonantes;
}
