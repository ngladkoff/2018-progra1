#pragma warning (disable:4996)
#include<stdlib.h>
#include<stdio.h>

void Incrementar(int *ptrNro, int nro2);
void ModificarVector(int v[]);
void ModificarVectorPtr(int *v);
void ImprimirStr(char *);

int ContarPalabras(char *);

int EsSeparador(char c);

int main(void) {
	int numero = 0;
	int numero2 = 0;
	int vector[5] = { 1,2,3,4,5 };
	char nombre[20] = "Nicolas";
	int cantPalabras = 0;
	char texto[200] = "Nicolas kjhkj kjhkjh kjhkjh kjhnkjhk kjhkjh kjhk";

	Incrementar(&numero, numero2);

	Incrementar(&numero, numero2);

	printf("%d\n", numero);
	printf("%d\n", numero2);

	ModificarVector(vector);

	printf("%d\n", vector[0]);

	ModificarVectorPtr(vector);

	for (int i= 0; i < 5; i++) {
		printf("%d\n", vector[i]);
	}

	ImprimirStr(nombre);

	cantPalabras = ContarPalabras(texto);

	printf("%d\n", cantPalabras);

	system("pause");
	return EXIT_SUCCESS;
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
