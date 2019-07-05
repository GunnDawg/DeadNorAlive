#include "PCH.h"
#include "GameStateMachine.h"

void GameStateMachine::push(std::unique_ptr<GameState> states)
{
	mGameStates.emplace_back(std::move(states));
	mGameStates.back()->on_enter();
}

void GameStateMachine::pop()
{
	if (!mGameStates.empty())
	{
		mGameStates.back()->on_exit();
		mGameStates.pop_back();
	}
}

void GameStateMachine::update()
{
	if (!mGameStates.empty())
	{
		mGameStates.back()->update();
	}
}

void GameStateMachine::draw()
{
	if (!mGameStates.empty())
	{
		mGameStates.back()->draw();
	}
}

void GameStateMachine::handleEvents()
{
	if (!mGameStates.empty())
	{
		mGameStates.back()->handle_events();
	}
}

void GameStateMachine::unloadAll()
{
	while (!mGameStates.empty())
	{
		pop();
	}
}