#include "Front-End/HeaderFiles/startApplication.h"
#include "Back-End/HeaderFiles/applicationSetUp.h"

int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "MTBS");

	Application app;

	while (!app.applicationShouldClose())
	{
		app.startApplication();
	}
}