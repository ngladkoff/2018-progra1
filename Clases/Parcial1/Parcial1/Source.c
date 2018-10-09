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
	tAlumno alumnos2[5] = { {"Fernandez","Carlos", 20, 1, 10 }, {"Ramirez","Juan", 21, 2, 15 },{"Gaitan","Claudio", 22, 3, 5 },{"Gauna","Sergio", 23, 4, 7 },{"Carranza","Guillermo", 24, 1, 20 } };

	Incrementar5Porciento(produccion, 3);

	// printf("Posicion: %d\n", BuscarAlumno(alumnos, 5, "Gaitan"));

	EstadisticasAlumnos(alumnos2, 5);
}


void Incrementar5Porciento(int produccion[][5], int largo) {

	for (int f = 0; f < largo; f++) {
		for (int c = 0; c < 5; c++) {
			produccion[f][c] = produccion[f][c] * 1.05;
		}
	}

	// printf("Produccion 1,1: %d\n", produccion[1][1]);
}

int BuscarAlumno(char alumnos[][50], int largo, char *alumnoABuscar) {

	for (int i = 0; i < largo; i++)
	{
		if (strcmp(alumnos[i], alumnoABuscar) == 0) {
			return i;
		}
	}

	return -1;
}

void EstadisticasAlumnos(tAlumno alumnos[], int largo) {
	int alumnoMenor21 = 0;
	int cantMateriasMenores21 = 0;
	int carrera = 0;
	int cantAlumnosCarrera = 0;

	printf("Alumnos con mas de 10 materias aprobadas de software:\n");

	for (int i = 0; i < largo; i++) {
		
		if (alumnos[i].MateriasAprobadas > 10 && alumnos[i].Carrera == 3)
			printf("%s,%s\n", alumnos[i].Apellido, alumnos[i].Nombre);

		if (alumnos[i].Edad < 21)
		{
			alumnoMenor21++;
			cantMateriasMenores21 += alumnos[i].MateriasAprobadas;
		}
	}

	printf("Promedio Materias aprobadas menores de 21: %d\n", (cantMateriasMenores21 / alumnoMenor21));

	printf("Ingrese carrera a consultar: \n");
	scanf("%d", &carrera);

	for (int f = 0; f < largo; f++) {
		if (alumnos[f].Carrera == carrera)
			cantAlumnosCarrera++;
	}

	printf("Cant alumnos carrera: %d\n", cantAlumnosCarrera);

}



