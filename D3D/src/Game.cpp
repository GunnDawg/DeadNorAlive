#include "PCH.h"
#include "Game.h"
#include "Scene01.h"

void Game::Init()
{
	std::unique_ptr<GameState> scene01 = std::make_unique<Scene01>();
	Core::GSM->push(std::move(scene01));

	mIsRunning = true;
}

void Game::HandleInput() const
{
	Core::GSM->handleEvents();
}

void Game::Update() const
{
	Core::GSM->update();
}

void Game::Draw() const
{
	Core::GSM->draw();
}