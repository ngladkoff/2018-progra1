#pragma warning (disable:4996)
#include<stdlib.h>
#include<stdio.h>

int PedirNumeroValido(char mensaje[], int min, int max, char mensajeError[]);
int PedirNumero(char mensaje[]);

void ImprimirMatriz(int matriz[][4], int largo);

void IncrementarUnoMatriz(int matriz[][4], int largo);

void Incrementar(int *ptrNro, int nro2);
void ModificarVector(int v[]);
void ModificarVectorPtr(int *v);
void ImprimirStr(char *);
int ContarPalabras(char *);
int EsSeparador(char c);

int main(void) {

	int cantidadProductos[5][4] = { {10,5,3,7}, {5,8,3,1}, {6,7,8,9}, {2,7,4,6}, {0,0,0,0} };

	int numero = 0;
	int numero2 = 0;
	int vector[5] = { 1,2,3,4,5 };
	char nombre[20] = "Nicolas";
	int cantPalabras = 0;
	char texto[200] = "Nicolas kjhkj kjhkjh kjhkjh kjhnkjhk kjhkjh kjhk";
	int fila = 0;
	int col = 0;

	// Pedir Fila y Columna
	fila = PedirNumeroValido("Igrese Fila (1-5): ", 1, 5, "El numero ingresado no es valido") - 1;
	col = PedirNumeroValido("Ingrese Columna (1-4): ", 1, 4, "Ingrese un numero entre 1 y 4") - 1;

	printf("Cantidad Producto: %d\n", cantidadProductos[fila][col]);

	printf("Antes: \n");
	ImprimirMatriz(cantidadProductos, 5);

	cantidadProductos[fila][col] = cantidadProductos[fila][col] - 1;

	printf("Despues: \n");
	ImprimirMatriz(cantidadProductos, 5);

	printf("Matriz Incrementada \n");
	IncrementarUnoMatriz(cantidadProductos, 5);
	ImprimirMatriz(cantidadProductos, 5); 

	system("pause");
	exit(0);

	Incrementar(&numero, numero2);

	Incrementar(&numero, numero2);

	printf("%d\n", numero);
	printf("%d\n", numero2);

	ModificarVector(vector);

	printf("%d\n", vector[0]);

	ModificarVectorPtr(vector);

	for (int i = 0; i < 5; i++) {
		printf("%d\n", vector[i]);
	}

	ImprimirStr(nombre);

	cantPalabras = ContarPalabras(texto);

	printf("%d\n", cantPalabras);

	system("pause");
	return EXIT_SUCCESS;
}

void IncrementarUnoMatriz(int matriz[][4], int largo)
{
	for (int f = 0; f < largo; f++) {
		for (int c = 0; c < 4; c++) {
			matriz[f][c] = matriz[f][c] + 1;
		}
	}
}


void ImprimirMatriz(int matriz[][4], int largo) {
	for (int f = 0; f < largo; f++) {
		for (int c = 0; c < 4; c++) {
			printf("%d\t", matriz[f][c]);
		}
		printf("\n");
	}
}

int PedirNumero(char mensaje[]) {
	int numero = 0;
	printf(mensaje);
	scanf("%d", &numero);
	return numero;
}

int PedirNumeroValido(char mensaje[], int min, int max, char mensajeError[]) {

	int nro = 0;

	do {
		nro = PedirNumero(mensaje);

		if (nro <min || nro > max) {
			printf(mensajeError);
			printf("\n");
		}

	} while (nro < min || nro > max);

	return nro;
}

void ModificarVector(int v[]) {
	v[1] = 0;
}

void ModificarVectorPtr(int *v)
{
	v++;
	*v = 99;
	v++;
	*v = 77;
}

void Incrementar(int *ptrNro, int nro2) {
	*ptrNro = *ptrNro + 1;
	nro2 = nro2 + 1;
}

void ImprimirStr(char *str) {

	int i = 0;

	while (*str != '\0') {
		printf("%c", *str);
		str++;
	}

	printf("\n");
}

int ContarPalabras(char *texto) {

	int enPalabra = 0;
	int cantPalabras = 0;

	while (*texto != '\0') {

		if (enPalabra == 0)
		{
			if (EsSeparador(*texto) == 0)
			{
				enPalabra = 1;
				cantPalabras++;
			}
		}
		else {
			if (EsSeparador(*texto) == 1)
			{
				enPalabra = 0;
			}
		}
		texto++;
	}
	return cantPalabras;
}


































int EsSeparador(char c) {
	char separadores[] = " ,.-+*/#&=;:_\"\'?!()[]{}\n";

	if (strchr(separadores, c))
		return 1;

	return 0;
}
