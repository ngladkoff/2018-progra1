#pragma warning (disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char Apellido[50];
	char Nombre[50];
	int Edad;
	int Carrera;
	int MateriasAprobadas;
} tAlumno;

void Incrementar5Porciento(int produccion[][5], int largo);
int BuscarAlumno(char alumnos[][50], int largo, char *alumnoABuscar);
void EstadisticasAlumnos(tAlumno alumnos[], int largo);

int main(void) {
	int produccion[3][5] = { {100,200,300,400,500}, {100,200,300,400,500}, {100,200,300,400,500} };
	char alumnos[5][50] = { "Fernandez", "Ramirez", "Gaitan", "Gauna", "Carranza" };
	char aBuscar[50] = "Gaitan";
	int posAlumno;
	tAlumno alumnos2[5] = { {"Fernandez","Carlos", 20, 1, 10 }, {"Ramirez","Juan", 21, 2, 15 },{"Gaitan","Claudio", 22, 3, 5 },{"Gauna","Sergio", 23, 4, 7 },{"Carranza","Guillermo", 24, 1, 20 } };

	Incrementar5Porciento(produccion, 3);
	posAlumno = BuscarAlumno(alumnos, 5, aBuscar);
	EstadisticasAlumnos(alumnos2, 5);

	system("pause");
	return 0;
}

void Incrementar5Porciento(int produccion[][5], int largo) {
	for (int fila= 0; fila < largo; fila++) {
		for (int columna= 0; columna < 5; columna++) {
			produccion[fila][columna] = produccion[fila][columna] * 1.05;
		}
	}
}

int BuscarAlumno(char alumnos[][50], int largo, char *alumnoABuscar) {
	for (int i = 0; i < largo; i++) {
		if (strcmp(alumnos[i], alumnoABuscar) == 0) {
			return i;
		}
	}
	return -1;
}

void EstadisticasAlumnos(tAlumno alumnos[], int largo) {
	int cantAlu = 0;
	int cantMat = 0;
	int nroCarrera = 0;

	// 3.1
	for (int i = 0; i < largo; i++) {
		if (alumnos[i].Carrera == 3 && alumnos[i].MateriasAprobadas > 10) {
			printf("%s %s\n", alumnos[i].Nombre, alumnos[i].Apellido);
		}
	}

	// 3.2
	for (int j = 0; j < largo; j++) {
		if (alumnos[j].Edad < 21) {
			cantAlu++;
			cantMat = cantMat + alumnos[j].MateriasAprobadas;
		}
	}
	printf("Prom: %d\n", cantMat / cantAlu);

	// 3.3
	printf("Nro Carrera?\n");
	scanf("%d", &nroCarrera);

	cantAlu = 0;
	for (int j = 0; j < largo; j++) {
		if (alumnos[j].Carrera == nroCarrera) {
			cantAlu++;
		}
	}
	printf("Cant: %d\n", cantAlu);






}