#include <stdio.h>
#include <stdlib.h>
#include "franco.h"
//int validarEdadLaboral (int);

int main()
{
    int edad;
    printf("Ingrese edad: ");
    scanf("%d",&edad);
    while (!validarRango(edad, 65,18)){
        printf("Edad invalida. Reingrese.\n\n");
        scanf("%d",&edad);
    }
    printf("Edad valida");

    return 0;
}

/*int validarEdadLaboral (int valor){

    if (valor<18){
        return 0;

    }
    if (valor>65){
        return 0;

    }
    else{
        return 1;

    }

}*/


