#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>



int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
void getString(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[]);
int getStringNumeros(char mensaje[], char input[]);
void getStri(char mensaje[], char input[]);
int getStriNumeros(char mensaje[], char input[]);
int getStriLetras(char mensaje[], char input[]);
int esSoloMoF(char str[]);
int getSexo(char mensaje[], char input[]);
char *strlwr(char *str);
