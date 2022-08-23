#include <iostream>
#include "triangulo.h"

ST_TRIANGULO cargarTriangulo(ST_TRIANGULO triangulo) {
    
    printf("Ingrese la base del triángulo:");
    scanf("%d", &triangulo.base);

    printf("Ingrese un lado del triángulo:");
    scanf("%d", &triangulo.lado1);

    printf("Ingrese el último lado del triángulo:");
    scanf("%d", &triangulo.lado2);

    printf("Ingrese la altura del triángulo:");
    scanf("%d", &triangulo.altura);

    return triangulo;
}

float area(ST_TRIANGULO triangulo) {
    return (triangulo.base * triangulo.altura)/2;
}

float perimetro(ST_TRIANGULO triangulo) {
    return triangulo.lado1 +  triangulo.lado2 + triangulo.base;
}
