#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int dia, mes, anio;
} tFecha;

typedef struct {
	char nombre[50];
	float precio;
	tFecha fechaAlta;
} tProducto;

void Menu(tProducto productos[]);
void Alta(tProducto productos[]);
void Baja(tProducto productos[]);
void Mostrar(tProducto productos[]);
void OrdenarVector(tProducto productos[]);

int main(void) {
	tProducto productos[1000];

	for (int i = 0; i < 1000; i++) {
		productos[i].precio = -1;
	}

	Menu(productos);	

	system("pause");
	return EXIT_SUCCESS;
}

void Menu(tProducto productos[]) {
	int opcion;
	
	while (1==1) {
		system("cls");
		printf("Seleccione opcion:\n1-Alta\n2-Baja\n3-Mostrar\n5-Salir\n");
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			Alta(productos);
			break;
		case 2:
			Baja(productos);
			break;
		case 3:
			Mostrar(productos);
			break;
		case 5:
			return;
		}
	}
}

void Alta(tProducto productos[]) {
	int i = 0;
	// Busco posición vacía
	for (i = 0; i < 1000; i++) {
		if (productos[i].precio == -1)
			break;
	}

	if (i == 1000)
	{
		printf("No hay mas espacio para guardar productos\n");
		return;
	}

	// Pido datos
	printf("Ingrese nombre: ");
	scanf("%s", &productos[i].nombre);
	printf("Ingrese precio: ");
	scanf("%f", &productos[i].precio);
	printf("Ingrese Fecha\nIngrese día");
	scanf("%d", &productos[i].fechaAlta.dia);
	printf("Ingrese mes");
	scanf("%d", &productos[i].fechaAlta.mes);
	printf("Ingrese anio");
	scanf("%d", &productos[i].fechaAlta.anio);
	
}


void Baja(tProducto productos[]) {
	char nombreABuscar[50];

	printf("Ingrese nombre del producto a borrar: ");
	scanf("%s", &nombreABuscar);

	for (int i = 0; i < 1000; i++)
	{
		// no puedo hacer esto:
		// if (nombre == productos[i].nombre)
		if (strcmp(productos[i].nombre, nombreABuscar) == 0) {
			productos[i].precio = -1;
		}
	}
}

void Mostrar(tProducto productos[])
{
	OrdenarVector(productos);

	for (int i = 0; i < 1000; i++)
	{
		if (productos[i].precio == -1) 
			continue;

		printf("Nombre: %s\n", productos[i].nombre);
		printf("Precio: %f\n", productos[i].precio);
		printf("Fecha Alta: %d / %d / %d \n", productos[i].fechaAlta.dia, productos[i].fechaAlta.mes, productos[i].fechaAlta.anio);

		printf(" ---------------------------------------------------------- \n");
	}
}

void OrdenarVector(tProducto productos[]) {

	tProducto auxProducto;

	for (int j = 1; j < 1000; j++) {
		for (int i = 0; i < (1000 - 1); i++) {
			if (productos[i].precio == -1 || strcmp(productos[i].nombre, productos[i + 1].nombre) > 0) {
				auxProducto = productos[i];
				productos[i] = productos[i + 1];
				productos[i + 1] = auxProducto;
			}
		}
	}
}