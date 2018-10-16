#pragma warning (disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXPROD 100

typedef struct {
	int codigo;
	char nombre[20];
	float precio;
	int stock;
} tProducto;

int Menu();
void AltaProducto(tProducto productos[]);
int BuscarProductoPorCodigo(tProducto productos[], int valorABuscar);
int IngresarEntero(char mensaje[], int min, int max, char error[]);
void ListarProductos(tProducto productos[]);
void CargarDatos(tProducto productos[]);
void GuardarDatos(tProducto productos[]);
void EditarProducto(tProducto productos[]);
void ExportarTxt(tProducto productos[]);

int main(void) {
	tProducto productos[MAXPROD] = {0};
	int opcionMenu;

	// Cargar los datos
	CargarDatos(productos);

	do {
		opcionMenu = Menu();
		switch (opcionMenu) {
		case 1:
			AltaProducto(productos);
			break;
		case 2:
			ListarProductos(productos);
			break;
		case 3:
			EditarProducto(productos);
			break;
		case 4:
			ExportarTxt(productos);
			break;
		case 5:
			break;
		default:
			printf("Opcion no valida\n");
			system("pause");
			exit(EXIT_FAILURE);
		}
	} while (opcionMenu != 5);

	// Guardar datos
	GuardarDatos(productos);
	return 0;
}

int Menu() {
	int opcion= 0;

	system("cls");
	printf("** MENU **\n");
	printf("1-Alta\n");
	printf("2-Listar\n");
	printf("3-Editar\n");
	printf("4-Exportar a txt\n");
	printf("5-Salir\n");
	opcion = IngresarEntero("Seleccione opcion:", 1, 5, "Seleccione un Nro de 1 a 5");
	return opcion;
}

void AltaProducto(tProducto productos[]) {
	int posVacia = 0;
	int codigoIngresado;
	posVacia = BuscarProductoPorCodigo(productos, 0);
	if (posVacia == -1) {
		printf("No existe mas capacidad para agregar productos\n");
		system("pause");
		return;
	}
	// tengo posVacia
	do {
		codigoIngresado= IngresarEntero("Ingrese codigo:", 1, 100, "Ingrese un codigo de 1 a 100");

		if (BuscarProductoPorCodigo(productos, codigoIngresado) == -1)
			productos[posVacia].codigo = codigoIngresado;

	} while (productos[posVacia].codigo == 0);

	printf("Ingrese nombre:\n");
	scanf("%s", &productos[posVacia].nombre);
	printf("Ingrese precio:\n");
	scanf("%f", &productos[posVacia].precio);
	productos[posVacia].stock= IngresarEntero("Ingrese stock:", 0, 9999999, "Ingrese un stock mayor o igual a 0");
}

int BuscarProductoPorCodigo(tProducto productos[], int valorABuscar) {
	for (int i = 0; i < MAXPROD; i++) {
		if (productos[i].codigo == valorABuscar) {
			return i;
		}
	}
	return -1;
}

int IngresarEntero(char mensaje[], int min, int max, char error[]) {
	int nro;

	do {
		printf("%s\n", mensaje);
		scanf("%d", &nro);

		if (nro < min || nro > max) {
			printf("%s\n", error);
			system("pause");
		}

	} while (nro < min || nro > max);

	return nro;
}

void ListarProductos(tProducto productos[]) {

	for (int f = 0; f < MAXPROD; f++) {
		if (productos[f].codigo == 0)
			continue;

		//imprimir
		printf("(%i) %s \t%d\t%.2f\n", productos[f].codigo, productos[f].nombre, productos[f].stock, productos[f].precio);
	}

	system("pause");

	/*
	for (int f = 0; f < MAXPROD; f++) {
		if (productos[f].codigo != 0)
		{
			//imprimir
		}
	}
	*/
}

void CargarDatos(tProducto productos[]) {

	FILE *file;
	file = fopen("stock.dat", "rb");
	if (file == NULL) {
		printf("Error al abrir el archivo\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < MAXPROD; i++) {
		fread(&productos[i], sizeof(tProducto), 1, file);
	}

	// rewind
	fseek(file, 0, SEEK_SET);
	fclose(file);
}

void GuardarDatos(tProducto productos[]) {

	FILE *file;
	file = fopen("stock.dat", "wb");
	if (file == NULL) {
		printf("Error al abrir el archivo\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < MAXPROD; i++) {
		fwrite(&productos[i], sizeof(tProducto), 1, file);
	}
	// rewind
	fseek(file, 0, SEEK_SET);
	fclose(file);
}

void EditarProducto(tProducto productos[]) {
	int codigo; 
	int pos;

	codigo = IngresarEntero("Ingrese codigo de producto a editar:", 1, 100, "Codigo no valido");
	pos = BuscarProductoPorCodigo(productos, codigo);
	if (pos == -1)
	{
		printf("Producto no encontrado\n");
		system("pause");
		return;
	}

	printf("(%i) %s \t%d\t%.2f\n", productos[pos].codigo, productos[pos].nombre, productos[pos].stock, productos[pos].precio);

	printf("Ingrese nombre:\n");
	scanf("%s", &productos[pos].nombre);
	printf("Ingrese precio:\n");
	scanf("%f", &productos[pos].precio);
	productos[pos].stock = IngresarEntero("Ingrese stock:", 0, 9999999, "Ingrese un stock mayor o igual a 0");

}

void ExportarTxt(tProducto productos[]) {
	FILE *archivo;
	archivo = fopen("stock.txt", "w");
	if (archivo == NULL) {
		printf("Error al abrir el archivo\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < MAXPROD; i++) {
		if (productos[i].codigo == 0)
			continue;

		fprintf(archivo, "(%i) %s \t%d\t%.2f\n", productos[i].codigo, productos[i].nombre, productos[i].stock, productos[i].precio);
	}
	fclose(archivo);
}