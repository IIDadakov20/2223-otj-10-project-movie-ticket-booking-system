#pragma once

#include <iostream>
#include <assert.h>
#include <raylib.h>

using namespace std;

class Application
{
public:

	Application(int screenWidth, int screenHeight);
	~Application() noexcept;

	bool ApplicationShouldClose() const;
	void startApplication();

private:

	Texture2D mainMenuBackground = LoadTexture("../assets/mainMenuBackground.png");

	//void Draw();

	int screenWidth = 0;
	int screenHeight = 0;

	Vector2 mouse = { 0,0 };

	//MainMenu& mainMenu = MainMenu::getInstance();
};