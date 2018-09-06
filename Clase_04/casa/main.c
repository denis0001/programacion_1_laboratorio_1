#include <stdio.h>
#include <stdlib.h>


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(char message[],char eMessage[], int lowLimit, int hiLimit);


int main()
{
    int edad;
     // Respuesta
    edad = getInt("¿Cual es tu edad?","Rango valido [0 - 100]",1,100);

    printf("La edad es: %d",edad);


    return 0;
}

int getInt(char message[],char eMessage[], int lowLimit, int hiLimit)
{
int edad;
printf("%s",message);
scanf("%d",&edad);

while (edad<lowLimit || edad>hiLimit){
    printf("%s",eMessage);
    scanf("%d", &edad);

}
    return edad;
}


