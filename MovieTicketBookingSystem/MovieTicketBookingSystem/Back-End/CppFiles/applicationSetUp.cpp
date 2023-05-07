#include "../HeaderFiles/applicationSetUp.h"

Application::Application(int width, int height)
	:
	screenWidth(width),
	screenHeight(height)
{
	SetExitKey(KEY_ESCAPE);
}

Application::~Application() noexcept
{
	assert(GetWindowHandle());
	CloseWindow();
}

bool Application::ApplicationShouldClose() const
{
	return WindowShouldClose();
}