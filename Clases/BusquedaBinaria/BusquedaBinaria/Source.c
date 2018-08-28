#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>

#define TAMANIO 10

int BusquedaBinaria(int b[], int claveBusqueda, int tamanio);

int main() {

	int v[TAMANIO] = { 2, 3, 5, 7, 8, 10, 15, 28, 67, 100 };
	int v2[5];
	int valorBuscar;
	int posicion = -1;
	int posicion2 = -1;

	for (int i = 0; i < 5; i++)
	{
		v2[i]= rand() % 100 + 1
	}

	printf("valor a buscar: ");
	scanf("%d", &valorBuscar);

	posicion = BusquedaBinaria(v, valorBuscar, TAMANIO);
	posicion2 = BusquedaBinaria(v2, valorBuscar, 3);

	printf("Resultado: %d\n", posicion);

	system("pause");

}

int BusquedaBinaria(int b[], int claveBusqueda, int tamanio) {
	int bajo= 0;
	int alto;
	int centro;
	alto = tamanio - 1;
	
	while (bajo <= alto)
	{
		centro = (bajo + alto) / 2;
		if (b[centro] == claveBusqueda) {
			return centro;
		}
		else if (claveBusqueda < b[centro]) {
			alto = centro - 1;
		}
		else {
			bajo = centro + 1;
		}
	}
	return -1;
}
