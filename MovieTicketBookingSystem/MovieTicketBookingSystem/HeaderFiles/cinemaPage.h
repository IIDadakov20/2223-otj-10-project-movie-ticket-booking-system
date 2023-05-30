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


	bool chooseCity();
	void chooseCinema();

	bool cinemaIsChosen = false;
	bool cityIsChosen = false;

	const char* cityName = "City";
	const char* cinemaName = "Cinema";

	Texture2D cinemaPageBackground;
	Texture2D button;

	Font font;
};

bool DrawButton(int x, int y, int width, int height, Texture2D texture, Vector2 pos, int fontSize, const char* name, Font font);