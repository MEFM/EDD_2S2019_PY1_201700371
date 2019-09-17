#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "NivelCubo.h"
class Arbol;
#include "Arbol.h"

using namespace std;
//typedef Arbol ArbolB;


class NodoArbol
{
	
	
	private:
	
		
		
	
	public:			
		
		NodoArbol* izquierdo;
		NodoArbol* derecho;
		
		int id;
		string nombre;
		NivelCubo* dato;
		
		NodoArbol();
		NodoArbol(int, string, NivelCubo*);		
		NodoArbol(int, string, NivelCubo*, Arbol*, Arbol*);		
		~NodoArbol();
		
};

#endif
