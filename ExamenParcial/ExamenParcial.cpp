#include "pch.h"
#include "Juego.h"
#include "Graficos.h"

int main()
{

    while (true)
    {

        srand(time(0));
        Console::CursorVisible = false;
        Juego* objJuego = new Juego();
        system("cls");
        while (objJuego->terminarJuego())
        {
            if (kbhit())
            {
                char tecla = getch();
                objJuego->moverRocky();
            }

            objJuego->animarRayo();
            objJuego->borrarTodos();
            objJuego->moverTodos();
            objJuego->dibujarTodos();

            objJuego->colisionRayo5();
            objJuego->colisionH();
            objJuego->comerHuesos();
            objJuego->contadorVidas();
            objJuego->contadorHuesos();

            _sleep(100);
        }
        objJuego->condicionDeVictoria();


    }
    return 0;
}
