#pragma once
#include "Figura.h"

class Enemigo : public Figura
{
private:
	int tipo;

public:
	Enemigo(int tipo) :Figura(x, y, dx, 0, 13, 6, color)
	{
		x = rand() % (WIDTH / 2) + 20;
		y = 1 + rand() % (HEIGHT / 2) - 1 + 1;

		this->tipo = tipo;
		if (rand() % 4 + 1 == 1)
		{
			dx = -1;
		}
		else if (rand() % 4 + 1 == 2)
		{
			dx = -2;
		}
		else if (rand() % 4 + 1 == 3)
		{
			dx = 2;
		}
		else
		{
			dx = 1;
		}

		if (tipo == 1)
		{
			color = 2;
		}
		else
		{
			color = 4;
		}

		r = new Rectangulo(x, y, 13, 6);
	}

	~Enemigo() {};

	void borrar()
	{
		Console::SetCursorPosition(x, y);	  cout << "            ";
		Console::SetCursorPosition(x, y + 1); cout << "            ";
		Console::SetCursorPosition(x, y + 2); cout << "            ";
		Console::SetCursorPosition(x, y + 3); cout << "            ";
		Console::SetCursorPosition(x, y + 4); cout << "            ";
	}

	void mover()
	{
		if (x + dx < 1) { x = WIDTH - ancho; }
		if (x + dx + ancho > WIDTH) { x = 1; }

		x += dx;
		y += dy;

		r->setX(x);
		r->setY(y);
	}

	void dibujar() {};

	void dibujarT1()
	{
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y);	  cout << "   -""""-   ";
		Console::SetCursorPosition(x, y + 1); cout << " /' . '. \\ ";
		Console::SetCursorPosition(x, y + 2); cout << "(`-..:...-')";
		Console::SetCursorPosition(x, y + 3); cout << " ;-......-; ";
		Console::SetCursorPosition(x, y + 4); cout << "  '------'  ";
	}

	void dibujarT2()
	{
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y);	  cout << "   ______   ";
		Console::SetCursorPosition(x, y + 1);	  cout << ".-'      `-.";
		Console::SetCursorPosition(x, y + 2); cout << "(__________)";
		Console::SetCursorPosition(x, y + 3); cout << " (________) ";
		Console::SetCursorPosition(x, y + 4); cout << "(__________)";
	}

};