#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char materia[100];
	int numero;
} tCurso;

typedef struct {
	int capacidad;
	int numero;
	int piso;
	tCurso cursos[10];
} tAula;

void imprimirAulas(tAula aulasUADE[]);

int main(void) {

	int matriz[4][4]; 

	int a= 0;
	int b= 0;

	char letra= 'a';
	char letra2 = 'b';

	char palabra[100] = "abc"; // == { 'a', 'b', 'c', '\0' };
	char palabra2[100] = "bcd";

	tAula miAula;
	tAula otraAula;

	tAula aulasUADE[10];

	tCurso curso1;
	tCurso curso2;

	strcpy(curso1.materia, "Progra1");
	curso1.numero = 3;

	strcpy(curso2.materia, "FDI");
	curso2.numero = 5;

	miAula.capacidad = 10;
	miAula.numero = 6;
	miAula.piso = 0;
	miAula.cursos[0] = curso1;
	miAula.cursos[1] = curso2;

	otraAula.capacidad = 20;
	otraAula.numero = 17;
	otraAula.piso = 1;

	aulasUADE[0] = miAula;
	aulasUADE[1] = otraAula;

	imprimirAulas(aulasUADE);

	if (a == b) {
	}
	if (letra == letra2) {
	}
	if (palabra == palabra2) { // NOOOOOOO
	}
	if (strcmp(palabra, palabra2) == 0) { // compara 2 variables string
	}

	a = strlen(palabra); // devuelve cantidad caracteres

	// palabra2 = palabra; NO SE PUEDE
	strcpy(palabra2, palabra);
	strcpy(palabra, "Hola");

	strncpy(palabra2, palabra + 1, 3); // palabra2 == "ola"

	if (strstr(palabra, "la") != NULL) {
		// lo encontre
	}

	if (strstr(palabra, palabra2)) {
		// lo encontre
	}

	printf("ingrese letra 1: \n");
	scanf("%c", &letra);

	// limpiar buffer
	printf("ingrese letra 2: \n");
	while (getchar() == "\n");
	scanf("%c", &letra2);




	for (int fila = 0; fila < 4; fila++) {
		for (int columna = 0; columna < 4; columna++) {
			if (fila == columna) 
				matriz[fila][columna] = 4-fila;
			else 
				matriz[fila][columna] = 0;
			
			printf("%d\t", matriz[fila][columna]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

void imprimirAulas(tAula aulas[]) {
	
	printf("Aula 1: %d, %d, %d\n", aulas[0].numero, 
		                           aulas[0].piso, 
		                           aulas[0].capacidad);

	printf("Aula 2: %d, %d, %d\n", aulas[1].numero,
								   aulas[1].piso,
								   aulas[1].capacidad);

	printf("%s\n", aulas[0].cursos[0].materia);

}