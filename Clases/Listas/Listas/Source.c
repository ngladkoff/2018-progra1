#include <stdlib.h>
#include <stdio.h>

struct nodoLista {
	int dato;
	struct nodoLista *ptrSiguiente;
};

typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;

void Agregar(ptrNodoLista *ptrS, int valor);
void Imprimir(ptrNodoLista *ptrS);

int main() {
	ptrNodoLista ptrInicial = NULL;

	// Agregar
	Agregar(&ptrInicial, 10);

	Agregar(&ptrInicial, 20);

	Agregar(&ptrInicial, 30);

	Imprimir(&ptrInicial);

	system("pause");
	return 0;
}

void Agregar(ptrNodoLista *ptrS, int valor) {

	ptrNodoLista ptrNuevo;
	ptrNodoLista ptrActual = NULL;
	ptrNodoLista ptrAnterior = NULL;

	ptrNuevo = malloc(sizeof(NodoLista));
	ptrNuevo->dato = valor;
	ptrNuevo->ptrSiguiente = NULL;

	//Pila
	//if (*ptrS != NULL)
	//	ptrNuevo->ptrSiguiente = *ptrS;
	//*ptrS = ptrNuevo;

	// Cola
	ptrActual = *ptrS;
	ptrAnterior= *ptrS;
	while (ptrActual != NULL) {
		ptrAnterior = ptrActual;
		ptrActual = ptrActual->ptrSiguiente;
	}
	if (ptrAnterior == NULL) {
		*ptrS = ptrNuevo;
		return;
	}
	ptrAnterior->ptrSiguiente = ptrNuevo;
}

void Imprimir(ptrNodoLista *ptrS) {

	ptrNodoLista ptrActual = NULL;

	ptrActual = *ptrS;

	while (ptrActual != NULL) {
		printf("%i\n", ptrActual->dato);
		ptrActual = ptrActual->ptrSiguiente;
	}
}