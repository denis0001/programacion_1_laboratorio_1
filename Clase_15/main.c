#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*int a=7; // asigno un valor a a

    int* punt; // el asterisco va al lado del tipo de dato
    int* otro; // crear un puntero abajo de otro para evitar errorers

    punt=&a; //apunta el puntero a la variable a

    otro = punt; // asigna al puntero la misma variable cargada
    */

    //printf("%d \n%d",*otro, punt);

    //printf("%d \n", punt); // muestra la posicion en memoria

    //printf("%d\n", punt+1); //muestra siguiente posicion en memoria

    //printf("%d\n", punt-1); //muestra la anterior posicion en memoria

    //printf("%d", *punt+1); //cambia el valor

    //punt=punt+1; //apunta a la siguiente direccion de memoria donde apuntaba == punt++

    //punt=punt-1; // apunta al anterior direccion de memoria donde apuntaba == punt--




    /*if (punt<otro);
    {
        printf("NO");
    }
    else
    {
        printf("si");
    }
    */

    //if (punt==&a);

    //if (punt==0x4FE);

    int x[5];

    int* p;
    int i;
    /*
    x[0]=9;
    x[1]=1;
    x[2]=5;
    x[3]=6;
    x[4]=8;
    */

    //p=&x; //no usar

     p=x;//esta si porque no es redundandte


    for
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

    return 0;
}
