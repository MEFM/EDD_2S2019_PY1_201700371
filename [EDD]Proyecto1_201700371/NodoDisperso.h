#ifndef NODODISPERSO_H
#define NODODISPERSO_H
#include <string>
#include <iostream>


using namespace std;
class NodoDisperso
{
	private:
		string RGB;
		int x;
		int y;
		int z;
	
	public:
		static int nivel;
		NodoDisperso* siguiente;
		NodoDisperso* anterior;
		NodoDisperso* arriba;
		NodoDisperso* abajo;
		NodoDisperso* zposit;
		NodoDisperso* znegat;	
		void setRGB(string);
		string getRGB();
		void setX(int);
		void setY(int);
		void setZ(int);
		int getX();
		int getY();
		int getZ();
		NodoDisperso(string, int, int);	
		NodoDisperso(string, int, int, int);
		NodoDisperso();
		~NodoDisperso();

};

#endif
