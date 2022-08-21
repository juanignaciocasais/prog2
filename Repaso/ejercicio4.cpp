#include <stdio.h>
#include <stdlib.h>
#include "string.h"
using namespace std;

/*
El empleado administrativo de una empresa atiende durante su jornada laboral a una
indeterminada cantidad de personas; todas ellas deben indicar su nombre y número de
legajo para ser atendidos.
Todos los días al terminar el turno, se informa:
* quién fue la primera persona en ser atendida, 
* quien poseía el legajo más bajo, 
* la cantidad total de personas 
* y cuántas personas fueron atendidas por tipo de trámite;
los empleados suelen acercarse a la administración por temas relacionados al 
salario(s), vacaciones(v) y cobertura médica(cm).
*/

typedef struct{
    char nombre[10];
    int legajo;
    char tipoTramite;
} ST_Cliente;

typedef struct{
    char primerEmpleado[10] = "";
    char empleadoLegajoMenor[10] = "";
    int legajoMenor;
    int cantPersonasAtendidas = 0;
    int cantPersonasSalario = 0; 
    int cantPersonasVacaciones = 0;
    int cantPersonasCobMedica = 0;
} ST_Informe;

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

void imprimir(ST_Informe informe) {

    printf("*************** INFORME ******************\n");
    
    printf("Primer persona atendida: %s \n", informe.primerEmpleado);

    printf("Persona con legajo mas bajo: %s Legajo nº : %d \n", informe.empleadoLegajoMenor, informe.legajoMenor);

    printf("Cantidad total de personas: %d \n", informe.cantPersonasAtendidas);

    printf("Cantidad de personas atendidas por tipo de trámite: \n");

    printf("Salario: %d \n", informe.cantPersonasSalario);

    printf("Vacaciones: %d \n", informe.cantPersonasVacaciones);

    printf("Cobertura médica: %d \n", informe.cantPersonasCobMedica);
}

ST_Informe cargarDatos(){
    
    ST_Cliente clientes;
    ST_Informe informe;

    int i = 0;

    printf("%s ", "Ingrese número de legajo:");
    scanf(" %d", &clientes.legajo);

    informe.legajoMenor = clientes.legajo;

    while(clientes.legajo != 0){

        printf("%s ", "Ingrese su nombre: ");
        scanf(" %9s", clientes.nombre);

        if(i == 0 ) {
            strcpy(informe.primerEmpleado, clientes.nombre);
        }

        printf("%s ", "Ingrese tipo de tramite s, v ó m:");
        scanf(" %c", &clientes.tipoTramite);

        informe.cantPersonasAtendidas++;

        cantidadTiposTramites(clientes.tipoTramite,informe.cantPersonasSalario,
                                informe.cantPersonasVacaciones,informe.cantPersonasCobMedica);

        if (informe.legajoMenor > clientes.legajo) {
            informe.legajoMenor = clientes.legajo;
            strcpy(informe.empleadoLegajoMenor,clientes.nombre);
        }

        printf("%s ", "Ingrese numero de legajo:");
        scanf(" %d", &clientes.legajo);
    }

    return informe;
}

int main () {

    ST_Informe informe;

    informe = cargarDatos();

    imprimir(informe);
   
   return 0;
}