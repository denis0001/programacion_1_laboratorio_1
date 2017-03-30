#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int suma(int, int);
int resta(int,int);
float division(int,int);
int multiplicacion(int, int);
int factorial(int);

int main()
{
    char seguir='s';
    int opcion=0;

    int primerNum;
    int segundoNum;
    int resultado;
    float resultadoDiv;
    int flagPrimerOperando=0;
    int flagSegundoOperando=0;


    while(seguir=='s')
    {

        if (flagPrimerOperando==1)
        {
            printf("1- Ingresar 1er operando (A=%d)\n",primerNum);
        }
        else
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        if (flagSegundoOperando==1)
        {
            printf("2- Ingresar 2do operando (B=%d)\n",segundoNum);
        }
        else
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        ;
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el 1er operando ");
                scanf("%d", &primerNum);
                flagPrimerOperando=1;
                break;
            case 2:
                printf("Ingrese el 2do operando ");
                scanf("%d", &segundoNum);
                flagSegundoOperando=1;
                break;
            case 3:
                if(flagPrimerOperando==0 || flagSegundoOperando==0)
                {
                    printf("Falta ambos o uno de los operandos");
                    break;
                }

                else
                {
                    resultado= suma(primerNum, segundoNum);
                    printf("La suma es: %d\n", resultado);
                    break;
                }


                //faltaria poner que pasa cuando falta alguno de los dos numeros

            case 4:
                if(flagPrimerOperando==0 || flagSegundoOperando==0)
                {
                    printf("Falta ambos o uno de los operandos");
                    break;
                }
                else
                {
                    resultado= resta(primerNum, segundoNum);
                    printf("La resta es: %d\n", resultado);
                    break;
                }

            case 5:
                if(flagPrimerOperando==0 || flagSegundoOperando==0)
                {
                    printf("Falta ambos o uno de los operandos");
                    break;
                }

                else
                {
                    if(segundoNum==0)
                    {
                        printf("No se puede dividir por 0, reingrese el 2do operando");
                        break;
                    }
                    else
                    {
                        resultadoDiv= division(primerNum, segundoNum);
                        printf("El cociente es: %f\n", resultadoDiv);
                        break;
                    }
                }


            case 6:
                resultado= multiplicacion(primerNum, segundoNum);
                printf("El producto es: %d\n", resultado);
                break;
            case 7:
                if (flagPrimerOperando==0)
                {
                    printf("Falta ingresar el 1er operando");
                    break;
                }
                else
                {
                    resultado=factorial(primerNum);
                    printf("El factorial es: %d\n",resultado);
                    break;
                }


                /*if(flagSegundoOperando==0)
                {
                    resultado=factorial(primerNum);
                    printf("El factorial es: %d\n",resultado);
                    break;
                }
                else
                {
                    if(flagPrimerOperando==0)
                    {
                        resultado=factorial(segundoNum);
                        printf("El factorial es: %d\n",resultado);
                        break;
                    }
                }
                */

            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}

int suma(int num1, int num2)
{
    int sumar;
    sumar= num1 + num2;
    return sumar;
}
int resta(int num1,int num2)
{
    int restar;
    restar= num1 - num2;
    return restar;
}
float division(int num1,int num2)
{
    float dividir;
    dividir= num1/num2;
    return dividir;
}
int multiplicacion(int num1, int num2)
{
    int multiplicar;
    multiplicar=num1*num2;
    return multiplicar;
}

int factorial(int numero)
{
    int i;
    int resultado = 1;

    for(i=numero; i>0; i--)
    {
        resultado=resultado*i;
    }
    return resultado;
}






