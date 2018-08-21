#pragma warning (disable: 4996)
#include<stdlib.h>
#include<stdio.h>

#define HORAS 2
#define DIAS 2

void CargarTemperaturas(int temp[][HORAS]);
float CalcularMedia(int temp[][HORAS]);

int main(void)
{
	int temperaturas[DIAS][HORAS];
	float media = 0;

	CargarTemperaturas(temperaturas);
	media = CalcularMedia(temperaturas);

	printf("\n\nEl promedio es: %.2f\n", media);

	system("pause");
	return 0;
}

void CargarTemperaturas(int temp[][HORAS])
{
	for (int dia = 0; dia < DIAS; dia++)
	{
		for (int hora = 0; hora < HORAS; hora++)
		{
			printf("\nIngrese la temp del dia %d de la hora %d :\n", dia, hora);
			scanf("%d", &temp[dia][hora]);
		}
	}
}

float CalcularMedia(int temp[][HORAS]) {
	float media = 0;
	for (int dia = 0; dia < DIAS; dia++)
	{
		for (int hora = 0; hora < HORAS; hora++)
		{
			// printf("%d => %d\n", hora, temperaturas[hora]);
			media = media + temp[dia][hora];
		}
	}
	return (float)media / (HORAS * DIAS);
}
