#pragma once

#include "DirectionMovement.h"

void PlayerInput();
void MuevePlayer(EDirectionMovement tipoMovimiento);

struct SPlayer
{
	const char Skin = 'O';
	unsigned short int X, Y;
	int Points;
};