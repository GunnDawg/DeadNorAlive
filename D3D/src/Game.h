#pragma once

class Game
{
public:
	void Init();
	void HandleInput() const;
	void Update() const;
	void Draw() const;

	inline bool IsRunning() const { return mIsRunning; }
	inline void Exit() { mIsRunning = false; }

private:
	bool mIsRunning						= false;
};