#pragma warning (disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ProductoMasEconomico(int precios[]);
int ContieneVocales(char vector[]);
int EsVocal(char c);

int main(void) {

	char productos[5] = { 'A','B','C','D','E' };
	int precios[5] = { 350, 200, 170, 190, 80 };
	char string[] = "qwrtyplkjhgfdszxcvbmn";

	printf("El producto mas económico es: %c\n", productos[ProductoMasEconomico(precios)]);

	if (ContieneVocales(string) == 1) {
		printf("contiene vocales\n");
	}
	else {
		printf("no contiene vocales\n");
	}

	system("pause");
}

int ProductoMasEconomico(int precios[]) {

	int posMenorPrecio = 0;
	
	for (int i=1; i < 5; i++) {
		if (precios[i] < precios[posMenorPrecio]) {
			posMenorPrecio = i;
		}
	}

	return posMenorPrecio;
}

int ContieneVocales(char vector[]) {

	int i = 0;

	while (vector[i] != '\0') {

		if (EsVocal(vector[i]) == 1) {
			return 1;
		}

		i++;
	}

	return 0;

}

int EsVocal(char c)
{
	char v[] = "aeiouAEIOUaáéíóú";
	int i = 0;

	while (v[i] != '\0') {
		
		if (c == v[i])
			return 1;

		i++;
	}
	return 0;
}

int EsVocal2(char c)
{
	char v[] = "aeiouAEIOUaáéíóú";

	if (strchr(v, c))
		return 1;
	else
		return 0;
}
