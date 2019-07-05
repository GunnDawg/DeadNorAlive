#pragma once

class GameState
{
public:
	virtual void on_enter() = 0;
	virtual void on_exit() = 0;
	virtual void update() = 0;
	virtual void handle_events() = 0;
	virtual void draw() = 0;
};