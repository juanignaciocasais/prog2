#include "circulo.h"

ST_CIRCULO cargarCirculo(int radio) {
    ST_CIRCULO circulo;
    circulo.radio = radio;
    return circulo;
}

float area(ST_CIRCULO circulo) {
    return 3.1415 * circulo.radio * circulo.radio;
}

float perimetro(ST_CIRCULO circulo) {
    return 2 * 3.1415 * circulo.radio;
}
