#include "../../HeaderFiles/ApplicationSetUp.h"

Cinema::Cinema()
{
	cinemaPageBackground = LoadTexture("../assets/cinemaPage.png");
	button = LoadTexture("../assets/button.png");

	font = LoadFontEx("../assets/font.ttf", 25, NULL, 0);

	movieList = {
		{"The Flash","English", "Action/Fantasy", LoadTexture("../assets/movies/TheFlash.png")},
		{"Anna","Bulgarian", "Drama", LoadTexture("../assets/movies/Anna.png")},
		{"Elemental","English", "Animation/Comedy", LoadTexture("../assets/movies/Elemental.png")},
		{"The Boogeyman","English", "Horror/Thriller", LoadTexture("../assets/movies/TheBoogeyman.png")},
	};
}

Cinema::~Cinema()
{
	UnloadTexture(cinemaPageBackground);
	UnloadTexture(button);

	UnloadFont(font);

	for (int i = 0; i < 4; i++)
	{
		UnloadTexture(movieList[i].movieBanner);
	}
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
		DrawButton(190, 105, button, { 190 + 13, 110 }, 25, "Varna", font, cityName);
		DrawButton(330, 105, button, { 330 + 13, 110 }, 25, "Plovdiv", font, cityName);
	}

	drawMovieList();
}

void Cinema::drawMovieList()
{
	if (cityName != "City")
	{
		for (int i = 0; i < 4; i++)
		{
			DrawTexture(movieList[i].movieBanner, 72 * (i + 1) + 230 * i, 220, WHITE);
		}
	}
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