#pragma once
#include "Game.h"
#include "GameStateMachine.h"

static void UpdateCursorPos(const LPARAM& lParam);
static void HandleInput();
static void Update();
static void Draw();

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
int CALLBACK WinMain(HINSTANCE Instance, HINSTANCE PrevInstance, LPSTR CommandLine, int ShowCode);

struct Window
{
	WNDCLASSEX wc						= { 0 };
	HWND hwnd							= { 0 };
	MSG Msg								= { 0 };
	HDC WindowDC						= { 0 };
	HGLRC BootstrapContext				= { 0 };
	HGLRC ModernContext					= { 0 };

	uint16 Width						= 0;
	uint16 Height						= 0;

	uint16 CenterX						= 0;
	uint16 CenterY						= 0;
};

struct Mouse
{
	uint16 x							= 0;
	uint16 y							= 0;
	uint16 z							= 0;
};

struct DeltaClock
{
	int64 prevTime						= 0;
	int64 currentTime					= 0;
	int64 countsPerSec					= 0;
	float secondsPerCount				= 0.0f;
	float deltaTime						= 0.0f;
};

namespace Core
{
	inline static auto game				= std::make_unique<Game>();
	inline static auto window			= std::make_unique<Window>();
	inline static auto mouse			= std::make_unique<Mouse>();
	inline static auto deltaClock		= std::make_unique<DeltaClock>();
	inline static auto GSM				= std::make_unique<GameStateMachine>();
}