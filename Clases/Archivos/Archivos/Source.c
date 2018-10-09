#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char Nombre[20];
	int edad;
	int matAprobadas;
} tPersona;

int main(void) {
	tPersona alumno2;

	tPersona alumno;
	alumno.edad = 20;
	strcpy(alumno.Nombre, "Nicolas");

	char temporal[100];

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

	FILE *archivo;
	// f = fopen("archivo.txt", "w");
	archivo = fopen("C:\\Users\\nicol\\Desktop\\archivo.txt", "w");

	if (archivo == NULL) {
		printf("No se pudo abrir archivo");
		exit(EXIT_FAILURE);
	}

	/*
	*/
	for (int i = 0; i < 10; i++) {
		fprintf(archivo, "%d: %s||%d\n", i, alumno.Nombre, alumno.edad);
	}

	fclose(archivo);

	archivo = fopen("C:\\Users\\nicol\\Desktop\\archivo.txt", "r");
	if (archivo == NULL) {
		printf("No se pudo abrir archivo");
		exit(EXIT_FAILURE);
	}

	fgets(temporal, 100, archivo);
	while (!feof(archivo)) {
		printf("%s", temporal);
		fgets(temporal, 100, archivo);
	}


	fclose(archivo); 

	
	
	// fprintf(stdout, "fin\n");

	// Binario
	archivo = fopen("C:\\Users\\nicol\\Desktop\\archivo.bin", "wb");
	fwrite(&alumno, sizeof(tPersona), 1, archivo);
	fseek(archivo, 0, SEEK_SET);
	fclose(archivo);

	archivo = fopen("C:\\Users\\nicol\\Desktop\\archivo.bin", "rb");
	fread(&alumno2, sizeof(tPersona), 1, archivo);
	fclose(archivo);

	printf("%s %d", alumno2.Nombre, alumno2.edad);

	system("pause");
	return EXIT_SUCCESS;
}