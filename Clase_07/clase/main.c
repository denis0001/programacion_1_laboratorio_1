#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4
typedef struct
{
    int legajo;
    char nombre[50];
    float peso;
    char sintoma[30];
} ePaciente;

void mostrarPaciente(ePaciente);
void mostrarTodosLosPacientes(ePaciente[], int);
void cargarTodosLosPacientes(ePaciente[], int);
void inicializar(ePaciente[], int);
int main()
{

    ePaciente listaPacientes[TAM];

    inicializar(listaPacientes,TAM);
    //cargarTodosLosPacientes(listaPacientes,TAM);
    //mostrarTodosLosPacientes(listaPacientes, TAM);


    return 0;
}

void mostrarPaciente(ePaciente paciente)
{
    printf("%d-%s-%f-%s\n", paciente.legajo, paciente.nombre, paciente.peso,paciente.sintoma);
}

void mostrarTodosLosPacientes(ePaciente lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        mostrarPaciente(lista[i]);
    }
}

void cargarTodosLosPacientes(ePaciente lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese peso: ");
        scanf("%f", &lista[i].peso);
        printf("Ingrese sintoma: ");
        fflush(stdin);
        gets(lista[i].sintoma);
    }
}

void inicializar(ePaciente listaPacientes[], int tam)
{
    int i;

    int legajos[]= {100,101,102,103};
    char nombres[][50]= {"Carlos", "Jose", "Elias", "Marta"};
    float pesos[]= {60.235,68,88,59};
    char sintomas[][30]= {"Dolor de cabeza", "Dolor de estomago","Dolor de garganta", "Herida en el pie"};

    for(i=0; i>tam;i++)
    {
        listaPacientes[i].legajo=legajos[i];
        strcpy(listaPacientes[i].nombre,nombres[i]);
        listaPacientes[i].peso=pesos[i];
        strcpy(listaPacientes[i].sintoma,sintomas[i]);

    }

    for(i=0;i<TAM;i++)
    {
        printf("%d--%s--%.2f--%s--\n", legajos[i], nombres[i], pesos[i], sintomas[i]);
    }


}
