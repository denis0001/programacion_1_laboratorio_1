# include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int suma (int,int);
int resta (int, int);
int producto(int,int);
int division(int,int);

int main()
{
    int nr1, nr2, rst1, rst2, rst3, rst4;
    //char a;
    //a=getche(); getche muestra el caracter
    printf("Ingrese numero: ");
    scanf("%d",&nr1);

    printf("Ingrese numero: ");
    scanf("%d",&nr2);



    rst1=suma(nr1, nr2);
    rst2=resta(nr1, nr2);
    rst3=producto(nr1, nr2);
    rst4=division(nr1,nr2);

    printf("suma= %d\nresta= %d\nproducto= %d\ncociente= %d",rst1,rst2,rst3,rst4);

    return 0;
}

int suma (int op1,int op2){
    int resultado;
    resultado=op1+op2;
    return resultado;
}


int resta (int op1, int op2){
    int resultado;
    resultado=op1-op2;
    return resultado;

}
int producto(int op1,int op2){
    int resultado;
    resultado=op1*op2;
    return resultado;

}
int division(int op1,int op2){
    int resultado;
    resultado=op1/op2;
    return resultado;

}


