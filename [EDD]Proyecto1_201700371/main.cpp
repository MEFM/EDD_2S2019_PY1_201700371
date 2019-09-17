#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <sstream> 
#include <cstring>
#include <cstdlib>
//#include "CuboDispersoI.h"
#include "Arbol.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
//using namespace ios;
NodoArbol* raiz;
NodoDisperso* rai;

void archivos(int, string);
void conta(string);
void pruebadeMIerda(string);
void seleccion_imagen();
void edicionManul();
void exportarImagen();
void reportes();

int filas = 0;
int noArchivo = 0;
Arbol arbolin;

NivelCubo *nivel;
CuboDispersoI *lista;
string nombre_imagen = "";

void atolon(){
	//nivel.~NivelCubo();
	noArchivo = 0;
	nivel = new NivelCubo();
	system("cls");
	
	string path = "";
	
	cout<<"Inserte el nombre de la imagen a trabajar."<<endl;
	cin>>nombre_imagen;
	cout<<"Inserte el nombre del archivo CSV."<<endl;
	cin>>path;
	const char *name = path.c_str();
	
	ifstream file(name);
	//file.open("s.csv",ios::in);
	string linea = "j";	
	string archivo = "";
	char a = ',';
	char b = '\n';
	
	while(file.good()){
		getline(file, linea, a);
	
		int contador = 0;
		int numero_archivo=0;
		
		
		const char *temporal = linea.c_str();
		numero_archivo = atoi(temporal);
		cout<<linea<<" este es el numero del archivo";
	
		string lineab = "";	
		string ubicacion = "";
		getline(file, lineab, b);
		//cout<<lineab;
		ubicacion = lineab;
		
		
		
		archivos(numero_archivo, ubicacion);	
		
	}
	

	//archivos("Parte1.csv");
	file.close();
	
	cout<<"\n0 to menu.\n";
	cin>>path;

}

void archivos(int id, string archivo){
	if(archivo.find(".csv") != string::npos){
		noArchivo = id;
		cout<<id<<" este es el numero que paso al metodo archivos.";
	
		const char *name = archivo.c_str();
		ifstream file(name);
		string linea = "";
		char a = '\n';
		while(file.good()){
			filas = filas + 1;
			getline(file, linea, a);
			conta(linea);
		}
		filas = 0;
		
		file.close();	
	
		nivel->insertar(noArchivo, lista);
	}
}

void conta(string a){
	char cstr[a.size() + 1];
	a.copy(cstr, a.size() + 1);
	char delim[] = ",";
	char *tokem = strtok(cstr, delim);
	int columnas = 0;
	
	if(tokem != NULL){
		//CuboDispersoI lista;
		lista = new CuboDispersoI();
		while(tokem != NULL){
			columnas = columnas + 1;
			//printf("Token: %s\n", tokem);
			string jj = tokem;
			
			if(jj.find("x") != string::npos){
				
			}else{
				cout<<"Token: "<<tokem<<" numero de fila y columna "<<filas<<columnas;
				cout<<"Numero de archivo: "<<noArchivo<<endl;
				lista->insertar(tokem, columnas, filas);
				
			}			
			
			tokem = strtok(NULL ,delim);			
		}
		//lista->imprimir();
		
	}
	
		
	cout<<endl;
	
}



int main() {
	int contador = 0;
	int opcion = 0;
	bool validador = true;
	
	do
	{
		cout<<"---------------Menú Principal-----------------\n";
		cout<<"[1.] Insertar Imagen.\n";
		cout<<"[2.] Seleccionar Imagenes.\n";
		cout<<"[3.] Aplicar Filtros.\n";
		cout<<"[4.] Edición Manual.\n";
		cout<<"[5.] Exportar Imagen.\n";
		cout<<"[6.] Menú Reportes.\n";
		cin>>opcion;
		
		switch(opcion){
			case 1:	
				
			//lista->insertar("ola", 15, 15);
			//lista = new CuboDispersoI();
			
			atolon();
			//arbolin.insertar(ini,1,"sdf",nivel);
			
			arbolin.insertar(nombre_imagen.length(), nombre_imagen, nivel, raiz);	
			cout<<"Aca biene la impresion perro\n"<<raiz->nombre;
			//arbolin.mostrarImagenes(contador, raiz);	
		//	arbolin.mostrarImagenes(contador, raiz);
			break;
			case 2:
				seleccion_imagen();				
				break;
			case 3:
				cout<<raiz->nombre<<" imagen seleccionada para aplicar filtros.\n";				
				break;
			case 4:
				edicionManul();
				break;
			case 5:
				break;
			case 6:
				break;
		
			
			default: validador = false; break;
		}
	system("cls");
	nivel->imprimir();
//	nivel->imprimirNivel();
			
	}while(validador);
	

	
	
	return 0;
}

void seleccion_imagen(){
	int contador = 0;
	arbolin.mostrarImagenesSeleccion(contador, raiz);
//	system("pause");
}

void edicionManul(){
	int opcion = 0;
	cout<<"-----------------------Edicion manual-------------------------\n";
	cout<<"[1.] Edicion por pixeles.\n";
	cout<<"[2.] Filtros.\n";
	cout<<"Escriba el numero de opcion al que desee ingresar.\n";
	cin>>opcion;
	
	switch(opcion){
		case 1:
			//Llamar a la matriz de un solo vergazo
			break;
		case 2:
			//Jala una lista circular de filtros
			break;
	}
	
	/*Weno en esta parte tengo que ver que putas tengo que hacer realmente
	en este lugar se debe realizar la toma de nodo por nodo de cada matriz del cubo
	probar el recorrido de las matrices para hacer la imagen.*/
}

void exportarImagen(){
	/*En este metodo se debe pintar la imagen en el HTML con CSS.*/
	
}

void reportes(){
		int opcion = 0;
		bool validador = true;
		
		do{
			cout<<"---------------Menú Reportes-----------------\n";
			cout<<"[1.] Reportes de imagenes importadas.\n";
			cout<<"[2.] Reportes de reporte de capas.\n";
			//De esta imagen se debe hacer otra busqueda en el arbol para jalar lo que se necesita
			//Devolver un nodo para su implementacion
			cout<<"[3.] Reportes de capa linealizada.\n";
			//Se debe elejir entre capara para poder linealizar una matriz
			cout<<"[4.] Reporte traspuesto.\n";
			//Los tres recorridos posibles para el arbol
			cout<<"[5.] Reportes de filtros.\n";
			cout<<"[6.] Regresar a Menu.\n";
			//Lista doble enlazada
			cout<<"Elija una opcion.\n";
			cin>>opcion;
		
			switch(opcion){
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
			}	
		}while(validador);
}


