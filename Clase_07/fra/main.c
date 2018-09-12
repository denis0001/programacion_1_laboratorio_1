#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define CANT 3
int main()
{
    int legajo[CANT], edadAux;
    int edad[CANT], legajoAux;
    int i,j,opcion=0, flag=0;
    char rta;
    char nombre[CANT][31],nomAux[31];
    char apellido[CANT][31], apeAux[31];
    int isEmpty[CANT], isEmptyAux;

    for(i=0;i<CANT;i++){

        isEmpty[i]=1;
    }

    do{
        printf("*********MENU*********");
        printf("\n1-Altas");
        printf("\n2-Bajas");
        printf("\n3-Modificacines");
        printf("\n4-Listado por apellido");
        scanf("%d",opcion);
        switch(opcion){

            case 1:
            for (i=0; i<CANT;i++){
                if (isEmpty[i]==1){
                    printf("Legajo: ");
                    //legajo[i]=i+1;
                    scanf("%d",&legajo[i]);
                    printf("Edad: ");
                    scanf("%d",&edad[i]);
                    printf("Nombre: ");
                    fgets(nombre[i],31,stdin);
                    printf("Apellido: ");
                    fgets(apellido[i],31,stdin);
                    isEmpty[i]=0;
                    break;
                }
            }

                break;
            case 2:

            //int buscaInt(int legajo[],legajoAux);
                printf("Ingrese legajo:");
                scanf("%d",&legajoAux);
                flag=0;
                for(i=0;0<CANT;i++){
                    if(legajoAux==legajo[i]&& isEmpty[i]==0){
                        isEmpty[i]=1;
                        flag=1;
                    }
                }
                if(flag==0){
                    printf("Dato no encontrado");
                }
            case 3:
                printf("legajo");
                scanf("%d",&legajoAux);
                flag=0;
                for(i=0;i<CANT;i++){
                    if(legajoAux==legajo[i]){
                        printf("%d%s%s%d",legajo[i],apellido[i],nombre[i],edad[i];
                        printf("Modificar s/n?");
                        fflush(stdin);
                        scanf("%c",&rta);
                        //toupper
                        if(rta=='s'){
                            do{
                            printf("menu");
                            printf("Apellido");
                            scanf("%d",opcionM);
                            switch(opcionM){
                            case 1:
                                printf("Apellido: ");
                                fflush(stdin)
                                fgets(apellido[i],31,stdin);
                                break;

                            }
                            }while(opcionM!=4);
                            else{
                                printf("Datos no modificados");

                            }
                        }


                    }
                }
            case 4:
                    for (i=0;i<CANT-1;i++){ //ordenamiento con dos criterios //cuando el criterio a ordenar puede ser repetido
                        for(j=i+1;j<CANT;j++){
                            if(strcmp(apellido[i],apellido[j])>0){
                                strcpy(nomAux,nombre[i]);
                                strcpy(nombre[i],nombre[j]);
                                strcpy(nombre[j],nomAux);
                                strcpy(apeAux,apellido[i]);
                                strcpy(apellido[i],apellido[j]);
                                strcpy(apellido[j],apeAux);
                                edadAux=edad[i];
                                edad[i]=edad[j];
                                edad[j]=edadAux;
                                legajoAux=legajo[i];
                                legajo[i]=legajo[j];
                                legajo[j]=legajoAux;
                                isEmptyAux=isEmpty[i];
                                isEmpty[i]=isEmpty[j];
                                isEmpty[j]=isEmptyAux;

                            }
                            else{
                                if (strcmp(apellido[i],apellido[j])==0){
                                    if(strcmp(nombre[i], nombre[j])>0){
                                        strcpy(nomAux,nombre[i]);
                                        strcpy(nombre[i],nombre[j]);
                                        strcpy(nombre[j],nomAux);
                                        edadAux=edad[i];
                                        edad[i]=edad[j];
                                        edad[j]=edadAux;
                                        legajoAux=legajo[i];
                                        legajo[i]=legajo[j];
                                        legajo[j]=legajoAux;
                                        isEmptyAux=isEmpty[i];
                                        isEmpty[i]=isEmpty[j];
                                        isEmpty[j]=isEmptyAux;
                                    }
                                }
                            }
                        }
                    }
                    printf("legajo\tapellido\t\t\nombre\tedad\n\n");
                for(i=0; i<CANT; i++){
                    if (isEmpty[i]==0){
                    printf("%d\t%s\t\t%s\t%d\n",legajo[i],apellido[i],nombre[i],edad[i]);
                    }
                }
                break;
                default:
                printf("Opcion incorrecta.");
                system("pause");
                break;
        }


    }while(opcion!=5);
        //cantidad=strlen(nombre[i]);
          //nombre[cantidad-1]='\0';



    //printf("%d", sizeof(cadena));
    //pasar todo a mayusm


    //fgets(cadena,sizeof(cadena),stdin);

    return 0;
}
