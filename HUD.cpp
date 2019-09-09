#include "HUD.h"
#include <iostream>

using namespace std;

void PrintHUD(int puntosPlayer, int remainingSteps, EGameState gameState, int remainingChaseSteps)
{
	cout << "\n";
	cout << "************************************************************************************\n";
	cout << "PUNTOS RESTANTES: " << puntosPlayer << "\t";
	cout << "PASOS RESTANTES: " << remainingSteps << "\t";

	cout << "ESTADO: ";
	switch (gameState)
	{
	case EGameState::FLIGHT:
		cout << "HUIDA";
		break;
	case EGameState::CHASE:
		cout << "PERSECUCION";
		break;
	}
	cout << "\t";

	if (gameState == EGameState::CHASE)
		cout << "PASOS FIN PERSECUCION: " << remainingChaseSteps;

	cout << "\n";
	cout << "************************************************************************************\n";
}
