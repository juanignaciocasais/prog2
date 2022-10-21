#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char apellidoYNombre[31];
    char domicilio[21];
    int codigoPostal;
    char telefono[11];
    int anioIngreso;
} ST_ALUMNO;

int main()
{
    ST_ALUMNO r;
    FILE *f1 = fopen("ALUMACTU.dat", "rb+");
    FILE *f2 = fopen("alumactu.TXT", "wt+");
    fread(&r, sizeof(r), 1, f1);
    while (!feof(f1))
    {
        fprintf(f2, "%d %s %s %d %s %d\n", r.legajo, r.apellidoYNombre, r.domicilio, r.codigoPostal, r.telefono, r.anioIngreso);
        fread(&r, sizeof(r), 1, f1);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}