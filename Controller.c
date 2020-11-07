#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    FILE* f;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            if(!parser_EmployeeFromText(f, pArrayListEmployee))
            {
                printf("Carga de datos en modo texto exitosa!!\n");
                todoOk = 0;
            }
            else
            {
                printf("Carga de datos en modo texto fallida!!\n");
            }

            fclose(f);
        }

    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    FILE* f;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path, "rb");
        if(f != NULL)
        {
            if(!parser_EmployeeFromBinary(f, pArrayListEmployee))
            {
                todoOk = 0;
                printf("Carga de datos en modo binario exitosa!!\n");
            }
            else
            {
                printf("Carga de datos en modo binario exitosa!!\n");
            }

            fclose(f);
        }

    }

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(!agregarEmpleado(pArrayListEmployee))
        {
            printf(" Problema para dar el alta\n");

        }
        else
        {
            printf(" Se dio de alta exitosamente!!\n");
            error = 1;
        }
    }

    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
       int error = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(modificarEmpleado(pArrayListEmployee))
        {
            printf("Modificacion exitosa!!\n");
            error = 1;
        }
        else
        {
            printf(" Modificacion fallida\n");
        }
    }
    return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(destruirEmpleado(pArrayListEmployee))
        {
            error  =1;
            printf("Baja de empleado exitosa!!\n");
        }
        else
        {
            printf("Baja de empleado fallida!!\n");
        }
    }

    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
     int error = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(listarEmpleados(pArrayListEmployee))
        {
            printf(" listado de empleados exitoso!!!\n");
            error = 1;
        }
        else
        {
             printf(" listado de empleados fallido!!!\n");
        }
    }
    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(ordenarEmpleados(pArrayListEmployee))
        {
            printf("orden de empleados exitoso!!\n");
            error = 1;
        }
        else
        {
           printf("orden de empleados fallido!!\n");
        }
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int error = -1;
    Employee* nuevoEmpleado;
    FILE* p;


    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        p = fopen(path,"w");

        if(p !=NULL)
        {
            fprintf(p,"Id,Nombre,Horas trabajadas,Sueldo\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (Employee*)ll_get(pArrayListEmployee,i);

                if(nuevoEmpleado !=NULL)
                {
                    fprintf(p,"%d,%s,%d,%d\n",nuevoEmpleado->id,nuevoEmpleado->nombre,nuevoEmpleado->horasTrabajadas,nuevoEmpleado->sueldo);
                }
            }

            printf(" se han guardado los empleados en modo texto!\n");
            error = 0;
        }
        else
        {
            printf(" No se han podido guardar los empleados en modo texto\n");
        }

        fclose(p);
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error = -1;
    Employee* nuevoEmpleado;
    FILE* p;


    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        p = fopen(path,"wb");

        if(p !=NULL)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (Employee*)ll_get(pArrayListEmployee,i);

                if(nuevoEmpleado !=NULL)
                {
                    fwrite(nuevoEmpleado,sizeof(Employee),1,p);
                }
            }

            printf(" Se han guardado los empleados en modo binario!\n");
            error = 0;
        }
        else
        {
            printf(" No se han podido guardar los empleados en modo binario\n");
        }

        fclose(p);
    }

    return error;
}

