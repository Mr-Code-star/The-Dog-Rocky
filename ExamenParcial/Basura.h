#pragma once
#include "Figura.h"

class Basura :public Figura
{
private:

public:
	Basura() :Figura(x, y, 0, 0, 2, 1, 15)
	{
		x = rand() % (WIDTH - 5) + 1;
		y = rand() % (HEIGHT - 5 - 1) + 1;
		r = new Rectangulo(x, y, 4, 1);
	}

	~Basura() {};

	void borrar()
	{
		Console::SetCursorPosition(x, y); cout << "  " << " " << " " << " " << " " << " ";
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
		Console::SetCursorPosition(x, y); cout << char(174) << char(219) << char(205) << char(205) << char(219) << char(175);
	}

};