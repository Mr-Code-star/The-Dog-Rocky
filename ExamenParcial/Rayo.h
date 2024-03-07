#pragma once
#include "Figura.h"

class Rayo :public Figura
{
private:

public:
	Rayo() : Figura(rand() % (WIDTH - 10) + 5, 1, 0, 1, 1, 1, 1)
	{
		r = new Rectangulo(1, 0, 1, 1);
	}

	~Rayo() {};

	void borrar()
	{
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void mover()
	{
		if (x + dx < 0 || x + dx + ancho > WIDTH) dx *= -1;
		if (y + dy < 0 || y + dy + alto > HEIGHT) dy *= -1;

		x += dx;
		y += dy;

		r->setX(x);
		r->setY(y);
	}

	void dibujar()
	{
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y); cout << char(4);
	}

};