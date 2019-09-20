#include "CuboDispersoI.h"



CuboDispersoI::CuboDispersoI()
{
 raiz = new NodoDisperso("Raiz", -1, -1);
}

void CuboDispersoI::nuevoNivel(){
	raiz = new NodoDisperso("Raiz", 0, 0);
}

CuboDispersoI::~CuboDispersoI()
{
}

CuboDispersoI::CuboDispersoI(int archivo, CuboDispersoI *l){
	this->nivel = archivo;
	this->a = l;
	
}

void CuboDispersoI::locura(CuboDispersoI *l){
	a = l;
}

NodoDisperso* CuboDispersoI::buscarFila(int fila){
	NodoDisperso* temporal = this->raiz;
	
	while(temporal != NULL){
			if(temporal->getY() == fila){
				return temporal;
			}
			temporal = temporal->abajo;
			
	}
	return NULL;
}


NodoDisperso* CuboDispersoI::buscarColumna(int columna){
	NodoDisperso* temporal = this->raiz;
	
	while(temporal != NULL){
		if(temporal -> getX() == columna){
			return temporal;
		}
		temporal = temporal -> siguiente;
	}
	return NULL;
}


//Solo es una idea todavia no se debe implementar
NodoDisperso* CuboDispersoI::buscarNivel(int nivel){
	NodoDisperso* temporal = this->raiz;
	
	while(temporal != NULL)
	{
		if(temporal->getZ() == nivel){
			return temporal;
		}
	}
	return NULL;
}

NodoDisperso* CuboDispersoI::insertarColumna(NodoDisperso* nuevo, NodoDisperso* cabeceraColumna){
	NodoDisperso* temporal = cabeceraColumna;
	bool validador = true;
	
	while (true){
		if(temporal->getX() == nuevo->getX()){
			//Si se agrega la primera columna despues de la raíz
			
			temporal->setY(nuevo->getY());
			temporal->setRGB(nuevo->getRGB());
			return temporal;
		}
		else if(temporal->getX() > nuevo->getX()){
			//se tiene que insertar antes del temporal
			validador = true;
			break;
		}
		else if(temporal->siguiente != NULL){
			temporal = temporal->siguiente;
		}
		else{
			validador = false;
			//Se inserta el nuevo despues de temporal
			break;
		}
	}
	
	if(validador){
		//Se inserta antes a temporal
		nuevo->siguiente = temporal;
		temporal->anterior->siguiente = nuevo;
		nuevo->anterior=temporal->anterior;
		temporal = nuevo;
	}else{
		temporal->siguiente = nuevo;
		nuevo->anterior = nuevo;
	}
	return nuevo;
}

NodoDisperso* CuboDispersoI::insertarFila(NodoDisperso* nuevo, NodoDisperso* cabeceraFila){
	NodoDisperso* temporal = cabeceraFila;
	bool validador = false;
	
	while (true){
		if(temporal->getY() == nuevo->getY()){
			//Si se agrega la primera columna despues de la raíz
			
			temporal->setRGB(nuevo->getRGB());
			temporal->setX(nuevo->getX());
			
			return temporal;
		}
		else if(temporal->getY() > nuevo->getY()){
			//se tiene que insertar antes del temporal
			validador = false;
			break;
		}
		else if(temporal->abajo != NULL){
			temporal = temporal->abajo;
		}
		else{
			validador = false;
			//Se inserta el nuevo despues de temporal
			break;
		}
	}
	
	if(validador == true){
		//Se inserta antes a temporal
		nuevo->abajo = temporal;
		temporal->arriba->abajo = nuevo;
		nuevo->arriba=temporal->arriba;
		temporal = nuevo;
	}else{
		temporal->abajo = nuevo;
		nuevo->arriba = nuevo;
	}
	return nuevo;
}

NodoDisperso* CuboDispersoI::crearC(int columna){
	NodoDisperso* cabecera = this->raiz;
	NodoDisperso* column = insertarColumna(new NodoDisperso("C", columna, 0), cabecera);
	return column;
	
}

NodoDisperso* CuboDispersoI::crearF(int fila){
	NodoDisperso* cabecera = this->raiz;
	NodoDisperso* fil = insertarFila(new NodoDisperso("F", 0, fila), cabecera);
	return fil; 
}


void CuboDispersoI::insertar(string color, int columna, int fila){
	
	/*Nodos de creacion*/
	NodoDisperso* nuevo = new NodoDisperso(color, columna, fila);	
	NodoDisperso* nodoColumna = this->raiz;
	NodoDisperso* nodoFila = this ->raiz;
	/*----------------------------------------------------------*/
	
	/*Condicionales de creacion e incersion*/
	if(nodoColumna == NULL && nodoFila == NULL){
		//Crear columna y Crear Fila
		nodoColumna = crearC(columna);
		nodoFila = crearF(fila);
		
		nuevo = insertarColumna(nuevo, nodoFila);
		
		nuevo = insertarFila(nuevo, nodoColumna);
		return;
		
	}else if(nodoColumna != NULL && nodoFila == NULL){
		//Crear Fila
		nodoFila = crearF(fila);
		
		nuevo = insertarColumna(nuevo, nodoFila);
		nuevo = insertarFila(nuevo, nodoColumna);
		
		return;
		
	}else if(nodoColumna == NULL && nodoFila != NULL){
		//Crear columna
		nodoColumna = crearC(columna);
		
		nuevo = insertarColumna(nuevo, nodoFila);
		nuevo = insertarFila(nuevo, nodoColumna);
		
		return;		
		
	}else if(nodoColumna != NULL && nodoFila != NULL){
		//Insertar en su lugar correspondiente
		
		nuevo = insertarColumna(nuevo, nodoFila);
		nuevo = insertarFila(nuevo, nodoColumna);
	}
	
}

void CuboDispersoI::setNivel(int nivel){
	this->nivel=nivel;
}

int CuboDispersoI::getNivel(){
	return this->nivel;
}


void CuboDispersoI::imprimir(){
//	rai = this->raiz;
cout<<"Hola";
	if(this->raiz == NULL){
		cout<<"No hay nada en este nivel."<<endl;
	}
	else{
	//	cout<<"que sad :("<< raiz->getRGB()<<"\n";
		NodoDisperso* temporal = this->raiz;	
		NodoDisperso* temporal2;
	//	NodoDisperso* auxiliar2 = this->raiz;
		
		
		while(temporal != NULL){
			temporal2 = temporal;
			while(temporal2 != NULL){
				cout<<temporal->getRGB()<<temporal->getY()<<endl;
				temporal2 = temporal2->siguiente;
				
			}
				temporal = temporal->abajo;
				
			
		}
		
		/*do{
			
			cout<<"Si entro aqui\n";
			cout<<temporal->getRGB()<<"Ese es el color Fila y Columna: "<<temporal->getX()<<" "<<temporal->getY()<<endl;
			if(temporal->siguiente == NULL){
			
				temporal = temporal->abajo;
			}else{
				//cout<<temporal->getRGB()<<" "<<temporal->getX()<<" "<<temporal->getY()<<endl;
				temporal = temporal->siguiente;
			}			
				//cout<<temporal->getRGB()<<" "<<temporal->getX()<<" "<<temporal->getY()<<endl;
		
		}while(temporal != NULL);*/
	}
}


