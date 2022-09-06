#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct {
    int edad;
    char nombre[81];
}ST_PERSONA;

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

int main()
{
    // Ejemplo Archivo Binario
    ST_PERSONA persona;
    ST_PERSONA personaLeida;

    char fileName[] = "myfile.dat";
    FILE *pFile;
    pFile = fopen(fileName, "wb");
    if (pFile == NULL)
    {
        printf("Error al abrir el archivo %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    printf("Ingrese la edad: ");
    scanf("%d", &persona.edad);
    discardChars();                     //Limpia Buffer stdin
    printf("Ingrese el nombre: ");
    fgets(persona.nombre, 81, stdin);// Captura texto con espacios en blanco desde la consola

    fwrite(&persona, sizeof(persona),1,pFile);

    fclose(pFile);

    pFile = fopen(fileName, "rb");
    if (pFile == NULL)
    {
        printf("Error al abrir el archivo %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    fread(&personaLeida, sizeof(persona),1,pFile);

    printf("\nEl nombre que leí del archivo binario es: %s\n", personaLeida.nombre);
    printf("La edad es: %d\n", personaLeida.edad );

    fclose(pFile);

    return 0;
}
