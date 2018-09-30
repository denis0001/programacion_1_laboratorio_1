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
}eMenu;
//muchos a muchos
typedef struct{
    int idEmpleado;
    int idMenu;
    int estaLleno;
}eEmpleadoMenu;//va en el medio



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



int main()
{
    char seguir = 's';
    eEmpleado lista[10] ={
    {1, "Luis Perez", 'm', 15.000, 1, 1},
    {2, "Jose Gimenez", 'm', 14.000, 2, 1},
    {3, "Vivina Gonzales", 'f', 12.000, 3, 1},
    {4, "Rocio Rossi", 'f', 16.000, 4, 1},
    {5, "Juan Lopez", 'm', 18.000, 5, 1}
    };

    eMenu comidas[5]= {
    {1, "Milanesas", 1},
    {2, "Albondigas", 1},
    {3, "Bife", 1},
    {4, "Tarta", 1},
    {5, "Salmon", 1}
    };

    eEmpleadoMenu empMenu[10];


    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    inicializarEmpleados(lista, 10);


    do
    {
        switch(menu())
        {
        case 1:
            agregarEmpleado(lista, 10, sectores, 5);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, 10, sectores, 5);
            break;
        case 3:
            modificarEmpleado(lista, 10, sectores, 5);
            break;
        case 4:
            mostrarEmpleados(lista, 10, sectores, 5);
            system("pause");
            break;
        case 5:
            listarEmpleadosPorSector(lista,10,sectores,5);
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');



    return 0;
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
    printf("6- Salir\n");
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


void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    // es una buena proctica trabajar en una estructura auxiliar y luego cargar todos los datos en nuestro array.
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            // no confundir empleados[esta] no es un array es un solo empleado que le esta pasando a la funcion
            mostrarEmpleado( empleados[esta], sectores, tamSector);
        }
        else
        {
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);
            //id.Sector es el campo que sirve como link para relacionar las dos estructuras
            // con la funcion elgir sector genero un submenu que me permite escoger el sector de cada empleado
            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.estaLleno = 1;

            empleados[indice] = nuevoEmpleado;
        }
    }
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
/*
for (i=0; i<10;i++){
    for j=0;j<20;j++){//doble del primer
        if (empMenu[j].idEmpleado==emp[i].id && empleado[i].estaLleno != 0){
            for(k=0; k<2;i++){
                if(menu[k].id==empMenu[j].idMenu){
                    mostrar
                }
            }
        }
    }
*/
