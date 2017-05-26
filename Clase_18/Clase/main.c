#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*FILE* miArchivo;
    char palabra[50];

    printf ("Ingrese una palabra: ");
    fgets(palabra,50,stdin);

    puts(palabra);
    */

    FILE* miArchivo;
    char palabra[50];

    gets(palabra);

    miArchivo=fopen("prueba.txt","w"); // primero va el nombre del archivo y despues la forma en que se va a guardar

    fprintf(miArchivo,"%c", palabra);

    fclose(miArchivo);

    //miArchivo=fopen("prueba.txt", "r");

    /*while (!feof(miArchivo))
    {
        gets(palabra);
    }
*/
    return 0;
}
