#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char palabra[10];

    printf("Ingrese palabra: ");
    gets(palabra);
    //strcpy(palabra, "casa");

    printf("La palabra es: %s", palabra);
    return 0;
}
