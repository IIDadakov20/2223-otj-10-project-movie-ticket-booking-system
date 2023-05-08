#pragma once

#include <iostream>
#include <assert.h>
#include "../../Front-End/HeaderFiles/startApplication.h"

using namespace std;

class Application
{
public:

	Application();
	~Application() noexcept;

	bool applicationShouldClose() const;
	void startApplication();

private:

	MainMenu& mainMenu = MainMenu::getInstance();
};

bool checkCollision(int x, int y, int width, int height);