
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "empleados.h"
#include "validacion.h"

/*
void inicializarEmpleados( eEmpleado x[], int tam)
{
    int i;
    for( i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1;
    int i;
    for( i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1;
    int i;
    for( i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

*/

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    eEmpleado nuevoEmpleado; // trabajar en una estructura auxiliar y luego cargar todos los datos en nuestro array.
    int indice;
    int esta;
    char legajoStr[51];
    int legajo;
    char sexoAux[51];
    char sueldoAux[51];

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        while(!getStriNumeros("Ingrese legajo: ", legajoStr)){
            printf("Deben ser solamente numeros.\n");
        }
        legajo=atoi(legajoStr);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados[esta], sectores, tamSector);
        }
        else
        {
            nuevoEmpleado.legajo = legajo;

            while(!getStriLetras("Ingrese nombre: ", nuevoEmpleado.nombre)){
                printf("Ingrese solo letras.\n");
            }

            while(!getSexo("Ingrese sexo f/m: ", sexoAux)){
                printf("Ingrese f o m para indicar el sexo\n");
            }
            nuevoEmpleado.sexo = sexoAux[0];

            while(!getStriNumeros("Ingrese sueldo: ", sueldoAux)){
                printf("Ingrese importe valido.\n");
            }
            nuevoEmpleado.sueldo = atof(sueldoAux);
            //id.Sector es el campo que sirve como link para relacionar las dos estructuras
            // con la funcion elgir sector genero un submenu que me permite escoger el sector de cada empleado
            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.estaLleno = 1;

            empleados[indice] = nuevoEmpleado;

        }
    }

}



void inicializarEmpleados( eEmpleado empleados[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        if(empleados[i].estaLleno !=1 )
        empleados[i].estaLleno = 0;
    }
}

int buscarLibre( eEmpleado empleados[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {
        if( empleados[i].estaLleno == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado empleados[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if( empleados[i].legajo == legajo && empleados[i].estaLleno == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un sector\n");
    printf("6- Mostrar almuerzos\n");
    printf("7- Mostrar almuerzos por empleado\n");
    printf("9- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int elegirSector(eSector sectores[], int tam)
{
    int idSector;
    int i;
    printf("\nSectores\n\n");
    for( i=0; i < tam; i++)
    {
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}



void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{
    int i;
    for( i=0; i < tamSector; i++)
    {
        if( sectores[i].id == idSector)
        {
            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}


void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[])
{
    int i;
    for( i=0; i < tamComida; i++)
    {
        if( comidas[i].id == idComida)
        {
            strcpy(cadena, comidas[i].descripcion);
            break;
        }
    }
}

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)//revisar
{
    // descripcion guardara la descripcion del sector que le corresponde al legajo
    char descripcion[20];
    // no olvidar pasar el link entre estructuras en este caso el idSector
    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);
    printf("%d\t\%s\t\t%c\t%.2f\t\t%s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, descripcion);
}

void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    printf("Legajo\tNombre\t\t\tSexo\tSueldo\t\tSector\n");
    int i;
    for( i=0; i< tam; i++)
    {
        if( nomina[i].estaLleno == 1)
        {
            // con este tipo de sentencia ahorramos codigo pasando el indice entre los corchetes
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    int legajo;
    int indice;
    char borrar;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice], sectores, tamSector);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            empleados[indice].estaLleno = 0;
            printf("Se ha eliminado el empleado\n\n");
        }
        system("pause");
    }
}

void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    int legajo;
    int indice;
    char modificar;
    float nuevoSueldo;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado(empleados[indice], sectores, tamSector);

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            empleados[indice].sueldo = nuevoSueldo;
            printf("Se ha modificado el sueldo con exito\n\n");
        }
        system("pause");
    }
}


void listarEmpleadosPorSector(eEmpleado empleado[],int tam, eSector sector[],int tamSector)
{
    int i;
    int auxSector;
    // primero pido el sector que quiero listar
    auxSector = elegirSector(sector,tamSector);
    for(i=0; i<tam; i++)
    {
        /* recorro el array buscando empleados que tengan en comun el sector ingresado
         y que ademas esten activos. esta busqueda no ce puede hacer con el array secores pues este
         tiene una longitud menor que el array empleado.*/
        if(empleado[i].idSector == auxSector && empleado[i].estaLleno != 0)
        {
            mostrarEmpleado(empleado[i],sector,tamSector);
        }
    }
    system("pause");
}


void mostrarAlmuerzos(eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int tamAlm){

    char descripcion[20];
    char nombreAlm[20];
    system("cls");
    printf("Lista de almuerzos\n\n");
    printf("Legajo\t Nombre\t\t\tComida\n\n");

    for(int i= 0; i<tamAlm; i++){
        for(int j=0; j<tamEmp;j++){
            if(almuerzos[i].idEmpleado==empleados[j].legajo && empleados[j].estaLleno !=0){
                strcpy(nombreAlm, empleados[j].nombre);
                break;
            }
        }

        for(int k=0; k<tamCom;k++){
            if(almuerzos[i].idComida==comidas[k].id){
                strcpy(descripcion, comidas[k].descripcion);
                break;
            }
        }

        printf("%d\t %s\t\t%s\n", almuerzos[i].idEmpleado, nombreAlm, descripcion);
        }

        system("pause");
}


void mostrarAlmuerzosPorEmpleado(eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int tamAlm, eSector sectores[], int tamSector){

    mostrarEmpleados(empleados, tamEmp, sectores, tamSector);
    int legajoAux;
    int flag = 0;
    system("cls");
    printf("Ingrese legajo del empleado a mostrar: ");
    scanf("%d", &legajoAux);
    for(int i=0; i<tamAlm;i++){
        if(legajoAux==almuerzos[i].idEmpleado){
            for(int j=0; j<tamCom;j++){
                if(almuerzos[i].idComida == comidas[j].id){
                    if (flag==0){
                            printf("Comidas de %d: \n", legajoAux);
                    }
                    printf("%s\n", comidas[j].descripcion);
                    flag++;
                }
            }
        }
     }

    if (flag==0){
        printf("\nNo existe ese legajo en sistema\n\n");
    }
    system("pause");
}

