#pragma warning (disable: 4996)
#include<stdlib.h>
#include<stdio.h>

void OrdenarVector(int v[], int tamanio);

int main(void) {
	int i= 0;
	int vector1[5] = { 9, 5, 3, 6, 1 };
	int vector2[3] = { 4, 9, 3 };

	for (i = 0; i < 5; i++)
	{
		printf("%d\n", vector1[i]);
	}
	system("pause");

	OrdenarVector(vector1, 5);
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", vector1[i]);
	}
	system("pause");

	for (i = 0; i < 3; i++)
	{
		printf("%d\n", vector2[i]);
	}
	system("pause");

	OrdenarVector(vector2, 3);
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", vector2[i]);
	}

	system("pause");
}


void OrdenarVector(int v[], int tamanio)
{
	int i, j;
	int aux;

	for (i = 0; i < tamanio - 1; i++)
	{
		for (j = 0; j < tamanio - 1; j++) {
			if (v[j] > v[j + 1])
			{
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}
}