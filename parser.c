#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int cant;
    char buffer[4][100];

    Employee* auxEmpleado;


    if(pFile == NULL)
    {
        printf("no se puede abrir el archivo!\n");
        exit(EXIT_FAILURE);
    }
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
        printf("%s   %s   %s  %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3] );

        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant == 4)
            {
                auxEmpleado = new_empleadoParam(atoi(buffer[0]), buffer[1], buffer[2][0], atof(buffer[3]));
                printf("%d %s %c %.2f", auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
                todoOk = 0;

            }
            else
            {
                break;
            }
        }


        fclose(pFile);
        return todoOk;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error = -1;
    Employee* nuevoEmpleado;
    int cant;

    if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
        while(!feof(pFile))
        {
            nuevoEmpleado = employee_new();

            if(nuevoEmpleado !=NULL)
            {
                cant = fread(nuevoEmpleado, sizeof(Employee), 1, pFile);

                if( cant < 1)
                {
                    if(feof(pFile))
                    {

                        break;
                    }
                    else
                    {
                        printf("Problemas para leer el archivo");
                    }
                }
                ll_add(pArrayListEmployee,nuevoEmpleado);
            }
        }

        error = 0;
    }

    return error;
}
