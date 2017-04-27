#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define S 2


int main()
{
    int i;
    char seguir='s';
    int opcion=0;
    int contador=0;

    EPersona persona[S];

    for (i=0; i<S; i++)
    {
        persona[i].estado=0;
    }


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                for (i=0; i<S; i++)
                {
                    if (persona[i].estado==0)
                    {
                        printf("\nIngrese nombre: ");
                        fflush(stdin);
                        gets(persona[i].nombre);
                        printf("\nIngrese edad: ");
                        fflush(stdin);
                        scanf("%d",&persona[i].edad);
                        printf("\nIngrese dni: \n");
                        fflush(stdin);
                        scanf("%d",&persona[i].dni);
                        fflush(stdin);
                        persona[i].estado=1;
                        fflush(stdin);
                        break;
                    }
                }

                break;
            case 2:
                printf("El nombre de la persona es: %s \n ", persona[0].nombre);
                printf("El dni de la persona es: %d \n ", persona[0].dni);
                printf("El nombre de la persona es: %s \n ", persona[1].nombre);
                printf("El dni de la persona es: %d \n ", persona[1].dni);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
