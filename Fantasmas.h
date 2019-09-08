#pragma once

#include "DirectionMovement.h"

struct SFantasma
{
	const char skinCHASE = '"';
	const char skinFLIGHT = '^';
	unsigned short int X, Y;

	EDirectionMovement lastMovement;
};

void MueveFantasmas();