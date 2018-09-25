#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char Nombre[20];
	int edad;
} tPersona;

int main(void) {
	tPersona alumno;
	alumno.edad = 20;
	strcpy(alumno.Nombre, "Nicolas");

	char lectura[100];

	/*
	
	tPersona alumnos[100];

	alumnos[0].edad = 25;
	strcpy(alumnos[0].Nombre, "Alejandro");

	alumno.edad = 20;
	strcpy(alumno.Nombre, "Nicolas");

	for (int i = 0; i < 100; i++) {
		printf("%s %d\n", alumnos[i].Nombre, alumnos[i].edad);
	}

	*/

	FILE *f;
	// f = fopen("archivo.txt", "w");

	f = fopen("archivo.txt", "r");
	if (f == NULL) {
		printf("No se pudo abrir archivo");
		exit(EXIT_FAILURE);
	}

	fgets(lectura, 100, f);
	while (!feof(f)) {
		printf("%s", lectura);
		fgets(lectura, 100, f);
	}
	
	// fprintf(f, "%s %d\n", alumno.Nombre, alumno.edad);

	// fprintf(stdout, "fin\n");

	fclose(f);

	system("pause");
	return EXIT_SUCCESS;
}