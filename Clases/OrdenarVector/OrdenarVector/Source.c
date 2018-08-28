#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int vector[6] = { 9, 5, 3, 2, 7, 8 };
	int i, j;
	int tamanioVector = 6;
	int aux;

	for (j = 1; j <= tamanioVector - 1; j++)
	{
		printf("Numero de vuelta: %d\n", j);

		for (i = 0; i < tamanioVector - 1; i++)
		{
			if (vector[i] > vector[i + 1])
			{
				aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
			}
		}
	}

	for (i = 0; i < tamanioVector; i++)
	{
		printf("%d\n", vector[i]);
	}

	system("pause");
	return 0;
}