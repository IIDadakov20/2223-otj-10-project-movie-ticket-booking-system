#include "../HeaderFiles/startApplication.h"
#include "../../Back-End/HeaderFiles/applicationSetUp.h"

MainMenu::MainMenu()
{
	mainMenuBackground = LoadTexture("../assets/mainMenuBackground.png");
	startButton = LoadTexture("../assets/startButton.png");
	exitButton = LoadTexture("../assets/exit.png");

	font = LoadFont("../assets/font.ttf");
}

MainMenu::~MainMenu()
{
	UnloadTexture(mainMenuBackground);
	UnloadTexture(startButton);
	UnloadTexture(exitButton);

	UnloadFont(font);
}

void Application::startApplication()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	if (!mainMenu.isMenuOpen)
	{

	}
	else
	{
		mainMenu.DrawMainMenu();
	}

	EndDrawing();
}

void MainMenu::DrawMainMenu()
{
	DrawTexture(mainMenuBackground, 0, 0, RAYWHITE);

	if (checkCollision(519, 462, 608, 191))
	{
		DrawTexture(startButton, 519, 462, { 150, 144, 144 ,255 });
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			
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

bool DrawButton(int x, int y, int width, int height, Texture2D texture, Vector2 pos, int fontSize, const char* name, Font font)
{
	Rectangle rec = { x, y, width, height };

	DrawTexture(texture, rec.x, rec.y, WHITE);
	DrawTextEx(font, name, pos, fontSize, 5, BLACK);

	if(CheckCollisionPointRec(GetMousePosition(), rec))
	{
		DrawTexture(texture, rec.x, rec.y, { 189, 183, 183 ,255 });
		DrawTextEx(font, name, pos, fontSize, 5, BLACK);

		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			return 1;
		}
	}
	return 0;
}