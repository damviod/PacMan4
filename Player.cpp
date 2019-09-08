#include <iostream>
#include <conio.h>

#include "Player.h"
#include "Laberinto.h"

/*
	VARIABLES DEL PLAYER
*/
SPlayer player;

void PlayerInput()
{
	char tecla = toupper(_getch());
	switch (tecla)
	{
	case 'W':
		MuevePlayer(EDirectionMovement::Up);
		break;
	case 'A':
		MuevePlayer(EDirectionMovement::Left);
		break;
	case 'D':
		MuevePlayer(EDirectionMovement::Right);
		break;
	case 'S':
		MuevePlayer(EDirectionMovement::Down);
		break;
	}
}

void MuevePlayer(EDirectionMovement tipoMovimiento)
{
	char celda;

	SetMap(player.Y, player.X, ' ');

	switch (tipoMovimiento)
	{
	case EDirectionMovement::Up:
		celda = GetMap(player.Y - 1, player.X);
		if ((celda != 'X') && (celda != '\0'))
		{
			player.Y--;
		}
		break;
	case EDirectionMovement::Down:
		celda = GetMap(player.Y + 1, player.X);
		if ((celda != 'X') && (celda != '\0'))
		{
			player.Y++;
		}
		break;
	case EDirectionMovement::Left:
		celda = GetMap(player.Y, player.X - 1);
		if ((celda != 'X') && (celda != '\0'))
		{
			player.X--;
		}
		break;
	case EDirectionMovement::Right:
		celda = GetMap(player.Y, player.X + 1);
		if ((celda != 'X') && (celda != '\0'))
		{
			player.X++;
		}
		break;
	}

	SetMap(player.Y, player.X, player.Skin);
}