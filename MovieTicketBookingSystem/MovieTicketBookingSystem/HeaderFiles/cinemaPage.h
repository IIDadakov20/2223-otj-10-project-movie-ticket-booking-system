#pragma once

#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>

struct MovieData
{
	std::string movieName;
	std::string movieLanguage;
	std::string movieGenre;

	Texture2D movieBanner;
};

class Cinema
{
public:

	Cinema(Cinema const&) = delete;
	void operator=(Cinema const&) = delete;

	static Cinema& getInstance();
	void DrawCinema();

private:

	Cinema();
	~Cinema();

	void chooseCity();
	void drawMovieList();

	bool cityIsChosen = false;
	const char* cityName = "City";
	std::vector<MovieData> movieList;

	Texture2D cinemaPageBackground;
	Texture2D button;

	Font font;
};

std::vector<int> cinemaBannerShuffle(std::vector<int> movie);

bool DrawButton(int x, int y, Texture2D texture, Vector2 pos, float fontSize, const char* text, Font font, const char*& name);