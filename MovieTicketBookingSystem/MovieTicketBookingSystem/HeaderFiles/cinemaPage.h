#pragma once

#include <iostream>
#include <raylib.h>
#include <string>

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
	void drawMovies();

	bool cityIsChosen = false;

	const char* cityName = "City";

	Texture2D cinemaPageBackground;
	Texture2D button;

	Font font;
};

bool DrawButton(int x, int y, Texture2D texture, Vector2 pos, float fontSize, const char* text, Font font, const char*& name);