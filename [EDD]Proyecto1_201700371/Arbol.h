#ifndef ARBOL_H
#define ARBOL_H
#include "NodoArbol.h"
using namespace std;

class NodoArbol;
class Arbol
{
	private:
		NodoArbol* raiz;
	
	public:
		NodoArbol* buscar(string);
		//NodoArbol* buscar(NodoArbol*, string);
		NodoArbol* buscarID(int);
		
		
		void insertar(int, string, NivelCubo*, NodoArbol *&);
		
		void mostrarImagenes(int, NodoArbol*&);
		void mostrarImagenesSeleccion(int, NodoArbol*&);
		
		void mostrar(int, NodoArbol*&);
		
		void buscarImagenSeleccion(string, NodoArbol *&);
		
		Arbol();
		Arbol(NodoArbol*);
		~Arbol();
	protected:
};

#endif
