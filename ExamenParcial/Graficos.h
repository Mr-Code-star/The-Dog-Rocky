#pragma once
#include"Juego.h"
#include "Librerias.h"

class Graficos
{
private:

public:
    Graficos() {}
    ~Graficos() {}

    void Cursor(int x, int y)
    {
        Console::SetCursorPosition(x, y);
    }


    void color(int c)
    {
        switch (c)
        {
        case 1: Console::ForegroundColor = ConsoleColor::Black; break;
        case 2: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
        case 3: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
        case 4: Console::ForegroundColor = ConsoleColor::DarkRed; break;
        case 5: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
        case 6: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
        case 7: Console::ForegroundColor = ConsoleColor::Gray; break;
        case 8: Console::ForegroundColor = ConsoleColor::DarkGray; break;
        case 9: Console::ForegroundColor = ConsoleColor::Blue; break;
        case 10: Console::ForegroundColor = ConsoleColor::Green; break;
        case 11: Console::ForegroundColor = ConsoleColor::Cyan; break;
        case 12: Console::ForegroundColor = ConsoleColor::Red; break;
        case 13: Console::ForegroundColor = ConsoleColor::Magenta; break;
        case 14: Console::ForegroundColor = ConsoleColor::Yellow; break;
        case 15: Console::ForegroundColor = ConsoleColor::White; break;
        }
    }

    void GENERAMATRIZ(int fondo[HEIGHT][WIDTH])
    {
        for (int f = 0; f < HEIGHT; f++)
        {
            for (int c = 0; c < WIDTH; c++)
            {
                Cursor(c, f);
                if (fondo[f][c] == 0) color(10);
                if (fondo[f][c] == 1) color(15);
                if (fondo[f][c] == 2) color(3);
                if (fondo[f][c] == 3) color(4);
                if (fondo[f][c] == 4) color(5);
                if (fondo[f][c] == 5) color(6);
                if (fondo[f][c] == 6) color(7);
                if (fondo[f][c] == 7) color(8);
                if (fondo[f][c] == 8) color(9);
                if (fondo[f][c] == 9) color(1);
                if (fondo[f][c] == 10) color(11);
                if (fondo[f][c] == 11) color(12);
                if (fondo[f][c] == 12) color(13);
                if (fondo[f][c] == 13) color(14);
                if (fondo[f][c] == 14) color(2);
                cout << (char)219;
            }
        }
    }





};

