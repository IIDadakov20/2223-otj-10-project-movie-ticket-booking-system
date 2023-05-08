#pragma once

#include <iostream>
#include <raylib.h>

using namespace std;

class MainMenu
{
public:

	MainMenu(MainMenu const&) = delete;
	void operator=(MainMenu const&) = delete;

	static MainMenu& getInstance();
	void DrawMainMenu();

	bool isMenuOpen = true;
	bool appShouldClose = false;

private:

	MainMenu();
	~MainMenu();

	//void newGame();

	Texture2D mainMenuBackground;
	Texture2D button;
	Texture2D exitButton;

	Font font;
};

bool DrawButton(int x, int y, int width, int height, Texture2D texture, Vector2 pos, int fontSize, const char* name, Font font);

//void DrawText(int x, int y, int fontSize, const char* name, Font font);