#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
El empleado administrativo de una empresa atiende durante su jornada laboral a una
indeterminada cantidad de personas; todas ellas deben indicar su nombre y número de
legajo para ser atendidos.
Todos los días al terminar el turno, se informa:
* quién fue la primera persona en ser
atendida, 
* quien poseía el legajo más bajo, 
* la cantidad total de personas 
* y cuántas personas fueron atendidas por tipo de trámite;
los empleados suelen acercarse a la administración por 
temas relacionados al salario(s), vacaciones(v) y cobertura médica(cm).
*/

struct ST_Cliente{
    char nombre[10];
    int legajo;
    char tipoTramite;
};

void cantidadTiposTramites(char tipoTramite, int& cantSalario, int& cantVacaciones, int& cantCoberMedica){

    switch(tipoTramite){
        case 's':
        cantSalario++;
        break;

        case 'v':
        cantVacaciones++;
        break;

        case 'm':
        cantCoberMedica++;
        break;

    }

    return;
}

int buscarLegajoMenor(int legajoMenor, int legajo){

    if(legajo < legajoMenor){
        return legajo;
    }

    return legajoMenor;
}

void cargarDatos(ST_Cliente clientes[],int cant){

    int legajoMenor;
    int cantPersonasAtendidad=0, cantPersonasSalario=0, cantPersonasVacaciones=0, cantPersonasCobMedica=0;
    int i=0;



    printf("%s ", "ingrese numero de legajo:");
    scanf(" %d", &clientes[i].legajo);

    legajoMenor=clientes[i].legajo;

    while(i < cant && clientes[i].legajo != 0){

        printf("%s ", "Ingrese su nombre: ");
        scanf(" %9s", clientes[i].nombre);

        printf("%s ", "Ingrese tipo de tramite s, v ó m:");
        scanf(" %c", &clientes[i].tipoTramite);

        cantPersonasAtendidad++;

        cantidadTiposTramites(clientes[i].tipoTramite,cantPersonasSalario,cantPersonasVacaciones,cantPersonasCobMedica);

        legajoMenor = buscarLegajoMenor(legajoMenor, clientes[i].legajo);

        i++;

        printf("%s ", "ingrese numero de legajo:");
        scanf(" %d", &clientes[i].legajo);

    }

    printf("Primer persona atendida: %s \n", clientes[0].nombre);

    printf("Persona con legajo mas bajo: %d \n", legajoMenor);

    printf("Cantidad total de personas: %d \n", cantPersonasAtendidad);

    printf("Cantidad de personas atendidas por tipo de tramite: \n");

    printf("Salario: %d \n", cantPersonasSalario);

    printf("Vacaciones: %d \n", cantPersonasVacaciones);

    printf("Cobertura medica: %d \n", cantPersonasCobMedica);

    return;
    
}

int main () {

    ST_Cliente clientes[10];

    cargarDatos(clientes, 10);

   return 0;
}