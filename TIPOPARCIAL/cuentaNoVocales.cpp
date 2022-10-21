#include <iostream>
using namespace std;

int cuentaNoVocales(char *cadena)
{
    int cantNoVocales = 0;
    int i = 0;

    while (*(cadena + i) != '\0')
    {
        switch (*(cadena + i))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            break;
        default:
            cantNoVocales++;
        }
        i++;
    }

    return cantNoVocales;
}

int main () {

    char *cadena = "aedfrtgu@#iddddop";
    printf("La cantidad de no vocales en esta '%s' son :%d\n", cadena, cuentaNoVocales(cadena));

    return 0;
}