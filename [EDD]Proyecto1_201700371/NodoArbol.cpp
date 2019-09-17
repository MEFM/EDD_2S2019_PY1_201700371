#include "NodoArbol.h"

NodoArbol::NodoArbol()
{
}

NodoArbol::NodoArbol(int id, string nombre, NivelCubo* cubo){
	this->id = id;
	this->nombre = nombre;
	this->dato = cubo;
	
	this->izquierdo = NULL;
	this->derecho = NULL;

}



