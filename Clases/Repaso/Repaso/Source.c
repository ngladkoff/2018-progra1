#pragma warning (disable: 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char nombre[50];
	int edad;
	long lu;
} tAlumno;

int main(void)
{
	// alumno
	// char nombre[50];
	// int edad;
	// long lu;
	tAlumno alumno;
	tAlumno alumno2;
	strcpy(alumno.nombre, "Nicolas");
	alumno.edad = 5;
	alumno2.lu = 1234;

	//alumnos
	//char nombre[100][50];
	//int edad[100];
	//long lu[100];
	tAlumno cursoProgra1[30];

	cursoProgra1[5].edad = 30;
	strcpy(cursoProgra1[5].nombre, "D");

	for (int j = 0; j < 30; j++) {
		strcpy(cursoProgra1[j].nombre, "");
	}



	scanf("%s", &cursoProgra1[5].nombre);

	//printf("Edad: %d\n", cursoProgra1[5].edad);
	//printf("Nombre: %s\n", cursoProgra1[5].nombre);

	for (int i = 0; i < 30; i++) {
		
		if (strlen(cursoProgra1[i].nombre) <= 0)
			continue;

		printf("Nombre: %s\n", cursoProgra1[i].nombre);
		printf("Edad: %d\n", cursoProgra1[i].edad);
		printf("Lu: %d\n", cursoProgra1[i].lu);
		printf("----------------------------------\n");
	}

	int opcion= 0;

	// edad = 0;

	/*

	printf("Ingrese su edad: \n");
	scanf("%d", &edad);

	if (edad >= 21) {
		printf("Es mayor de edad\n");
	}
	else {
		printf("No es mayor de edad\n");
	}
	*/
	opcion = 5;

	do
	{

		printf("Seleccione opcion: \n1-Alta\n2-Baja\n3 o 4-Borrar\n5-Salir\n");
		scanf("%d", &opcion);

		/*
		if (opcion == 1) {
			//alta
		}
		else if (opcion == 2)
		{
			//baja
		}
		else if (opcion == 3 || opcion == 4)
		{
			//borrar
		}
		else if (opcion == 5)
		{
			// salir
		}
		else
		{
			// opcion erronea
		}
		*/

		switch (opcion)
		{
		case 1:
			// alta
			printf("Seleccionó ALTA\n");
			system("pause");
			break;
		case 2:
			// baja
			printf("Seleccionó BAJA\n");
			system("pause");
			break;
		case 3:
		case 4:
			// borrar
			printf("Seleccionó BORRAR\n");
			system("pause");
			break;
		case 5:
			// salir
			printf("Seleccionó SALIR\n");
			system("pause");
			break;
		default:
			// opcion erronea
			printf("opcion erronea\n");
			system("pause");
			break;
		}

	} while (opcion != 5);

	system("pause");
	return 0;
}