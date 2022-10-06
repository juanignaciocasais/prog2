/* 
    Desarrollar validaTelefono
telefono valido: + <cod_pais> - <cod_area> - <nro_telefono>
    los cod_* y nro_telefono deben ser digitos
    entre cod_area y nro_telefono deben tener maximo 8 digitos
*/

#include <iostream>
#include "string.h"
using namespace std;

bool validaTelefono(const char *telefono) {

    char buffer[15];
    strcpy(buffer, telefono);
    int i = 0;
    int contNum = 0;
    bool primerGuion = false;

    while (buffer[i] != '\0') {
        i++;
    }

    int leng = i;
    i = 0;

    bool esNumeroValido = false;

    if(buffer[i] == '+') {
        i++;

        while(i < leng) {
            while (buffer[i] >= 48 && buffer[i] <= 57 && i < leng) {
                contNum++;
                i++;
            }

            if(buffer[i] != 45 && buffer[i] != '\0') {
                return esNumeroValido;
            }

            if(!primerGuion) {
                primerGuion = true;
                contNum = 0;
            }
            i++;
        }

        if(contNum <= 8) {
            esNumeroValido = true;
        }
    } 
    
    return esNumeroValido;
}

int main () {

    if(validaTelefono("+12-3522-8890")){
        printf("Es un teléfono válido\n");
    } else {
        printf("NO es un teléfono válido\n");
    }

    return 0;
}