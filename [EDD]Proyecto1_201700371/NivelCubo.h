#ifndef NIVELCUBO_H
#define NIVELCUBO_H
#include "CuboDispersoI.h"


class NivelCubo
{	
	private:
		CuboDispersoI* primero;
		CuboDispersoI* ultimo;	
		
		
		CuboDispersoI* dato;
		NivelCubo* izquierdo;
		NivelCubo* derecho;
	public:
		
		void insertarOrdenado(int, CuboDispersoI *);
		void recorrer();
		void imprimirNivel();
		void insertar(int, CuboDispersoI *);
		void imprimir();
		NivelCubo();
		NivelCubo(CuboDispersoI*);
		
		
		
		~NivelCubo();
	protected:
};

#endif
