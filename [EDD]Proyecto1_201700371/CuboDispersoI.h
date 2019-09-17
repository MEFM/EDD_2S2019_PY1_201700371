#ifndef CUBODISPERSOI_H
#define CUBODISPERSOI_H
#include "NodoDisperso.h"

using namespace std;

class CuboDispersoI
{
	private:
	NodoDisperso* raiz;	
	NodoDisperso* raizCub;
	int nivel;	
	
	
	public:
		CuboDispersoI* siguiente;
		CuboDispersoI* anterior;
		CuboDispersoI* a;
		
		NodoDisperso* buscarFila(int);
		NodoDisperso* buscarColumna(int);
		NodoDisperso* buscarNivel(int);
		NodoDisperso* insertarColumna(NodoDisperso* , NodoDisperso*);
		NodoDisperso* insertarFila(NodoDisperso*, NodoDisperso*);
		NodoDisperso* crearC(int);
		NodoDisperso* crearF(int);
		
		void nuevoNivel();
		void imprimir();
		void graficar();
		void insertar(string, int, int);
		
		void setNivel(int);
		int getNivel();
		
		void locura(CuboDispersoI*);
		
		CuboDispersoI();
		CuboDispersoI(int, CuboDispersoI*);
		~CuboDispersoI();
	protected:
};

#endif
