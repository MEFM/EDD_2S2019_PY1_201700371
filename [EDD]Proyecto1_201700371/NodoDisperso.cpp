#include "NodoDisperso.h"

using namespace std;



NodoDisperso::NodoDisperso()
{
}

NodoDisperso::~NodoDisperso()
{
}

NodoDisperso::NodoDisperso(string RGB, int x, int y, int z){
	this -> RGB = RGB;
	this -> x = x;
	this -> y = y;
	this -> z = z;
	this -> siguiente = NULL;
	this -> anterior = NULL;
	this -> arriba = NULL;
	this -> abajo = NULL;
}

NodoDisperso::NodoDisperso(string RGB, int x, int y){
	this -> RGB = RGB;
	this -> x = x;
	this -> y = y;
	this -> siguiente = NULL;
	this -> anterior = NULL;
	this -> arriba = NULL;
	this -> abajo = NULL;

}

void NodoDisperso::setRGB(string RGB){
	this -> RGB = RGB;
}

string NodoDisperso::getRGB(){
	return RGB;
}

void NodoDisperso::setX(int x){
	this -> x = x;
}

void NodoDisperso::setZ(int z){
	this -> z = z;
}

void NodoDisperso::setY(int y){
	this -> y = y;
}

int NodoDisperso::getX(){
	return x;
}

int NodoDisperso::getY(){
	return y;
}

int NodoDisperso::getZ(){
	return z;
}
