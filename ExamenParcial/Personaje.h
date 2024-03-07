#pragma once
#include "Figura.h"

class Personaje :public Figura
{
private:
	int vidas;

public:

	Personaje() :Figura(60, 25, 0, 0, 9, 5, 14)
	{
		vidas = 3;
		r = new Rectangulo(60, 20, 9, 5);
	}

	~Personaje() {};

	void setVidas(int vidas) { this->vidas = vidas; }
	int getVidas() { return this->vidas; }

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
		if (_kbhit())
		{
			char tecla = _getch();

			switch (tecla)
			{
			case ARRIBA:
				if (y > 1) y--;
				break;
			case ABAJO:
				if (y < 25) y++;
				break;
			case DERECHA:
				if (x < WIDTH - 2) x++;
				break;
			case IZQUIERDA:
				if (x > 2) x--;
				break;
			default:
				break;
			}
		}
		r->setX(x);
		r->setY(y);
	}

	void dibujar()
	{
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y);	  cout << ",-, ___ ,-, ";
		Console::SetCursorPosition(x, y + 1); cout << "\\_/    \\_/";
		Console::SetCursorPosition(x, y + 2); cout << "   )O_O(    ";
		Console::SetCursorPosition(x, y + 3); cout << "  { (_) }   ";
		Console::SetCursorPosition(x, y + 4); cout << "   `-^-'    ";
	}

	void disminuirVidas()
	{
		vidas--;
	}
};