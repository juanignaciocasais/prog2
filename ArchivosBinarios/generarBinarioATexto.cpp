#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    int codMateria;
    int dia;
    int mes;
    int anio;
    char nombreApellido[26];
} ST_ALUMNO;

int main()
{
    ST_ALUMNO r;
    FILE *f1 = fopen("DIAFINALES.DAT", "rb+");
    FILE *f2 = fopen("DIAFINALES.TXT", "wt+");
    fread(&r, sizeof(r), 1, f1);
    while (!feof(f1))
    {
        fprintf(f2, "%d %d %d/%d/%d %s", r.legajo, r.codMateria, r.dia, r.mes, r.anio, r.nombreApellido);
        fread(&r, sizeof(r), 1, f1);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}