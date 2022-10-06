/*
Desarrolle la función validaEmail que reciba una cadena de caracteres y devuelve true o
false si la cadena recibida es o no una dirección de email válida.
Una dirección de email válida posee: <nombre> @ <dominio> . <extensión>
*/

#include <iostream>
#include "string.h"

using namespace std;

bool validaEmail (const char *email) {

    char buffer[60];
    char nombre[40];
    char dominio[40];
    char extension[40];
    strcpy(buffer, email);
    int largoTotal = strlen(buffer) - 2;

    strcpy(nombre, strtok(buffer, "@"));
    
    int nombreLen = strlen(nombre); 
    if(nombreLen < 1 || nombreLen > largoTotal) {
        return false;
    }

    strcpy(dominio, strtok(NULL, "."));
    
    int dominioLen = strlen(dominio);
    if( dominioLen < 1 || nombreLen + dominioLen >= largoTotal) {
        return false;
    }

    strcpy(extension, strtok(NULL, "\0"));

    int extensionLen = strlen(extension);
    if(extensionLen < 1 || (nombreLen + dominioLen + extensionLen) > largoTotal) {
        return false;
    }
    
    return true;
}

int main() {

    if(validaEmail("juan@mail.com")){
        printf("Es un email válido\n");
    } else {
        printf("NO es un email válido\n");
    }   

    return 0;
}