#include <iostream>
using namespace std;

int busquedaBinaria(FILE * file, int id)
{
    //Cuando arranco evalúo todo el vector de 0 a cantElementos-1
    ST_DATO dato;
    int inicio = fseek(file, 0, SEEK_SET);
    int fin = fseek(file,0,SEEK_END);

    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        fseek(file, mitad, SEEK_SET);
        fread(&dato, sizeof(dato), 1, file);
        //Si el elemento es el del medio, devolvemos la posición
        if (dato.id == id)
        {
            return mitad;
        }

        //Si el elemento es menor, entonces sólo puede estar en la 1ra mitad del array
        if (dato.id > id)
        {
            fin = mitad - 1; //Cambio el límite superior
        }
        else
        {
            inicio = mitad + 1; //Cambio el límite inferior
        }
    }
    return -1; //Si no se encuentra
}
