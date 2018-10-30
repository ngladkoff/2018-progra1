#pragma warning (disable: 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
	int legajo;
	char nombre[100];
	char gerencia[100];
	char puesto[100];
} tEmpleado;

int CargarEmpleados(tEmpleado *);
void ImprimirEmpleados(tEmpleado *, int);
int ContarEmpGerencia(tEmpleado *ptrEmp, char *gerencia);

int main(void) {

	int cantEmpleados = 0;
	tEmpleado empleados[MAX];

	cantEmpleados= CargarEmpleados(empleados);

	printf("Cantidad de Empleados cargados: %d\n", cantEmpleados);
	system("pause");

	//printf("Emp gerencia: %d\n", ContarEmpGerencia(empleados, "Gerencia Comercial                                "));

	// ImprimirEmpleados(empleados, cantEmpleados);

	char busqueda[100]= "a";

	



	system("pause");
	return EXIT_SUCCESS;
}











int CargarEmpleados(tEmpleado *ptrEmpleado) {

	FILE *f;
	int i = 0;
	char strLinea[200];

	char strLegajo[9];

	f = fopen("c:\\temp\\empleadosArsat.txt", "r");

	if (f == NULL)
	{
		printf("Error, no se pudo abrir el archivo");
		system("pause");
		exit(EXIT_FAILURE);
	}

	fgets(strLinea, 200, f);

	while (!feof(f) && i < MAX) {


		// Proceso
		// sscanf(strLinea, "%d", &ptrEmpleado->legajo);

		strncpy(strLegajo, strLinea, 8);
		strLegajo[8] = '\0';
		ptrEmpleado->legajo = atoi(strLegajo);

		strncpy(ptrEmpleado->nombre, strLinea + 8, 40);
		ptrEmpleado->nombre[40]= '\0';
				
		strncpy(ptrEmpleado->gerencia, strLinea + 48, 50);
		ptrEmpleado->gerencia[50] = '\0';
		
		
		strncpy(ptrEmpleado->puesto, strLinea + 98, 90);
		ptrEmpleado->puesto[90] = '\0';


		i++;
		ptrEmpleado++;
		fgets(strLinea, 200, f);
	}

	fclose(f);



	return i;
}

void ImprimirEmpleados(tEmpleado *ptrEmpleado, int max) {
	int i = 0;

	while (i < max) {
		printf("%d %s %s %s\n", ptrEmpleado->legajo, ptrEmpleado->nombre, ptrEmpleado->gerencia, ptrEmpleado->puesto);
		ptrEmpleado++;
		i++;
	}

}

int ContarEmpGerencia(tEmpleado *ptrEmp, char *gerencia) {
	int i = 0;
	int cant = 0;

	while (i < MAX) {

		if (strcmp(ptrEmp->gerencia, gerencia) == 0) {
			cant++;
		}

		ptrEmp++;
		i++;
	}
	return cant;
}