#include <stdio.h>
#include <stdlib.h>
#include "punteros.h"

int main()
{
    int x[5];

    int* p;
    int i, tam=5;

    //p=&x; //no usar

    /*p=x;//esta si porque no es redundandte



    for (i=0;i<5;i++)
    {
        *(p+1)=0; // inicializar p a 0;
    }

    for (i=0;i<5;i++)
    {
        printf("%d\n", *(p+1));
    }

    //*(p+1)=3; //cambia el valor al segundo elemento del vector

    //*p=1;  //cambia el valor al primer elemento del vector

    //una funcion que cargue el vector a traves del puntero, ordenar y mostrar
    */


    cargaPorPuntero(x, tam);

    mostrarPorPuntero(x, tam);




    return 0;
}
