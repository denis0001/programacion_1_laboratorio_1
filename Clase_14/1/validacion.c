#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "validacion.h"



/** \brief Verifica si el valor recibido es numérico
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]){
    int i=0;
    int contadorPuntos=0;
    while(str[i] !='\0'){
        if((str[i]<'0' || str[i] >'9') && str[i] != '.'){
            return 0;
        }
        if (str[i] == '.'){
            contadorPuntos++;
        }

        i++;
    }
    if (contadorPuntos>1){ //solo un punto puede tener
        return 0;
    }
    if(strlen(str)<1){ // por si se apreta enter por error
        return 0;
    }
    if(strlen(str)== 1 && str[0] == '.'){  // para evitar que solamente quede un punto como dato
        return 0;
    }
    return 1;

}

/** \brief Verifica si el valor recibido contiene solo letras
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y 0 si no lo es
 *
 */

int esSoloLetras(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
    i++;
    }
    if(strlen(str)<1){ //por si se apreta enter por error
        return 0;
    }
    return 1;
}

/** \brief Verifica si el valor recibido contiene solo letras y números
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] >'9'))
            return 0;
    i++;
    }
    return 1;
}

/** \brief Verifica si el valor recibido contiene solo numeros y un guion
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion
 *
 */
int esTelefono(char str[]){
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0'){
        if((str[i] !=' ') && (str[i] !='-') && (str[i]<'0' || str[i] >'9'))
        return 0;
    if (str[i] == '-')
        contadorGuiones++;
    i++;
    }
    if (contadorGuiones==1) //debe tener un guion
        return 1;

    return 0;
}

/** \brief Solicita un texto al usuario y lo devuelve
 *
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 *
 */
void getString(char mensaje[], char input[]){
    printf("%s", mensaje);
    scanf("%s", input);

}

/** \brief Solicita un texto al usuario y lo devuelve
 *
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 *
 */
int getStringLetras(char mensaje[], char input[]){
    char aux[256];
    getString(mensaje, aux);
    if (esSoloLetras(aux)){
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/** \brief Solicita un texto al usuario y lo devuelve
 *
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo numeros
 *
 */
 int getStringNumeros(char mensaje[], char input[]){
    char aux[256];
    getString(mensaje, aux);
    if (esNumerico(aux)){
        strcpy(input, aux);
        return 1;
    }
    return 0;
}


/** \brief Solicita un texto al usuario y lo devuelve
 *
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 *
 */
void getStri(char mensaje[], char input[]){
    printf("%s", mensaje);
    fflush(stdin);
    gets(input);
}

/** \brief Solicita un texto al usuario y lo devuelve
 *
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo numeros o es flotante
 *
 */
 int getStriNumeros(char mensaje[], char input[]){
    char aux[256];
    getStri(mensaje, aux);
    if (esNumerico(aux)){
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/** \brief Solicita un texto al usuario y lo devuelve con mayuscula en la primer letra de cada una de las palabras
 *
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo numeros
 *
 */
 int getStriLetras(char mensaje[], char input[]){
    char aux[256];
    int i;
    getStri(mensaje, aux);
    if (esSoloLetras(aux)){
        strcpy(input, aux);
        strlwr(input);
        for (i=0; input[i]!='\0'; i++){
            input[0]=toupper(input[0]);
            if (input[i]==' '){
                input[i+1]=toupper(input[i+1]);
            }
        }
        return 1;
    }
    return 0;
}

/** \brief Verifica si el valor recibido contiene solo f o m
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y 0 si no lo es
 *
 */

int esSoloMoF(char str[]){

    if((str[0] != 'f') && (str[0]!= 'm') && (str[0] != 'F') && (str[0] != 'M')) {
        return 0;
    }
    if(strlen(str)>1){
        return 0;
    }
    return 1;
}
int getSexo(char mensaje[], char input[]){
    char aux[50];
    getStri(mensaje, aux);
    if(esSoloMoF(aux)){
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/** \brief Pone en minuscula a los caracteres de un array
 *
 * \param str Array con la cadena a ser usada
 * \return str Retorna el array con todos sus caracteres en minuscula
 *
 */


char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}
