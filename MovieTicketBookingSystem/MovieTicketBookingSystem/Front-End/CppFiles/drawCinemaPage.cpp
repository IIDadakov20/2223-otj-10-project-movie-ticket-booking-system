#include "../../HeaderFiles/ApplicationSetUp.h"

Cinema::Cinema()
{
	cinemaPageBackground = LoadTexture("../assets/cinemaPage.png");
	button = LoadTexture("../assets/button.png");

	font = LoadFontEx("../assets/font.ttf", 25, NULL, 0);

	movieList = {
		{"Anna","Bulgarian", "Drama", LoadTexture("../assets/movies/Anna.png")},
		{"Close", "French", "Drama", LoadTexture("../assets/movies/Close.png")},
		{"Elemental","English", "Animation/Comedy", LoadTexture("../assets/movies/Elemental.png")},
		{"Hypnotic", "English", "Action/Thriller", LoadTexture("../assets/movies/Hypnotic.png")},
		{"The Boogeyman","English", "Horror/Thriller", LoadTexture("../assets/movies/TheBoogeyman.png")},
		{"The Flash","English", "Action/Fantasy", LoadTexture("../assets/movies/TheFlash.png")},
	};
}

Cinema::~Cinema()
{
	UnloadTexture(cinemaPageBackground);
	UnloadTexture(button);

	UnloadFont(font);

	for (int i = 0; i < movieList.size(); i++)
	{
		UnloadTexture(movieList[i].movieBanner);
	}
}

void Cinema::DrawCinema()
{
	DrawTexture(cinemaPageBackground, 0, 0, RAYWHITE);

	chooseCity();

	drawMovieList();
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
}

void Cinema::drawMovieList()
{
	static std::vector<int> movie;
	movie = cinemaBannerShuffle(movie);

	std::unordered_map<std::string, std::array<int, 4>> cityIndex = {
	{ "Varna", {0, 1, 3, 4} },
	{ "Plovdiv", {1, 2, 4, 5} },
	};

	auto cityRange = cityIndex.find(cityName);

	for (int i = 0; i < 4; i++)
	{
		int startIndex = (cityRange != cityIndex.end()) ? cityRange->second[i] : 0;

		if (cityName != "City")
		{
			DrawTexturePro(movieList[startIndex].movieBanner, { 0, 0, 500, 700 }, { float(72) * (i + 1) + 230 * i, 220, 230, 320 }, Vector2(), 0, WHITE);
		}
		else
		{
			DrawTexturePro(movieList[movie[i]].movieBanner, { 0, 0, 500, 700 }, { float(72) * (i + 1) + 230 * i, 220, 230, 320 }, Vector2(), 0, WHITE);
		}
	}
}

void Cinema::drawMoviePage()
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