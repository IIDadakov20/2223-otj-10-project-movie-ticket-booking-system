#include "../HeaderFiles/applicationSetUp.h"

Application::Application()
{
	SetExitKey(KEY_ESCAPE);
}

Application::~Application() noexcept
{
	assert(GetWindowHandle());
	CloseWindow();
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

bool checkCollision(int x, int y, int width, int height)
{
	Rectangle rec = { x, y, width, height };

	return CheckCollisionPointRec(GetMousePosition(), rec);
}