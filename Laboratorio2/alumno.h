typedef struct 
{
    int dia;
    int mes;
    int anio;
}ST_FECHA;

typedef struct{
    char nombre[10];
    float promedio;
    ST_FECHA fechaInicio;
} ST_ALUMNO;

void ingresarAlumnos(ST_ALUMNO vector[], int cantAlumnos);

ST_ALUMNO mejorPromedio(ST_ALUMNO vector[], int cantAlumnos);
