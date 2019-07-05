#include "PCH.h"
#include "Win32Platform.h"
#include "Scene02.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32s.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = NULL;

	switch (Msg)
	{
		case WM_CLOSE:
		{
			Core::game->Exit();
		} break;

		case WM_QUIT:
		{
			Core::game->Exit();
		} break;

		case WM_DESTROY:
		{
			Core::game->Exit();
		} break;

		case WM_KEYDOWN:
		{
			if (wParam == VK_ESCAPE)
			{
				Core::game->Exit();
			}
			if (wParam == VK_RIGHT)
			{
				Core::GSM->pop();

				std::unique_ptr<GameState> scene02 = std::make_unique<Scene02>();
				Core::GSM->push(std::move(scene02));
			}

		} break;

		case WM_MOUSEMOVE:
		{
			UpdateCursorPos(lParam);
		} break;

		default:
			Result = DefWindowProc(hWnd, Msg, wParam, lParam);
	}

	return(Result);
}

#ifdef _DEBUG
	int main(int argc, char* args[])
	{
		if (WinMain(GetModuleHandle(nullptr), GetModuleHandle(nullptr), nullptr, SW_SHOW) == 0)
		{
			return(EXIT_SUCCESS);
		}
		else
		{
			return(EXIT_FAILURE);
		}
	}
#endif

int CALLBACK WinMain(HINSTANCE Instance, HINSTANCE PrevInstance, LPSTR CommandLine, int ShowCode)
{
	Core::window->Width					= 1600;
	Core::window->Height				= 900;

	Core::window->CenterX				= (Core::window->Width / 2);
	Core::window->CenterY				= (Core::window->Height / 2);

	Core::window->wc.cbSize				= sizeof(Core::window->wc);
	Core::window->wc.style				= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	Core::window->wc.lpfnWndProc		= WndProc;
	Core::window->wc.hInstance			= Instance;
	Core::window->wc.hCursor			= LoadCursor(nullptr, IDC_ARROW);
	Core::window->wc.hIcon				= nullptr;
	Core::window->wc.hIconSm			= nullptr;
	Core::window->wc.hbrBackground		= nullptr;
	Core::window->wc.lpszMenuName		= nullptr;
	Core::window->wc.lpszClassName		= "WndClass";

	if (!RegisterClassEx(&Core::window->wc))
	{
		std::cout << "Error registering window class\n";
		return(EXIT_FAILURE);
	}

	Core::window->hwnd = CreateWindowEx(
				0, Core::window->wc.lpszClassName,
				"Dead nor Alive",
				WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU | WS_VISIBLE,
				CW_USEDEFAULT,CW_USEDEFAULT,
				Core::window->Width, Core::window->Height,
				nullptr,
				nullptr,
				Instance,
				nullptr);

	if (!Core::window->hwnd)
	{
		std::cout << "Error creating window!\n";
		return(EXIT_FAILURE);
	}

	Core::window->WindowDC = GetDC(Core::window->hwnd);

	if (!InitializeOpenGL(Core::window->WindowDC, Core::window->BootstrapContext, Core::window->ModernContext))
		return(false);

	Core::game->Init();

	QueryPerformanceCounter((LARGE_INTEGER*)& Core::deltaClock->prevTime);
	QueryPerformanceFrequency((LARGE_INTEGER*)& Core::deltaClock->countsPerSec);
	Core::deltaClock->secondsPerCount = 1.0f / Core::deltaClock->countsPerSec;

	while (Core::game->IsRunning())
	{
		Core::deltaClock->currentTime = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)& Core::deltaClock->currentTime);
		Core::deltaClock->deltaTime = (Core::deltaClock->currentTime - Core::deltaClock->prevTime) * Core::deltaClock->secondsPerCount * 1000;

		while(PeekMessage(&Core::window->Msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Core::window->Msg);
			DispatchMessage(&Core::window->Msg);
		}

		HandleInput();
		Update();
		Draw();

		Core::deltaClock->prevTime = Core::deltaClock->currentTime;
	}

	return(EXIT_SUCCESS);
}

void UpdateCursorPos(const LPARAM& lParam)
{
	const POINTS pt = MAKEPOINTS(lParam);

	Core::mouse->x = pt.x;
	Core::mouse->y = pt.y;
}

void HandleInput()
{
	Core::game->HandleInput();
}

void Update()
{
#ifdef _DEBUG
	std::ostringstream oss;
	oss << "Dead nor Alive - (DEBUG BUILD INFO) Frame Time: " << Core::deltaClock->deltaTime << "ms";
	SetWindowText(Core::window->hwnd, oss.str().c_str());
#endif

	Core::game->Update();
}

void Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Core::game->Draw();

	SwapBuffers(Core::window->WindowDC);
}