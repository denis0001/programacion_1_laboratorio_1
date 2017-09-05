#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char nombre[15];
    char apellido[20];

    char ayn[37];

    printf("Ingrese nombre:");
    gets(nombre);

    printf("Ingrese apellido:");
    gets(apellido);
    //strcat(nombre, apellido);
    printf("%s, %s", nombre, apellido);


    return 0;
}
