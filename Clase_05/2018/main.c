#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void mostrarArray (char letras[], int tam);
void ordenarArray(char letras[], int tam, int criterio);
int main()
{
    char letras[]= {'t','v','b','T','A','v'};

    mostrarArray(letras,6);

    ordenarArray(letras,6,1);

    mostrarArray(letras,6);

    return 0;
}

void mostrarArray (char letras[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%c", letras[i]);
    }
    printf("\n\n");
}

void ordenarArray(char vec[], int tam, int criterio)
{
    char aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(criterio)
            {
                if(vec[i]>vec[j])
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
            else
            {
                if(vec[i]<vec[j])
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

