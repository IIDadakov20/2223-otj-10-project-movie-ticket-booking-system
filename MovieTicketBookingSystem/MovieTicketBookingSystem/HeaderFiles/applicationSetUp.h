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

bool checkCollision(float x, float y, float width, float height);

void DrawAlert();