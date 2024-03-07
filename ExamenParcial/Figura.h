#pragma once
#include "Rectangulo.h"

class Figura
{
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int color;
	Rectangulo* r;
public:
	Figura()
	{
		x = 0;
		y = 0;
		dx = 0;
		dy = 0;
		ancho = 0;
		alto = 0;
		color = 0;
	}

	Figura(int x, int y, int dx, int dy, int ancho, int alto, int color)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->ancho = ancho;
		this->alto = alto;
		this->color = color;
		r = new Rectangulo(x, y, ancho, alto);
	}
	~Figura() {};

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int dx) { this->dx = dx; }
	void setDy(int dy) { this->dy = dy; }
	void setAncho(int ancho) { this->ancho = ancho; }
	void setAlto(int alto) { this->alto = alto; }
	void setColor(int color) { this->color = color; }

	int getX() { return this->x; }
	int getY() { return this->y; }
	int getDx() { return this->dx; }
	int getDy() { return this->dy; }
	int getAncho() { return this->ancho; }
	int getAlto() { return this->alto; }
	int getColor() { return this->color; }
	Rectangulo* getR() { return r; }

	virtual void borrar() = 0;
	virtual void mover() = 0;
	virtual void dibujar() = 0;



};