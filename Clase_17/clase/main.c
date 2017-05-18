#include <stdio.h>
#include <stdlib.h>
#define T 3

int main()
{
    int* p;
    int i;
    int* auxP;

    p=(int*)malloc(sizeof(int)); //castear tipo de dato del puntero.
                                 //malloc devuelve cualquier tipo de dato


    p=(int*)malloc(sizeof (int)*3);

    for (i=0;i<T;i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", p+i);
    }
    for (i=0; i<T; i++)
    {
        printf("%d\n", *(p+i));
    }

    auxP=realloc(p, sizeof(int)*(T+2)); // primerp se le manda lo que quiero relocalizar
                                        //seguido del nuevo tamaño

    if (auxP!=NULL)
    {
        p=auxP;

        for(i=T; i<T+2;i++)
        {
            printf("Ingrese mas numeros: ");
            scanf("%d", p+i);
        }
        for (i=0; i<T+2; i++)
        {
            printf("%d\n", *(p+i));
        }
    }
    if (auxP==NULL)
    {
        printf("no hay lugar");
    }
    return 0;
}
