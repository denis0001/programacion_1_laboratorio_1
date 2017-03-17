#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int main()
{
    int numero;
    int cantPares=0;
    int cantImpares=0;
    int sumImpares=0;
    int contTodo;
    int sumTodo=0;
    float promedio;
    int numMayor;
    int numMenorImpar=0;
    int cont315=0;
    int cont1629=0;
    int cont30plus=0;
    char respuesta='s';
    int i;
    //int flag=0;

    while(respuesta=='s')
    {
        printf("Ingrese numero positivo:");
        scanf("d", &numero);

        while(numero<1)
        {
            printf("Ingrese numero positivo:");
            scanf("d", &numero);
        }

        if(numero%2==0)
        {
            cantPares++;

        }
        if(numero%2==1)
        {
            cantImpares++;
            sumImpares=+numero;
        }

        if (contTodo==0)
        {
            numMayor=numero;
        }
        else
        {
            if(numMayor<numero)
            {
                numMayor=numero;
            }
        }

        /*if (flag==0)
        {
            max=numero;
            flag=1;
        }
        else
        {
            if (num>max)
            {
                max=num;
            }
        */

        //if(flag==0 || numero>max)

        }



        if(numero>2 && numero<16)
        {
            cont315++;
        }
        if(numero>15 && numero<30)
        {
            cont1629++;
        }
        if (numero>29)
        {
            cont30plus++;
        }

        contTodo++;
        sumTodo+=numero;

        printf("¿Desea seguir ingresando numeros? s/n");
        respuesta=tolower(getche());

    }

    /*for(i=sumImpares;i>0;sumImpares--)
    {
        printf("%d", i)
    }
    */
    promedio=(float)contTodo/sumTodo;

    printf("\nLa cantidad de numeros pares es: %d", cantPares);
    printf("\nLa cantidad de numeros impares es: %d", cantImpares);
    printf("\nLa sumatoria de todos los numeros impares es: %d",sumImpares);
    printf("\nEl promedio de todos los numeros es: %f", promedio);
    printf("\nEl numero mayor ingresado es: %d", numMayor);
    printf("\nEl numero impar menor ingresado es: %d",numMenorImpar);
    printf("\nEntre 3-15 hay: %d entre 16-29: %d y 30 o mas: %d", cont315,cont1629,cont30plus);


    return 0;
}
