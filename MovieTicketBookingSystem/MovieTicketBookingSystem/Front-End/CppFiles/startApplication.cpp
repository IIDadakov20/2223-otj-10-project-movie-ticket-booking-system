#include "../HeaderFiles/startApplication.h"
#include "../../Back-End/HeaderFiles/applicationSetUp.h"

MainMenu::MainMenu()
{
	mainMenuBackground = LoadTexture("../assets/mainMenuBackground.png");
	button = LoadTexture("../assets/button.png");
	exitButton = LoadTexture("../assets/exit.png");

	font = LoadFont("../assets/font.ttf");
}

MainMenu::~MainMenu()
{
	UnloadTexture(mainMenuBackground);
	UnloadTexture(button);
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

	DrawButton(360, 455, 250, 70, button, { 425, 465 }, 50, "Sofia", font);
	DrawButton(640, 455, 250, 70, button, { 696, 465 }, 50, "Varna", font);
	DrawButton(920, 455, 250, 70, button, { 967, 465 }, 50, "Burgas", font);
	
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