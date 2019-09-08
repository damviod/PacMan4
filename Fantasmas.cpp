#include "Fantasmas.h"
#include "Laberinto.h"
#include "DirectionMovement.h"

/*
	VARIABLES DE LOS FANTASMAS
*/
SFantasma phantom[4];

void MueveFantasmas()
{
	for (int i = 0; i < 4; i++)
	{
		SetMap(phantom[i].Y, phantom[i].X, ' ');
	}
	for (int i = 0; i < 4; i++)
	{
		EDirectionMovement lastMov = phantom[i].lastMovement;
		int currentX = phantom[i].X;
		int currentY = phantom[i].Y;

		switch (lastMov)
		{
		case EDirectionMovement::Up:
			//buscar en celda Left
			if (IsThereAHollow(currentY, currentX - 1))
			{
				phantom[i].X = --currentX;
				phantom[i].lastMovement = EDirectionMovement::Left;
				break;
			}
		case EDirectionMovement::Right:
			//buscar en celda Up
			if (IsThereAHollow(currentY - 1, currentX))
			{
				phantom[i].Y = --currentY;
				phantom[i].lastMovement = EDirectionMovement::Up;
				break;
			}
			//Buscar en celda Right
			if (IsThereAHollow(currentY, currentX + 1))
			{
				phantom[i].X = ++currentX;
				phantom[i].lastMovement = EDirectionMovement::Right;
				break;
			}
			//Buscar en celda Down
			if (IsThereAHollow(currentY + 1, currentX))
			{
				phantom[i].Y = ++currentY;
				phantom[i].lastMovement = EDirectionMovement::Down;
				break;
			}
			//Buscar en celda Left
			if (IsThereAHollow(currentY, currentX - 1))
			{
				phantom[i].X = --currentX;
				phantom[i].lastMovement = EDirectionMovement::Left;
				break;
			}
			break;
		case EDirectionMovement::Down:
			//buscar en celda Right
			if (IsThereAHollow(currentY, currentX + 1))
			{
				phantom[i].X = ++currentX;
				phantom[i].lastMovement = EDirectionMovement::Right;
				break;
			}
		case EDirectionMovement::Left:
			//Buscar en celda Down
			if (IsThereAHollow(currentY + 1, currentX))
			{
				phantom[i].Y = ++currentY;
				phantom[i].lastMovement = EDirectionMovement::Down;
				break;
			}
			//buscar en celda Left
			if (IsThereAHollow(currentY, currentX - 1))
			{
				phantom[i].X = --currentX;
				phantom[i].lastMovement = EDirectionMovement::Left;
				break;
			}
			//Buscar en celda Up
			if (IsThereAHollow(currentY - 1, currentX))
			{
				phantom[i].Y = --currentY;
				phantom[i].lastMovement = EDirectionMovement::Up;
				break;
			}
			//Buscar en celda Right
			if (IsThereAHollow(currentY, currentX + 1))
			{
				phantom[i].X = ++currentX;
				phantom[i].lastMovement = EDirectionMovement::Right;
				break;
			}
		}

		SetMap(phantom[i].Y, phantom[i].X, phantom[i].skinFLIGHT);
	}
}