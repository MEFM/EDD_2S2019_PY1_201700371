#include "Arbol.h"
#include <stdlib.h>

Arbol::Arbol()
{
	this->raiz = NULL;
}

Arbol::~Arbol()
{
}


void Arbol::insertar(int id, string nombre, NivelCubo* cubo, NodoArbol *&arbol){
	
	if(arbol == NULL){
		NodoArbol* nuevo = new NodoArbol(id, nombre, cubo);
		arbol = nuevo;
	}else{
		int idNu = arbol->id;
		if(id <= idNu){
			insertar(id, nombre, cubo, arbol->izquierdo);
		}else{
			insertar(id, nombre, cubo, arbol->derecho);
		}
	}
}


void Arbol::mostrarImagenes(int contador, NodoArbol *&arbol){
	//cout<<arbol->nombre<<" este es el supesto nombre\n";
	if(arbol == NULL){
	//	cout<<arbol->nombre<<endl<<" si aca esta pendejo.";
		return;
	}
	else{
		
		mostrarImagenes(contador++, arbol->derecho);
		cout<<contador<<". "<<arbol->nombre<<endl;
		mostrarImagenes(contador++, arbol->izquierdo);
	}
	
}

void Arbol::mostrarImagenesSeleccion(int contador, NodoArbol *&arbol){
	string imagenSeleccion = "";
	this->mostrarImagenes(contador, arbol);
	cout<<"Escriba el nombre de la imagen que desea seleccionar.\n";
	cin>>imagenSeleccion;
	
	this->buscarImagenSeleccion(imagenSeleccion, arbol);
}

void Arbol::buscarImagenSeleccion(string imagenSeleccion, NodoArbol *&arbol){
	if(arbol == NULL){
		cout<<"Hermano esa imagen no existe.\n";
		
	}
	else{
	
		int tamanio = imagenSeleccion.length();
		
		int idNodo = arbol->id;
		
		if(idNodo == tamanio && arbol->nombre == imagenSeleccion){
			cout<<arbol->nombre<<" encontrada esa mierda despeus de anios\n";
			system("pause");
		}
		else if(tamanio <= idNodo){
			if(arbol == NULL){
				return;
			}else{
				buscarImagenSeleccion(imagenSeleccion, arbol->izquierdo);	
			}
		}
		else{
			if(arbol == NULL){
				
			}else{
				buscarImagenSeleccion(imagenSeleccion, arbol->derecho);
			}
		}
		
		
	}
}

