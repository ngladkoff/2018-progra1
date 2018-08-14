#pragma warning (disable:4996)
#include <stdlib.h>
#include <stdio.h>

// definir prototipos funciones
int Multiplicar(int numero1, int numero2);
int Potencia(int nro1, int nro2);
void ImprimirSaludo();

int main() {
	int resultado = 0;
	int n1, n2;
	     
	n1 = 3;
	n2 = 2;

	resultado = Potencia(n1, n2);

	printf("%d", n1);

	ImprimirSaludo();
    printf("%d\n", resultado);
	system("pause");
	return 0;
}

int Multiplicar(int numero1, int numero2) {
	
	int suma = 0;

	for (int i = 1; i <= numero2; i++)
	{
		suma += numero1; // suma = suma + numero1
	}

	return suma;
}

int Potencia(int n1, int nro2) {
	int pow = 1;

	if (nro2 == 0) {
		return 1;
	}

	for (int i = 1; i <= nro2; i++)
	{
		pow = Multiplicar(n1, pow); 
	}

	return pow;
}

void ImprimirSaludo() {
	printf("Hola\n");
	return;
}