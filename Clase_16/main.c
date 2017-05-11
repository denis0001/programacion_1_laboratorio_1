#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct
{
    int legajo;
    char nombre[50];
}eAlumno;


int main()
{
/*
    // ejercicio con una sola persona

    eAlumno miAlumno, *pAlumno;

    pAlumno=&miAlumno; //asigno la la direccion de la estructura al puntero

    printf("Ingrese legajo: ");
    scanf("%d", &pAlumno->legajo); // aca se pone el unperson porque la variable no es un puntero;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets (pAlumno ->nombre);


    //pAlumno->legajo=100; //valores hardcodeados

    //strcpy (pAlumno->nombre, "Juan"); //valores hardcodeados

    printf("%d -- %s", pAlumno->legajo, pAlumno->nombre);
*/

    //con varias personas
    int i;
    eAlumno miAlumno, *pAlumno;

    pAlumno=&miAlumno; //asigno la la direccion de la estructura al puntero

    for (i=0;i<3;i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &(pAlumno+i)->legajo); // aca se pone el unperson porque la variable no es un puntero;
        printf("%d\n",(pAlumno+i)->legajo);
        //printf("Ingrese nombre: ");
        //fflush(stdin);
        //gets (((pAlumno)+i)->nombre);
    }

    for (i=0;i<3;i++)
    {
         printf("%d", (pAlumno+i)->legajo);//, pAlumno+i->nombre);
    }
    return 0;
}
