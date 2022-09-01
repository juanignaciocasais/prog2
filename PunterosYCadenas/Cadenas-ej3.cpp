/*
Dada una cadena, cuya longitud máxima es de 15 caracteres, y utilizando sólo sintaxis de
punteros, determinar si la cadena forma una dirección de ip válida.
Ejemplo:
192.168.1.23 → verdadero
192.168.1.z → falso
10.250.244.255 → verdadero
*/

#include <stdio.h>
#include <stdlib.h>
using namespace std;

int largoCadena(char *cadena){
    int i = 0;
    while(*(cadena + i) != '\0'){
        i++;
    }
    return i;
}

bool esIPValido(char *cadena) {

    int cantCaracteres = largoCadena(cadena);
    int i = 1;
    int cantPuntos = 0;
    int cantNumeros = 0;
    int cantPuntosTotal = 0;
    int cantNumerosTotal = 0;

    while (i < cantCaracteres) {
        if( (*(cadena + cantCaracteres - i) >= '0' && 
            *(cadena + cantCaracteres - i) <= '9') && cantNumeros < 3) {
                i++;
                cantNumeros++;
                cantNumerosTotal++;
                cantPuntos = 0;
        }else if(*(cadena + cantCaracteres - i) == '.' && cantPuntos < 2){
            i++;
            cantPuntos++;
            cantPuntosTotal++;
            cantNumeros = 0;
        } else return false;
    }

    if(cantPuntosTotal == 3) {
        return true;
    }
    return false;
}

int main()
{
    char numeroIp[16];

    printf("Ingrese un Nº de IP: ");
    scanf("%s", &numeroIp);

    if(esIPValido(numeroIp)) {
        printf("El Nro %s es un IP válido.\n",numeroIp);
    } else printf("El Nro %s NO es un IP válido.\n",numeroIp);

    return 0;
}