#ifndef IMPORTIMAGE_H
#define IMPORTIMAGE_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include "CuboDispersoI.h"

using namespace std;
class ImportImage
{
	private:
		int contador;	
		string colorear, div;	
	
	public:
		//Para crearCarpeta unicmante se envia el nombre de la carpeta
		void crearCarpeta(string);		
		//Para crearHtml se envia el nombre del archivo y los pixeles que entraran(cantidad)
		//se almacena dentro de crearCarpeta
		void crearHtml(string, int);
		/*
		Para crearCss se envia:
		-Nombre de archivo
		-Ancho de la imagen
		-Altura de la imagen
		-Ancho de pixel
		-Altura de pixel		
		se almacena dentro de crearCarpeta
		*/
		void crearCss(string, string, string, string, string);
		
		string pintar_pixel(string, string);
		string pintar_pixel();	
		string cantidadPixeles(int);
		
		ImportImage();
		~ImportImage();
	protected:
};

#endif
