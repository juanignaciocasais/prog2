#include <iostream>
#include "pentagono.h"

ST_PENTAGONO cargarPentagono(ST_PENTAGONO pentagono) {
    printf("Ingrese un lado del Pentágono:");
    scanf("%d", &pentagono.lado);

    printf("Ingrese el apotema del Pentágono:");
    scanf("%d", &pentagono.apotema);
    
    return pentagono;
}

float area(ST_PENTAGONO pentagono) {
    return (pentagono.lado * 5 * pentagono.apotema)/2;
}

float perimetro(ST_PENTAGONO pentagono) {
    return pentagono.lado * 5;
}

