#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int opcion;
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();


      do
    {
        printf("*** tp 3 ***\n\n");
        printf("1 Cargar datos modo texto\n");
        printf("2 Cargar datos modo binario\n");
        printf("3 Alta empleado\n");
        printf("4 Modificar empleado\n");
        printf("5 Eliminar empleado\n");
        printf("6 listar empleados\n");
        printf("7 Ordenar empleados\n\n");
        printf("8 Guardar empleados modo texto\n");
        printf("9 Guardar empleados modo binario\n");
        printf("10 salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                if(controller_loadFromText("./data.csv", listaEmpleados))
                {
                    printf("Problemas para cargar la lista!!\n");
                }
                else
                {
                    printf("Carga correcta de empleados.\n");
                }
            break;
        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);


            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_editEmployee(listaEmpleados);

            break;
        case 5:
            controller_removeEmployee(listaEmpleados);

            break;
        case 6:
                controller_ListEmployee(listaEmpleados);

            break;


        case 7:

            controller_sortEmployee(listaEmpleados);
            break;
            case 8:

           controller_saveAsText("data.csv",listaEmpleados);
            break;
              case 9:

           controller_saveAsBinary("data.bin",listaEmpleados);
            break;
            case 10:
                seguir = 'n';
                ll_deleteLinkedList(listaEmpleados);
            break;
            default:
                printf("opcion invalida");
            }

        getchar();
        getchar();

        }while( seguir == 's');





    return 0;
}


char menu()
{
    int opcion;
    printf("\033[2J");

    printf("*** tp 3 ***\n\n");
    printf("1 Cargar datos modo texto\n");
    printf("2 Cargar datos modo binario\n");
    printf("3 Alta empleado\n");
    printf("4 Modificar empleado\n");
    printf("5 Eliminar empleado\n");
    printf("6 listar empleados\n");
    printf("7 Ordenar empleados\n\n");
    printf("8 Guardar empleados modo texto\n");
    printf("9 Guardar empleados modo binario\n");
    printf("10 salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion > 10 )
        {
            printf("Opcion elegida invalida, ingrese operacion a realizar: ");

            scanf("%d", &opcion);
        }

    return opcion;
}
