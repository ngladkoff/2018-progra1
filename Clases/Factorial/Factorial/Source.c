#include <stdio.h>
#include <stdlib.h>

int Factorial(int numero);
int Fibonacci(int numero);

int main(void) {

	int numero = 5;
	int respuesta = 0;

	respuesta = Factorial(numero);

	printf("Factorial de %d: %d\n", numero, respuesta);


	for (int i = 0; i <= 10; i++) {
		printf("%d\t", Fibonacci(i));
	}
	printf("\n");

	system("pause");
	return 0;
}

int Factorial(int numero) {

	if (numero <= 1)
		return 1;

	return numero * Factorial(numero - 1);
}

int Fibonacci(int numero) {

	if (numero <= 1)
		return 1;

	return Fibonacci(numero - 1) + Fibonacci(numero - 2);

	return 1;
}
