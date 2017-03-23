#include <stdio.h>
#include <stdlib.h>

int pedirNumeroEntero(char mensaje []);
int validarEntero(int numero, int inferior, int superior);

int main()
{
    int numero;
    int sueldo;
    int sexo;
    int edad;
    int respuesta ="s";

    while(respuesta == 's')
    {
        numero= pedirNumeroEntero("Ingrese numero de legajo");


    }

}


int pedirNumeroEntero(char mensaje [])
{
    int numero;
    printf ("%s", mensaje);
    scanf("%d", &numero);
    return numero;
}

int validarEntero(int numero, int inferior, int superior)
{
    while(numero>superior || numero <inferior)
    {
        pedirNumeroEntero
    }
}




