#include "ImportImage.h"
#include <fstream>

ImportImage::ImportImage()
{
	this->contador = 0;
}



ImportImage::~ImportImage()
{
}

void ImportImage::crearCarpeta(string nombre){
	
}

void ImportImage::crearHtml(string nombre, int pixeles){
	ofstream file;	
	file.open(nombre+".html");
	file<<"<!DOCTYPE html>";
	file<<"<html>\n";
	file<<"<head>";
	file<<"<link rel=\"stylesheet\" href=\""+nombre+".css\""<<endl;
	file<<"<\\head>\n";
	file<<"<body>"<<endl;
	file<<"<div class = \"canvas\">"<<endl;

	file<<this->cantidadPixeles(pixeles)<<endl;
	
	file<<"<\\div>"<<endl;
	file<<"<\\body>"<<endl;
	file<<"<\\html>";
	file.close();
}

string ImportImage::cantidadPixeles(int pixeles){
	string color = "";
	for(int i=1;i<pixeles;i++){
		color += "<div class =\"pixel\"><\\div>\n";
	}
	return color;
}


void ImportImage::crearCss(string nombre, string alturaImagen, string anchoImagen, string alturapixel, string anchoPixel){
	ofstream file;
	file.open(nombre+".css");
	file<<"body{"<<endl;
	file<<"	background: #333;"<<endl;
	file<<"	height: 100hv;";
	file<<"	display: flex;"<<endl;
	file<<"	justify-content: center;"<<endl;
	file<<"	aling-items: center;"<<endl;
	file<<"}"<<endl;
	
	file<<""<<endl;
	
	file<<".canvas{"<<endl;
	file<<"	width: "+anchoImagen+"px;"<<endl;
	file<<"	height: "+alturaImagen+"px;"<<endl;
	file<<"}"<<endl;
	
	file<<""<<endl;
	
	file<<".pixel{"<<endl;
	file<<"	width: "+anchoPixel+"px;"<<endl;
	file<<"	height: "+alturapixel+"px;"<<endl;
	file<<"	float: left;"<<endl;
	//file<<" box-shadow: 0px 0px 1px #fff"
	file<<"}"<<endl;
	
	file<<""<<endl;	
	
	file<<this->colorear<<endl;
	
	
	file.close();
}

string ImportImage::pintar_pixel(string pixeles, string rgb){
	string color = "";	
	
	color = ".pixel:nth-child(%s){\nbackground: rgb(%i); }", pixeles, rgb;
	color = this->colorear;
	
	return colorear;
}





