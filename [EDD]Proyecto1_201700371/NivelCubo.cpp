#include "NivelCubo.h"

using namespace std;

NivelCubo::NivelCubo()
{
	this->primero = NULL;
	this->ultimo = NULL;
}

NivelCubo::NivelCubo(CuboDispersoI* primero){
	this->primero = primero;
	this->ultimo = NULL;
}

NivelCubo::~NivelCubo()
{
}

void NivelCubo::insertar(int profundidad, CuboDispersoI *matriz){
	CuboDispersoI* nuevo = new CuboDispersoI(profundidad, matriz);
	//nuevo->locura(nuevo);
	if(this->primero == NULL){
	
		this->primero=this->ultimo=nuevo;
	
	}else{
	
		this->ultimo->siguiente = nuevo;
		nuevo->anterior = this->ultimo;
		this->ultimo = nuevo;
	
	}
}

void NivelCubo::imprimir(){
	if(primero == NULL){
		cout<<"Esta vacio esta mierda.";
	}else{
		bool validador = true;
		CuboDispersoI* temporal = this->primero;
		
		do{	
			cout<<temporal->getNivel()<<temporal->a<<endl;
			//temporal = temporal->subida;
			if(temporal == this->ultimo){
				validador = false;
				cout<<"sdf";
			}else{
			
				temporal = temporal->siguiente;
			}
		}while(validador);
	}
}


void NivelCubo::insertarOrdenado(int profundidad, CuboDispersoI *matriz){
	CuboDispersoI* nuevo = new CuboDispersoI(profundidad, matriz);
	CuboDispersoI* temporal = this->ultimo;
	//nuevo->locura(nuevo);
	if(temporal==NULL){
		//esta vacia entonces que inserte en la primer posicion
		this->primero = this->ultimo = nuevo;		
	}else{
		bool validador = true;
		/*
		Busca en que posicicion acomodar a los nodos que entran a la matriz
		*/
		do{
			if(temporal->getNivel() > nuevo->getNivel()){
				validador = false;
				break;
			}else if(temporal->anterior != NULL){
				temporal = temporal->anterior;
			}else{
				break;
			}
		}while(true);
		
		if(validador == true){
			nuevo->anterior = temporal;
			temporal->siguiente->anterior = nuevo;
			nuevo->siguiente = temporal->siguiente;
			temporal = nuevo->anterior;
		}else{
			cout<<"aca deberia de entrara"<<nuevo->getNivel();
			temporal->anterior = nuevo;
			nuevo->siguiente = temporal;
		}
		
	}
}

void NivelCubo::imprimirNivel(){
	if(primero == NULL){
		cout<<"Esta vacio esta mierda.";
	}else{
		bool validador = true;
		CuboDispersoI* temporal = this->primero;
		
		do{	
		//	cout<<temporal->getNivel()<<temporal->a<<endl;
			cout<<"Cosi\n";
			//temporal->imprimir();
			cout<<endl;
			//temporal = temporal->subida;
			if(temporal == this->ultimo){
				validador = false;
				cout<<"sdf";
			}else{
			
				temporal = temporal->siguiente;
			}
		}while(validador);
	}
	
}
