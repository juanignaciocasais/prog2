#include <iostream>
#include "cuadrado.h"
#include "circulo.h"
#include "triangulo.h"
#include "pentagono.h"

using namespace std;

int main()
{

    char tipoFigura;
    printf("Ingrese el tipo de figura (1 = Cuadrado, 2 = Círculo, 3 = Triángulo, 4 = Pentágono,):\n");
    scanf("%c", &tipoFigura);

    switch (tipoFigura)
    {
    case '1':
    {
        int lado = 0;
        printf("Ingrese un lado del cuadrado:");
        scanf("%d", &lado);
        ST_CUADRADO cuadrado = cargarCuadrado(lado);
        printf("El area es: %4.2f y el perimetro es %4.2f\n\n", area(cuadrado), perimetro(cuadrado));
        break;
    }
    case '2':
    {
        int radio = 0;
        printf("Ingrese el radio del círculo:");
        scanf("%d", &radio);
        ST_CIRCULO circulo = cargarCirculo(radio);
        printf("El área es: %4.2f y el perímetro es %4.2f\n\n", area(circulo), perimetro(circulo));
        break;
    }
    case '3':
    {
        ST_TRIANGULO triangulo;
        triangulo = cargarTriangulo(triangulo);
        printf("El área es: %4.2f y el perímetro es %4.2f\n\n", area(triangulo), perimetro(triangulo));
        break;
    }
    case '4':
    {
        ST_PENTAGONO pentagono;
        pentagono = cargarPentagono(pentagono);
        printf("El área es: %4.2f y el perímetro es %4.2f\n\n", area(pentagono), perimetro(pentagono));
        break;
    }
    default:
        break;
    }

    return 0;
}