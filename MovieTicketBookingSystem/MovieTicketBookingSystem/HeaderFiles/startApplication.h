#pragma once

#include <iostream>
#include <raylib.h>

class MainMenu
{
public:

	static MainMenu& getInstance();
	void DrawMainMenu();

	bool isMenuOpen = true;
	bool appShouldClose = false;

private:

	MainMenu();
	~MainMenu();

	Texture2D mainMenuBackground;
	Texture2D startButton;
	Texture2D exitButton;
	Texture2D alertBox;
};

//void DrawText(int x, int y, int fontSize, const char* name, Font font);