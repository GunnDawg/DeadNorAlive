#pragma once
#include "GameState.h"

class GameStateMachine
{
public:
	void push(std::unique_ptr<GameState> states);
	void pop();
	void update();
	void draw();
	void handleEvents();
	void unloadAll();

	std::vector<std::unique_ptr<GameState>> mGameStates;
};