#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

int mostrarEmpleados(LinkedList* lista);
void mostrarEmpleado(LinkedList* pArrayListEmployee);


void employee_delete(Employee* this);

int empleadoSetId(Employee* this,int id);
int empleadoGetId(int* pId, Employee* empleado);

int empleadoSetNombre(Employee* this,char* nombre);
int empleadoGetNombre(char* pNombre, Employee* empleado);

int empleadoSetHorasTrabajadas(Employee* this,int horasTrabajadas);
int empleadoGetHorasTrabajadas(int* pHorasTrabajadas,Employee* empleado);

int empleadoSetSueldo(Employee* this,int sueldo);
int empleadoGetSueldo(int* pSueldo,Employee* empleado);

int employeeSortByName(void* empleadoA, void* empleadoB);
int employeeSortById(void* empleadoA, void* empleadoB);
int employeeSortByWorHours(void* empleadoA, void* empleadoB);
int employeeSortBySalary(void* empleadoA, void* empleadoB);

int destruirEmpleado(LinkedList* pArrayListEmployee);
int buscarId(int id, LinkedList* empleados);
int agregarEmpleado(LinkedList* pArrayListEmployee);
int ordenarEmpleados(LinkedList* pArrayListEmployee);
int listarEmpleados(LinkedList* pArrayListEmployee);


#endif // employee_H_INCLUDED
