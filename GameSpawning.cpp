#include "GameSpawning.h"
#include "Laberinto.h"

extern const int CRUMB_STEPS;
extern const int GEM_STEPS;
extern const int COLS;

void SpawnCrumb(int currentSteps)
{
	if (currentSteps % CRUMB_STEPS == 0)
	{
		int posCodificada = FindHollow();
		if (posCodificada != -1)
		{
			int X = posCodificada % COLS;
			int Y = posCodificada / COLS;

			SetMap(Y, X, '.');
		}
	}
}

void SpawnGem(int currentSteps)
{
	if (currentSteps % GEM_STEPS == 0)
	{
		int posCodificada = FindHollow();
		if (posCodificada != -1)
		{
			int X = posCodificada % COLS;
			int Y = posCodificada / COLS;

			SetMap(Y, X, '*');
		}
	}
}
