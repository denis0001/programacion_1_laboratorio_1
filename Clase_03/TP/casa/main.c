#include <stdio.h>
#include <stdlib.h>
#include <strings.h>



int main()
{
    int opcion;
    float x,y, resultadoSuma, resultadoResta, resultadoDivision, resultadoMultiplicacion;

    do{
        system("CLS");
        printf("MENU");
        printf("\n\n1.Ingresar 1er operando (A= %.3f)",x);
        printf("\n2.Ingresar 2do operando (B= %.3f)",y);
        printf("\n3.Calcular todas las operaciones");
        printf("\n4.Informar resultados");
        printf("\n5.Salir");

        printf("\n\nSeleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                system("CLS");
                printf("Ingrese 1er operando: ");
                scanf("%f",&x);
                system("CLS");
                break;

            case 2:
                system("CLS");
                printf("Ingrese 2do operando: ");
                scanf("%f",&y);
                system("CLS");
                break;

            case 3:
                resultadoSuma=x+y;
                resultadoResta=x-y;
                resultadoDivision=x/y;
                resultadoMultiplicacion=x*y;
                system("CLS");
                break;

            case 4:
                system("CLS");
                printf("\nEl resultado de %.3f + %.3f es %.3f", x, y , resultadoSuma);
                printf("\nEl resultado de %.3f - %.3f es %.3f", x, y , resultadoResta);
                printf("\nEl resultado de %.3f / %.3f es %.3f", x, y , resultadoDivision);
                printf("\nEl resultado de %.3f * %.3f es %.5f\n", x, y , resultadoMultiplicacion);
                system("pause");
                break;

            case 5:
                break;


            default:
                system("CLS");
                printf("Opcion incorrecta\n");
                system("pause");
                break;

        }

    }while(opcion!=5);


    return 0;
}
