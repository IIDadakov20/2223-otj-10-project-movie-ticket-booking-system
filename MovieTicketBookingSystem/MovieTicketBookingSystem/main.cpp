#include "Front-End/HeaderFiles/startApplication.h"

int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "MTBS");

	Application app(screenWidth, screenHeight);

	while (!app.ApplicationShouldClose())
	{
		app.startApplication();
	}
}