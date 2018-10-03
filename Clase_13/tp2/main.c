#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000

typedef struct{
int id;
char name[51];
char lastName[51];
float salary;
int idSector;
int isEmpty;
}Employee;

typedef struct{
int id;
char descripcion[51];
}eSector;

int initEmployees(Employee list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

int main()
{
    Employee list[TAM];

    initEmployees(list, TAM);


    return 0;
}


int menu()
{
    int opcion;
    system("cls");
    printf("***MENU***\n\n");
    printf("1- Altas\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int initEmployees(Employee* list, int len)
{
    for (int i= 0; i<len; i++){
        list[i].isEmpty=0;
    }
    return 0;
}



/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    for(int i=0; list[i].isEmpty<len;i++){
        if(list[i].isEmpty==0){
            list[i].id = id;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].idSector = sector;
            list[i].isEmpty=1;
            return 0;
        }
    }
    return -1;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
    for(int i=0; list[i].id<len; i++){
        if(list[i].id==id){
            return i;
        }
    }
return NULL
}


Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
return -1;
}
Ejemplo uso:
r = removeEmployee(arrayEmployees, ELEMENTS,20);
UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 5
Programación I – Laboratorio I
2.5 Función sort Employees
Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
return 0;
}
Ejemplo uso:
r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);
2.6 Función print Employees
Imprime el array de empleados de forma encolumnada.
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
return 0;
}
Ejemplo uso:
r = printEmployees(arrayEmployees, ELEMENTS);

