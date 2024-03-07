#pragma once
#include <iostream>
#include <conio.h>

#define ARRIBA 72 
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

#define WIDTH 120
#define HEIGHT 35

using namespace std;
using namespace System;

class Rectangulo
{
private:
	int x;
	int y;
	int ancho;
	int alto;

public:
	Rectangulo()
	{
		x = 0;
		y = 0;
		alto = 0;
		ancho = 0;
	}
	Rectangulo(int x, int y, int ancho, int alto)
	{
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;

	}
	~Rectangulo() {};

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	int getX1() { return x; }
	int getX2() { return x + ancho; }
	int getY1() { return y; }
	int getY2() { return y + alto; }

	bool interseccion(Rectangulo* r)
	{
		return !((getX2() <= r->getX1()) || (getY2() <= r->getY1()) ||
			(getX1() >= r->getX2() || (getY1() >= r->getY2())));
	}



};