#include <stdio.h>
#include <stdlib.h>
using namespace std;

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

int main()
{
    // Ejemplo Archivo texto
    FILE *ptrArchivo = NULL;
    ptrArchivo = fopen("texto.txt", "w");

    if (ptrArchivo == NULL)
    {
        printf("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    int edad = 0;
    char nombre[81];
    char nombreLeido[81];

    printf("Ingrese la edad: ");
    scanf("%d", &edad);
    discardChars();                     //Limpia Buffer stdin
    printf("Ingrese el nombre: ");
    fgets(nombre, 81, stdin);// Captura texto con espacios en blanco desde la consola

    fprintf(ptrArchivo, "%s %d", nombre, edad); //Imprime texto en el archivo

    fclose(ptrArchivo);

    ptrArchivo = fopen("texto.txt", "r");

    if (ptrArchivo == NULL)
    {
        printf("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    fgets(nombreLeido, 81, ptrArchivo);

    printf("El nombre que leí del archivo de texto es: %s\n", nombreLeido);

    fclose(ptrArchivo); //Guarda los datos y cierra el archivo

    return 0;
}
