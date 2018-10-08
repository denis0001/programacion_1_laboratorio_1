#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int estaLleno;
} eEmpleado;

typedef struct{
    int id;
    char descripcion[20];
}eSector;

typedef struct{
    int id;
    char descripcion [31];
    int estaLleno;
}eComida;
//muchos a muchos
typedef struct{
    int id;
    int idEmpleado;
    int idComida;
}eAlmuerzo;//va en el medio, estructura de relacion


int menu();
void inicializarEmpleados( eEmpleado empleado[], int tam);
int buscarLibre( eEmpleado empleado[], int tam);
int buscarEmpleado(eEmpleado empleado[], int tam, int legajo);
int elegirSector(eSector sectores[], int tam);
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void listarEmpleadosPorSector(eEmpleado empleado[],int tam, eSector sector[],int tamSector);
void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[]);
void mostrarAlmuerzos(eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int tamAlm);
void mostrarAlmuerzosPorEmpleado(eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int tamAlm, eSector sectores[], int tamSector);
