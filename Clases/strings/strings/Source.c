#pragma warning (disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "custom.c"

int main() {
	
	char cadena[5] = { 'h', 'o','l','a','\0' };
	char cadena2[] = "hola mmundo";
	char cadena3[] = "hola mmundo";
	char cadena4[] = "          ";
	char cadena5[50] = "hola ";
	char cadena6[] = "mundo";
	string cadena7 = "hjgghjkhgjkhghjkhg";

	size_t tamanio;

	printf("%s\n", cadena);

	printf("%s\n", cadena2);

	printf("%c\n", cadena2[5]);

	 if (strcmp(cadena2, cadena3) == 0) // if (cadena3[2] == cadena2[2])
	{
		printf("iguales\n");
	}
	else {
		printf("dif\n");
	}
	
	// NO: cadena4 = "hola";
	strcpy(cadena4, "hola1");

	// scanf("%s", &cadena4);

	printf("%s\n", cadena4);

	tamanio = strlen(cadena4);

	printf("Tamanio: %d\n", tamanio);

	strcat(cadena5, cadena6);

	printf("%s\n", cadena5);
	printf("%s\n", cadena6);

	printf("%s\n", strchr(cadena2, 'm'));

	system("pause");
	return 0;
}
