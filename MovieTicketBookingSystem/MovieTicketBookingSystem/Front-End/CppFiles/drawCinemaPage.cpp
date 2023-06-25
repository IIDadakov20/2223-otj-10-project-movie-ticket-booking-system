#include "../../HeaderFiles/ApplicationSetUp.h"

Cinema::Cinema()
{
	cinemaPageBackground = LoadTexture("../assets/cinemaPage.png");
	button = LoadTexture("../assets/button.png");

	font = LoadFontEx("../assets/font.ttf", 25, NULL, 0);
}

Cinema::~Cinema()
{
	UnloadTexture(cinemaPageBackground);
	UnloadTexture(button);

	UnloadFont(font);
}

void Cinema::DrawCinema()
{
	DrawTexture(cinemaPageBackground, 0, 0, RAYWHITE);

	chooseCity();
}

void Cinema::chooseCity()
{
	if (DrawButton(50, 105, button, { 50 + 13, 110 }, 25, cityName, font, cityName))
	{
		cityIsChosen = !cityIsChosen;
	}

	if (cityIsChosen)
	{
		if (DrawButton(190, 105, button, { 190 + 13, 110 }, 25, "Varna", font, cityName))
		{
			
		}
		if (DrawButton(330, 105, button, { 330 + 13, 110 }, 25, "Plovdiv", font, cityName))
		{
			
		}
	}
}

void Cinema::drawMovies()
{
	
}

bool DrawButton(int x, int y, Texture2D texture, Vector2 pos, float fontSize, const char* text, Font font, const char*& name)
{
	DrawTexture(texture, x, y, WHITE);
	DrawTextEx(font, text, pos, fontSize, 5, BLACK);

	if (checkCollision(x, y, 120, 35))
	{
		DrawTexture(texture, x, y, { 189, 183, 183 ,255 });
		DrawTextEx(font, text, pos, fontSize, 5, BLACK);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			name = text;
			return 1;
		}
	}
	return 0;
}