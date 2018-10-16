#include <stdlib.h>
#include <stdio.h>

struct nodoLista {
	int dato;
	struct nodoLista *ptrSiguiente;
};

typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;

void Agregar(ptrNodoLista *ptrS, int valor);

int main() {
	ptrNodoLista ptrInicial = NULL;

	// Agregar



	return 0;
}

void Agregar(ptrNodoLista *ptrS, int valor) {

	ptrNodoLista ptrNuevo;

	ptrNuevo = malloc(sizeof(NodoLista));

	ptrNuevo->dato = valor;




}