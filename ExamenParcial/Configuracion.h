#pragma once
#pragma once
#include "Librerias.h"

class Configuracion
{

public:
	Configuracion() {};
	~Configuracion() {};
	void CONFIGURACION_PANTALLA()
	{
		Console::CursorVisible = false;
		Console::SetWindowSize(140, 49);
	}
	void CURSOR(int x, int y)
	{
		Console::SetCursorPosition(x, y);
	}

	void COLOR(int c)
	{

		switch (c)
		{
		case 0: Console::ForegroundColor = ConsoleColor::Cyan; break;
		case 1: cout << BROWN; break;
		case 2: Console::ForegroundColor = ConsoleColor::Yellow; break;
		case 3: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
		case 4: Console::ForegroundColor = ConsoleColor::White; break;
		case 5: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
		case 6: Console::ForegroundColor = ConsoleColor::Cyan; break;
		case 7: Console::ForegroundColor = ConsoleColor::Yellow; break;
		case 8: Console::ForegroundColor = ConsoleColor::Green; break;
		case 9: Console::ForegroundColor = ConsoleColor::Black; break;
		case 10:  Console::ForegroundColor = ConsoleColor::White; break;
		case 11: Console::ForegroundColor = ConsoleColor::DarkCyan; break;
		case 12: cout << RED; break;
		case 13: Console::ForegroundColor = ConsoleColor::Blue; break;
		case 14: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
		case 16: Console::ForegroundColor = ConsoleColor::Magenta; break;

		}
	}
};