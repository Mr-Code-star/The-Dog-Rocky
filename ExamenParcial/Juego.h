#pragma once
#include "Configuracion.h"
#include "Personaje.h" 
#include "Enemigo.h"
#include "Rayo.h"
#include "Basura.h"
#include <vector>
class Juego
{
private:

	Personaje* objPersonaje;

	Enemigo* objEne1;
	Enemigo* objEne2;

	Rayo* objRayo5;
	Configuracion* confi = new Configuracion;
	vector<Basura*> vecBasuras;
public:
	Juego()
	{

		objPersonaje = new Personaje();

		objEne1 = new Enemigo(1);
		objEne2 = new Enemigo(2);
		for (int i = 0; i < 10; i++)
		{
			vecBasuras.push_back(new Basura());
		}
		objRayo5 = new Rayo();
		objPersonaje->dibujar();
	}
	~Juego()
	{
		delete objPersonaje;
		delete objEne1;
		delete objEne2;
		delete objRayo5;
	}

	void animarRayo()
	{
		if (!(objRayo5->getY() == HEIGHT - 1))
		{
			objRayo5->borrar();
			objRayo5->mover();
			objRayo5->dibujar();
		}
		else
		{
			objRayo5->borrar();
			delete objRayo5;
			objRayo5 = new Rayo();
		}
	}

	void moverRocky()
	{
		objPersonaje->borrar();
		objPersonaje->mover();
		objPersonaje->dibujar();
	}

	void borrarTodos()
	{
		objEne1->borrar();
		objEne2->borrar();
	}

	void moverTodos()
	{
		objEne1->mover();
		objEne2->mover();
	}

	void dibujarTodos()
	{
		objEne1->dibujarT1();
		objEne2->dibujarT2();

		for (int i = 0; i < vecBasuras.size(); i++)
		{
			vecBasuras.at(i)->dibujar();
		}

	}

	void colisionRayo5()
	{
		if (objPersonaje->getR()->interseccion(objRayo5->getR()))
		{
			objPersonaje->disminuirVidas();
			objPersonaje->borrar();


			Console::SetCursorPosition(objPersonaje->getX(), objPersonaje->getY());
			cout << "IMPACTO PERSONAJE - RAYO";
			_sleep(1000);
			Console::SetCursorPosition(objPersonaje->getX(), objPersonaje->getY());
			cout << "                        ";

			objPersonaje->setX(60);
			objPersonaje->setY(25);

			objRayo5->borrar();
			delete objRayo5;
			objRayo5 = new Rayo();

			objPersonaje->mover();
			objPersonaje->dibujar();
		}
	}

	void colisionH()
	{
		if ((objPersonaje->getR()->interseccion(objEne1->getR())) ||
			objPersonaje->getR()->interseccion(objEne2->getR()))
		{

			objPersonaje->disminuirVidas();
			objPersonaje->borrar();

			Console::SetCursorPosition(objPersonaje->getX(), objPersonaje->getY());
			cout << "IMPACTO PERSONAJE - HAMBURGUESA";
			_sleep(1000);
			Console::SetCursorPosition(objPersonaje->getX(), objPersonaje->getY());
			cout << "                               ";

			objPersonaje->setX(60);
			objPersonaje->setY(25);

			objPersonaje->mover();
			objPersonaje->dibujar();
		}
	}

	void comerHuesos()
	{
		for (int i = 0; i < vecBasuras.size(); i++)
		{
			if (objPersonaje->getR()->interseccion(vecBasuras[i]->getR()))
			{

				vecBasuras[i]->borrar();
				vecBasuras.erase(vecBasuras.begin() + i); // i o 1 (?)
				objPersonaje->borrar();
				objPersonaje->dibujar();

			}
		}

	}

	void contadorVidas()
	{
		Console::SetCursorPosition(95, 27); cout << "Vidas: ";
		Console::ForegroundColor = ConsoleColor(12);
		for (int i = 0; i < objPersonaje->getVidas(); i++)
		{
			cout << char(3) << " ";
		}
		cout << " ";
	}

	void contadorHuesos()
	{
		Console::ForegroundColor = ConsoleColor(15);
		Console::SetCursorPosition(95, 28); cout <<
			"Pesas recogidas: " << (vecBasuras.size() * -1) + 10 << " ";
	}

	bool terminarJuego()
	{
		if (objPersonaje->getVidas() == 0)
		{
			return false;
		}

		if (vecBasuras.size() == 0)
		{
			return false;
		}

		return true;
	}

	void condicionDeVictoria()
	{
		if (vecBasuras.size() == 0)
		{
			int y;
			y += 10;
			int valor = 1 + rand() % 14;
			confi->COLOR(valor);
			Console::SetCursorPosition(20, 13); cout << " FELICITACIONES" << char(33) << char(33) <<  char(33) << " – ROCKY LLEGO AL OBJETIVO " << char(33) << char(33) << char(33) << endl;
		
			
			system("pause>0");
			_sleep(1000);


		}
		else
		{
			int y;
			y += 10;
			int valor = 1 + rand() % 14;
			confi->COLOR(valor);
			Console::SetCursorPosition(20, 13); cout << "“------- GAME OVER -------”" << endl;
			system("pause>0");
		}
		_sleep(1000);
	}
};