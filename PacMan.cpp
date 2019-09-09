// PacMan.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <time.h>

#include "Laberinto.h"
#include "DirectionMovement.h"
#include "Player.h"
#include "Fantasmas.h"
#include "GameState.h"
#include "HUD.h"
#include "GameSpawning.h"

EGameState gameState = EGameState::FLIGHT;

//Puntos iniciales
extern const int INIT_POINTS = 100;
//Puntos perdidos por paso
const int STEP_DROP_POINTS = 2;
//Puntos por comer miga
extern const int CRUMB_POINTS = 5;
//Puntos perdidos al ser alcanzado por fantasma
extern const int PHANTOM_DROP_POINTS = 50;
//Puntos por comer fantasma
extern const int PHANTOM_UP_POINTS = 40;


//PASOS NECESARIOS PARA LA VICTORIA
const int VICTORY_STEPS = 100;
//Duración en pasos del estado favorable "persecución"
const int CHASE_STEPS = 25;
//intervalo de pasos para spawn de gema
extern const int GEM_STEPS = 10;
//intervalo de pasos para spawn de crumb o punto básico
extern const int CRUMB_STEPS = 2;

int currentSteps = 0;
int chaseSteps = 0;

extern SPlayer player;

int main()
{
	bool gameOver = false;

	std::cout << "Presione cualquier tecla para iniciar el juego";
	_getch();

	InitGame();

	while (!gameOver)
	{
		PlayerInput();
		MueveFantasmas();
		currentSteps++;
		if (currentSteps == VICTORY_STEPS)
			gameOver = true;

		if (gameState == EGameState::CHASE)
		{
			chaseSteps++;
			if (chaseSteps == CHASE_STEPS)
				gameState = EGameState::FLIGHT;
		}
		player.Points -= STEP_DROP_POINTS;
		if (player.Points <= 0)
			gameOver = true;

		SpawnCrumb(currentSteps);
		SpawnGem(currentSteps);

		system("cls");
		PrintHUD(player.Points, VICTORY_STEPS - currentSteps, gameState, CHASE_STEPS-chaseSteps);
		DibujaMapa();
	}

	if (player.Points > 0)
		std::cout << "ENHORABUENA!! HAS GANADO CON " << player.Points << " puntos\n";
	else
		std::cout << "OOH! Has perdido. Sigue jugando...\n";
	
	getchar();
}


