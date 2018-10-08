#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "empleados.h"
#include "validacion.h"


int main()
{
    char seguir = 's';
    eEmpleado lista[10] ={
    {1, "Luis Perez", 'm', 15.000, 1, 1},
    {2, "Jose Gimenez", 'm', 14.000, 2, 1},
    {3, "Vivina Baus", 'f', 12.000, 3, 1},
    {4, "Rocio Rossi", 'f', 16.000, 4, 1},
    {5, "Juan Lopez", 'm', 18.000, 5, 1}
    };

    eComida comidas[]= {
    {1, "Milanesas", 1},
    {2, "Pizza", 1},
    {3, "Bife", 1},
    {4, "Tarta", 1},
    {5, "Pescado", 1}
    };

    eAlmuerzo almuerzos[]={
    {100, 1, 1},
    {101, 2, 3},
    {102, 3, 2},
    {103, 4, 5},
    {104, 1, 3},
    {105, 2, 2},
    {106, 3, 3},
    {107, 4, 5},
    {108, 5, 4},
    {109, 1, 2},
    {110, 2, 1},
    {111, 3, 5},
    {112, 5, 1},
    {113, 2, 4},
    {114, 3, 3},
    {115, 4, 2},
    {116, 5, 5},
    {117, 1, 4},
    {118, 4, 1}
    };


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
        case 6:
            mostrarAlmuerzos(lista,5, comidas, 5, almuerzos, 19);
            break;
        case 7:
            mostrarAlmuerzosPorEmpleado(lista,5, comidas, 5, almuerzos, 19, sectores, 5);
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');



    return 0;
}


