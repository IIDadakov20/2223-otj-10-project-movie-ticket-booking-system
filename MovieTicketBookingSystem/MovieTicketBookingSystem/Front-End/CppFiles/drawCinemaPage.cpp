#include "../../HeaderFiles/cinemaPage.h"

Cinema::Cinema()
{
	cinemaPageBackground = LoadTexture("../assets/cinemaPage.png");
	button = LoadTexture("../assets/button.png");

	font = LoadFont("../assets/font.ttf");
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

	if (cityIsChosen && cityName != "Cinema")
	{
		chooseCinema();
	}
}

bool Cinema::chooseCity()
{
	if (DrawButton(55, 110, 250, 70, button, { 115, 125 }, 40, cityName, font))
	{
		cityIsChosen = !cityIsChosen;
	}

	DrawButton(325, 110, 250, 70, button, { 385, 125 }, 40, cinemaName, font);

	if (cityIsChosen)
	{
		if (DrawButton(55, 210, 250, 70, button, { 115, 225 }, 40, "Burgas", font))
		{
			cityName = "Burgas";
			cinemaName = "Cinema";

		}
		if (DrawButton(55, 310, 250, 70, button, { 115, 325 }, 40, "Varna", font))
		{
			cityName = "Varna";
			cinemaName = "Cinema";
		}
	}

	return cityIsChosen;
}

void Cinema::chooseCinema()
{
	if (cityName == "Burgas")
	{
		if (DrawButton(325, 210, 250, 70, button, { 385, 225 }, 40, "MS", font))
		{
			cinemaName = "MS";
		}
		if (DrawButton(325, 310, 250, 70, button, { 385, 325 }, 40, "Kon", font))
		{
			cinemaName = "Kon";
		}
	}

	if (cityName == "Varna")
	{
		if (DrawButton(325, 210, 250, 70, button, { 385, 225 }, 40, "MS", font))
		{
			cinemaName = "MS";
		}
		if (DrawButton(325, 310, 250, 70, button, { 385, 325 }, 40, "Kon", font))
		{
			cinemaName = "Kon";
		}
	}
}

bool DrawButton(int x, int y, int width, int height, Texture2D texture, Vector2 pos, int fontSize, const char* name, Font font)
{
	Rectangle rec = { x, y, width, height };

	DrawTexture(texture, rec.x, rec.y, WHITE);
	DrawTextEx(font, name, pos, fontSize, 5, BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), rec))
	{
		DrawTexture(texture, rec.x, rec.y, { 189, 183, 183 ,255 });
		DrawTextEx(font, name, pos, fontSize, 5, BLACK);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			return 1;
		}
	}
	return 0;
}