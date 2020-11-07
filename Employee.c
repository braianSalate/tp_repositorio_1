#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

int employeeSortByName(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;
    char nombreA[20];
    char nombreB[20];

    if(empleadoA != NULL && empleadoB !=NULL)
    {

        empleadoGetNombre((Employee*) empA, nombreA);
        empleadoGetNombre((Employee*) empB, nombreB);

        retorno = strcmp(nombreA, nombreB);
    }

    return retorno;
}


int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;
    int idA;
    int idB;

    if(empleadoA != NULL && empleadoB !=NULL)
    {

        //employee_getId((Employee*) empA, &idA);
        //employee_getId((Employee*) empB, &idB);

        retorno = idA - idB;
    }

    return retorno;

}


int employeeSortByWorkHours(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;
    int horasA;
    int horasB;

    if(empleadoA != NULL && empleadoB !=NULL)
    {

        empleadoGetHorasTrabajadas((Employee*) empA, &horasA);
        empleadoGetHorasTrabajadas((Employee*) empB, &horasB);

        retorno = horasA - horasB;
    }

    return retorno;

}


int employeeSortBySalary(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;
    int sueldoA;
    int sueldoB;

    if(empleadoA != NULL && empleadoB !=NULL)
    {

        empleadoGetId((Employee*) empA, &sueldoA);
        empleadoGetId((Employee*) empB, &sueldoB);

        retorno = sueldoA - sueldoB;
    }

    return retorno;

}

Employee* employee_new()
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado;

    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        nuevoEmpleado = employee_new();
        if(nuevoEmpleado!=NULL)
        {
            if( !empleadoSetId(nuevoEmpleado, atoi(idStr))
               || !empleadoSetNombre(nuevoEmpleado, nombreStr)
               || !empleadoSetHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))
               || !empleadoSetSueldo(nuevoEmpleado, atoi(sueldoStr)))
            {
                employee_delete(nuevoEmpleado);
                nuevoEmpleado = NULL;
            }
        }
    }



    return nuevoEmpleado;
}


int empleadoSetId(Employee* empleado, int id)
{
    int error = 1;

    if(empleado != NULL && id>0)
    {
        empleado->id = id;
        error = 0;
    }

    return error;
}
int empleadoSetNombre(Employee* empleado, char* nombre)
{
    int error = 1;

    if(empleado != NULL && strlen(nombre>=3) && strlen(nombre)<20)
    {
        strcpy(empleado->nombre, nombre);
        error = 0;
    }

    return error;
}
int empleadoSetHorasTrabajadas(Employee* empleado, int horasTrabajadas)
{
    int error = 1;

    if(empleado != NULL )
    {
        empleado->horasTrabajadas = horasTrabajadas;
        error = 0;
    }

    return error;
}
int empleadoSetSueldo(Employee* empleado, int sueldo)
{
    int error = 1;

    if(empleado != NULL && sueldo > 10000 && sueldo < 1000000)
    {
        empleado->sueldo = sueldo;
        error = 0;
    }

    return error;
}

int empleadoGetId(int* pId, Employee* empleado)
{
    int error = 1;

    if(empleado != NULL && pId != NULL)
    {
        *pId = empleado->id;
        error = 0;
    }

    return error;
}
int empleadoGetNombre(char* pNombre, Employee* empleado)
{
    int error = 1;

    if(empleado != NULL && pNombre != NULL)
    {
        strcpy(pNombre, empleado->nombre);
        error = 0;
    }

    return error;
}
int empleadoGetHorasTrabajadas(int* pHorasTrabajadas,Employee* empleado)
{
    int error = 1;

    if(empleado != NULL && pHorasTrabajadas > 0)
    {
        *pHorasTrabajadas = empleado->horasTrabajadas;
        error = 0;
    }

    return error;
}
int empleadoGetSueldo(int* pSueldo,Employee* empleado)
{
    int error = 1;

    if(empleado != NULL && pSueldo != NULL)
    {
        *pSueldo = empleado->sueldo;
        error = 0;
    }

    return error;
}

int destruirEmpleado(LinkedList* pArrayListEmployee)
{

    int error = 0;
    int idEliminar;
    int indice;
    char confirma;

    if(pArrayListEmployee !=NULL)
    {
        printf("\033[2J");

        printf("-----------------------\n");
        printf(" ***Eliminar Empleado***\n");
        printf("-----------------------\n");

        listarEmpleados(pArrayListEmployee);

        printf(" Ingrese ID del empleado que desea eliminar: ");
        scanf("%d", &idEliminar);



        indice = buscarId(idEliminar,pArrayListEmployee);

        if(indice == -1)
        {
            printf("El id ingresado no existe ");
        }
        else
        {
            printf("\033[2J");
            printf("-----------------------\n");
            printf("    ***  Empleado  ***\n");
            printf("-----------------------\n");

            printf("   Id   Nombre   HorasTrabajadas   Sueldo\n");
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,indice));

            printf("Confirma que desea eliminar el empleado?");
            printf("s para si\n n para no\n");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                ll_remove(pArrayListEmployee,indice);

                printf(" Se elimino el empleado\n");
            }
            else
            {
                printf(" Se cancela!\n");
            }
        }

        error = 1;

    }

    return error;
}

int buscarId(int id, LinkedList* empleados)
{
    int indice = -1;
    Employee* auxEmp;
    int tam = ll_len(empleados);

    if(empleados !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            auxEmp = (Employee*)ll_get(empleados,i);

            if(auxEmp !=NULL && auxEmp->id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}



void mostrarEmpleado(LinkedList* pArrayListEmployee)
{
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    Employee* empleado;

    if(empleado !=NULL)
    {
        if(empleadoGetId(empleado,&id)
           && empleadoGetNombre(empleado,nombre)
           && empleadoGetHorasTrabajadas(empleado,&horasTrabajadas)
           && empleadoGetSueldo(empleado,&sueldo))
        {
            printf("%d %10s %d %d\n",id,nombre,horasTrabajadas,sueldo);
        }
    }
}

int mostrarEmpleados(LinkedList* lista)
{
    int error = 0;
    int flag = 0;

    if(lista != NULL)
    {
        error = 1;
        printf(" ID      Nombre      HS     Sueldo\n");
        for(int i=0; i<ll_len(lista); i++)
        {
            if( ((Employee*) ll_get(lista, i)) !=NULL)
            {
                mostrarEmpleado((Employee*)ll_get(lista, i));
                flag =1;
            }
        }
        if(flag == 0)
        {
            printf("No hay empleados que mostrar\n\n");
        }

    }
    return error;
}

int agregarEmpleado(LinkedList* pArrayListEmployee)
{
    int error = 0;
    Employee* nuevoEmpleado;
    char nombre[50];
    char horasTrabajadasStr[20];
    int horasTrabajadas;
    char sueldoStr[20];
    int horas;
    int sueldo;

    nuevoEmpleado = employee_new();

    if(pArrayListEmployee !=NULL && nuevoEmpleado !=NULL)
    {
        printf("\033[2J");

        printf("--------------------\n");
        printf(" ***Alta Empleado***\n");
        printf("--------------------\n");


        printf(" Ingrese nombre nuevo empleado: ");
        fflush(stdin);
        scanf("%s", nombre);

        empleadoSetNombre(nuevoEmpleado,nombre);

        printf("\n");

        printf(" Ingrese horas nuevo empleado: ");
        fflush(stdin);
        scanf("%s", horasTrabajadasStr);
        horasTrabajadas = atoi(horasTrabajadasStr);

        empleadoSetHorasTrabajadas(nuevoEmpleado,horasTrabajadas);

        printf("\n");

        printf(" Ingrese sueldo nuevo empleado: ");
        fflush(stdin);
        scanf("%s", sueldoStr);
        sueldo = atoi(sueldoStr);

        empleadoSetSueldo(nuevoEmpleado,sueldo);

        if(nuevoEmpleado !=NULL)
        {
            nuevoEmpleado->id = proximoId();
            ll_add(pArrayListEmployee,nuevoEmpleado);

            error = 1;
        }
    }

    return error;


}

static int obtenerId()
{
    static int id=1000;
    id++;
    return id;
}

int ordenarEmpleados(LinkedList* pArrayListEmployee)
{
    int error = 0;
    int opcion;


         printf("\033[2J");

        printf("----------------------\n");
        printf(" ***Ordenar Empleados***\n");
        printf("----------------------\n");

    if(pArrayListEmployee !=NULL)
    {
        printf(" Ingrese como desea ordenar los empleados\n");
        printf(" 1 ID\n");
        printf(" 2 nombre\n");
        printf(" 3 horas trabajdas\n");
        printf(" 4 sueldo\n");
        printf(" Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(ll_sort(pArrayListEmployee, employeeSortById, 1)==-1)
            {
                error = 0;
            }
            else
            {
                error = 1;
            }
            break;
        case 2:
            if(ll_sort(pArrayListEmployee, employeeSortByName, 1)==-1)
            {
                error = 0;
            }
            else
            {
                error = 1;
            }
            break;
        case 3:
            if(ll_sort(pArrayListEmployee, employeeSortByWorkHours, 1)==-1)
            {
                error = 0;
            }
            else
            {
                error = 1;
            }
            break;
        case 4:
            if(ll_sort(pArrayListEmployee, employeeSortBySalary, 1)==-1)
            {
                error = 0;
            }
            else
            {
                error = 1;
            }
            break;
        default:
            error = 0;
            printf(" No existe la opcion ingresada\n");
            break;
        }
    }

    return error;
}

int listarEmpleados(LinkedList* pArrayListEmployee)
{
    int error = 0;
    Employee* empleado;
    int tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
         printf("\033[2J");

        printf("----------------------\n");
        printf(" ***Listar Empleados***\n");
        printf("----------------------\n");



        error = 1;

        for(int i=0; i < tam; i++)
        {

                getchar();
                getchar();
                printf("\033[2J");
                printf("   Id   Nombre   HorasTrabajadas  Sueldo\n");

                empleado = (Employee*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado(empleado);


        }
    }


    return error;
}


int modificarEmpleado(LinkedList* pArrayListEmployee)
{
    int error = 0;
    Employee* empleado;
    int id;
    int indice;
    int opcion;
    char confirma;
    char nuevoNombre[50];
    int horasTrabajadas;
    int nuevoSueldo;


    if(pArrayListEmployee !=NULL)
    {
        printf("\033[2J");

        printf("----------------------\n");
        printf(" ***Modificar Empleados***\n");
        printf("----------------------\n");

        listarEmpleados(pArrayListEmployee);

        printf(" Ingrese el ID del empleadoa modificar: ");
        scanf("%d", &id);


        indice = buscarId(id,pArrayListEmployee);

        if(indice == -1)
        {
            printf("no existe el id ingresado\n");
        }
        else
        {
              printf("\033[2J");

            printf("----------------------\n");
            printf(" ***Empleado***\n");
            printf("----------------------\n");

            printf("   Id   Nombre   HorasTrabajadas   Sueldo\n");
            printf("   --   ------   -----   ------\n");
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,indice));
            empleado = (Employee*)ll_get(pArrayListEmployee,indice);


            printf(" Que desea modificar?\n");
            printf(" 1 Nombre\n");
            printf(" 2 Horas trabajadas\n");
            printf(" 3 sueldo\n");
            printf(" Ingrese opcion: ");
            scanf("%d", &opcion);



            switch(opcion)
            {
            case 1:
                printf("\033[2J");

                printf(" Ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s", nuevoNombre);


                printf("Confirma nuevo nombre?\n");
                printf("s para si\n n para no\n");
                fflush(stdin);
                scanf("%c", &confirma);


                if(confirma == 's')
                {
                    strcpy(empleado->nombre,nuevoNombre);
                    error = 1;
                    printf(" Modificacion exitosa!!!\n");
                }
                else
                {
                    error = 1;
                    printf(" ha cancelado la modificacion\n");
                }
                break;
            case 2:

                printf("\033[2J");
                printf(" Ingrese nuevas horas trabajadas: ");
                scanf("%d", &horasTrabajadas);

                printf("Confirma nuevas horas?\n");
                printf("s para si\n n para no\n");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's')
                {
                    error = 1;
                    empleado->horasTrabajadas = horasTrabajadas;
                    printf("\n");
                    printf(" Modificacion exitosa!!!\n");
                }
                else
                {
                    error = 1;
                     printf(" has cancelado la modificacion\n");
                }
                break;
            case 3:

                printf("\033[2J");

                printf(" Ingrese nuevo sueldo: ");
                scanf("%d", nuevoSueldo);

                printf("Confirma nuevo sueldo?\n");
                printf("s para si\n n para no\n");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's')
                {
                    error = 1;
                    empleado->sueldo = nuevoSueldo;
                    printf("\n");
                    printf(" Modificacion exitosa!!!\n");
                }
                else
                {
                    error = 1;
                    printf(" has cancelado la modificacion\n");
                }
                break;
            default:
                error = 0;
                printf(" No existe la opcion ingresada\n");
            }
        }
    }

    return error;
}


void employee_delete(Employee* empleado)
{
    free(empleado);
    empleado=NULL;
}

int proximoId()
{
    return obtenerId();
}
