#pragma once

#include <iostream>
#include <assert.h>
#include "startApplication.h"
#include "cinemaPage.h"

class Application
{
public:

	Application();
	~Application() noexcept;

	bool applicationShouldClose() const;
	void startApplication();

private:

	MainMenu& mainMenu = MainMenu::getInstance();
	Cinema& cinemaPage = Cinema::getInstance();

};

bool checkCollision(int x, int y, int width, int height);

void DrawAlert();