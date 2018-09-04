#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int tipo;
	int nro;
} naipe;

struct fecha {
	int anio;
	int mes;
	int dia;
};

struct persona {
	char nombre[20];
	char apellido[20];
	int edad;
	struct fecha diaNacimiento;
	struct persona *padre;
};

int main(void) {
	struct persona alumno;
	struct persona alumnos[20] = { -1 };

	naipe mazo[50];

	strcpy(alumno.nombre, "nicolas");
	alumno.edad = 20;
	alumno.diaNacimiento.anio = 1980;

	scanf("%s", &alumnos[0].nombre);



	alumnos[1].edad = 30;

	printf("%s", alumno.nombre);

	system("pause");
	return 0;
}

void cargarAlumno(struct persona alumnos[]) {

	scanf("%s", &alumnos[0].nombre);


}
