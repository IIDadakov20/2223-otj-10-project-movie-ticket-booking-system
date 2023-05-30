#include "../../HeaderFiles/applicationSetUp.h"

MainMenu::MainMenu()
{
	mainMenuBackground = LoadTexture("../assets/mainMenuBackground.png");
	startButton = LoadTexture("../assets/startButton.png");
	exitButton = LoadTexture("../assets/exit.png");
	alertBox = LoadTexture("../assets/alertBox.png");
}

MainMenu::~MainMenu()
{
	UnloadTexture(mainMenuBackground);
	UnloadTexture(startButton);
	UnloadTexture(exitButton);
	UnloadTexture(alertBox);
}

void MainMenu::DrawMainMenu()
{
	DrawTexture(mainMenuBackground, 0, 0, RAYWHITE);

	if (checkCollision(715, 490, 415, 140))
	{
		DrawTexture(startButton, 519, 462, { 163, 157, 157 ,255 });
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			isMenuOpen = false;
		}
	}
	
	if (checkCollision(70, 600 , 65, 45))
	{
		DrawTexture(exitButton, 70, 590, { 150, 144, 144 ,255 });
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			appShouldClose = true;
		}
	}
}

void DrawAlert()
{
	
}