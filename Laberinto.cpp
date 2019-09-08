#include <iostream>
#include <time.h>

#include "Laberinto.h"
#include "DirectionMovement.h"
#include "Player.h"
#include "Fantasmas.h"

extern SPlayer player;
extern SFantasma phantom[4];
extern const int INIT_POINTS;

const int FILAS = 11, COLS = 21;

char laberinto[FILAS][COLS] = {
	{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
	{'X',' ',' ',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'X',' ','X','X','X','X',' ','X',' ','X','X','X','X',' ','X',' ',' ','X',' ',' ','X'},
	{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ','X',' ',' ','X'},
	{'X','X','X','X','X','X',' ','X','X','X','X','X','X',' ','X',' ',' ',' ',' ',' ','X'},
	{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','X','X','X','X','X'},
	{'X',' ','X','X',' ','X','X','X','X','X','X','X',' ','X',' ',' ',' ',' ',' ',' ','X'},
	{'X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','X','X','X','X',' ','X'},
	{'X',' ','X','X','X','X','X','X','X','X','X','X',' ','X',' ',' ',' ',' ','X',' ','X'},
	{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
};

void InitGame()
{
	srand(time(NULL));

	player.Points = INIT_POINTS;
	player.X = 1;
	player.Y = FILAS - 2;
	laberinto[player.Y][player.X] = player.Skin;

	for (int fantasma = 0; fantasma < 4; fantasma++)
	{
		int hueco = FindHollow();
		phantom[fantasma].X = hueco % COLS;
		phantom[fantasma].Y = hueco / COLS;

		phantom[fantasma].lastMovement == EDirectionMovement::Up;
	}
}

int FindHollow()
{
	int startX = rand() % COLS;
	int startY = rand() % FILAS;

	int fila = startY;
	int columna = startX;
	do
	{
		if (GetMap(fila, columna) == ' ')
			return fila * COLS + columna;

		columna++;
		if (columna == COLS)
		{
			columna = 0;
			fila++;
			if (fila == FILAS)
				fila = 0;
		}
	} while ((columna != startX) || (fila != startY));

	return -1;
}

bool IsThereAHollow(int Y, int X)
{
	char celda = GetMap(Y, X);
	if ((celda != 'X') && (celda != '\0'))
		return true;

	return false;
}

void DibujaMapa()
{
	for (int filas = 0; filas < FILAS; filas++)
	{
		for (int columnas = 0; columnas < COLS; columnas++)
			std::cout << laberinto[filas][columnas];

		std::cout << "\n";
	}
}
char GetMap(int Y, int X)
{
	if ((Y >= FILAS) || (X >= COLS) || (Y < 0) || (X < 0))
		return '\0';

	return laberinto[Y][X];
}

bool SetMap(int Y, int X, char caracter)
{
	if ((Y >= FILAS) || (X >= COLS) || (Y < 0) || (X < 0))
		return false;

	laberinto[Y][X] = caracter;

	return true;
}