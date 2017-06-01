#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int i;
    ArrayList* lista;

    lista= al_newArrayList();

    Employee* e1;

    e1= (Employee*) malloc(sizeof(Employee));

    e1->id=11;
    e1->isEmpty=1;

    strcpy(e1->name, "juan");

    strcpy(e1->lastName, "perez");

    lista->add(lista,e1);

    Employee* e2;

    e2=(Employee*) malloc(sizeof(Employee));

    e2->id=10;
    e2->isEmpty=1;

    strcpy(e2->name, "marcelo");

    strcpy(e2->lastName, "juarez");

    lista->add(lista,e2);

    Employee* e3;

    e3=(Employee*) malloc(sizeof(Employee));

    e3->id=12;
    e3->isEmpty=1;

    strcpy(e3->name, "jose");

    strcpy(e3->lastName, "blanco");

    lista->add(lista,e3);

    printf("la cantidad de empleados es %d", al_len(lista));


    for (i=0; i<lista->len(lista);i++)
    {
        employee_print(lista->get(lista,i));
    }
    printf("\n////////////////\n");

   lista->sort(lista,employee_compare,1);





    return 0;
}
