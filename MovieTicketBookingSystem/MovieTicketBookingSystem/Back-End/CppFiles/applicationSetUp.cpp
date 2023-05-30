#include "../../HeaderFiles/applicationSetUp.h"

Application::Application()
{
	SetExitKey(KEY_ESCAPE);
}

Application::~Application() noexcept
{
	assert(GetWindowHandle());
	CloseWindow();
}

void Application::startApplication()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	if (!mainMenu.isMenuOpen)
	{
		cinemaPage.DrawCinema();
	}
	else
	{
		mainMenu.DrawMainMenu();
	}

	EndDrawing();
}

bool Application::applicationShouldClose() const
{
	return mainMenu.appShouldClose || WindowShouldClose();
}

MainMenu& MainMenu::getInstance()
{
	static MainMenu mainMenu;
	return mainMenu;
}

Cinema& Cinema::getInstance()
{
	static Cinema cinemaPage;
	return cinemaPage;
}

bool checkCollision(int x, int y, int width, int height)
{
	Rectangle rec = { x, y, width, height };

	return CheckCollisionPointRec(GetMousePosition(), rec);
}