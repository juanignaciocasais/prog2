typedef struct {
    int lado1;
    int lado2;
    int base;
    int altura;
}ST_TRIANGULO;

ST_TRIANGULO cargarTriangulo(ST_TRIANGULO);
float area(ST_TRIANGULO);
float perimetro(ST_TRIANGULO);