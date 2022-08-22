#include "cuadrado.h"

ST_CUADRADO cargarCuadrado(int lado) {
    ST_CUADRADO cuadrado;
    cuadrado.lado = lado;
    return cuadrado;
}

float area(ST_CUADRADO cuadrado) {
    return cuadrado.lado * cuadrado.lado;
}

float perimetro(ST_CUADRADO cuadrado) {
    return cuadrado.lado * 4;
}

