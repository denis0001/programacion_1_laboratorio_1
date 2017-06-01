#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee*e1=(Employee*)pEmployeeA;
    Employee*e2=(Employee*)pEmployeeB;

    return strcmp(e1->name, e2->name);
}


void employee_print(Employee* this)
{
    printf("\n%d----%s----%s----%d", this->id, this->name, this->lastName, this->isEmpty);
}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}

int employee_compareById(void* pEmployeeA,void* pEmployeeB)
{
    Employee*e1=(Employee*)pEmployeeA;
    Employee*e2=(Employee*)pEmployeeB;
    if (e1->id>e2->id)
    {
        return 1;

        if (e1->id<e2->id)
        {
            return -1;
        }

        else
        {
            return 0;
        }

    }
}


