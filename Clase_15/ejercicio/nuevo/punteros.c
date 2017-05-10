#include "punteros.h"
#include <stdio.h>
#include <string.h>
void cargaPorPuntero (int x[], int tam)
{
    int i;

    for (i=0;i<tam;i++)
    {
        printf("ingrese valor\n");
        scanf("%d ", *(x+i));
    }
}

void mostrarPorPuntero (int x[], int tam)
{
    int i;

    for (i=0;i<tam;i++)
    {
        printf("Los valores de los punteros son %d \n", *(x+i));
    }
}

/*void ordenarPorPuntero (int x[],int tam)
{
    int i,j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1 ;j<tam; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                burbuja=lista[i];
                lista[i]=lista[j];
                lista[j]=burbuja;
            }
        }
    }
}

*/
