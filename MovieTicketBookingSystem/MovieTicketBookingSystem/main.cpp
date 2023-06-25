#include "HeaderFiles/applicationSetUp.h"
#include "nanodbc/nanodbc.h"

int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "MTBS");

	Application app;

	//nanodbc::connection conn(NANODBC_TEXT("Data Source=DESKTOP-UBABQHO\SQLEXPRESS;Integrated Security=True;Connect Timeout=30;Encrypt=False;Trust Server Certificate=False;Application Intent=ReadWrite;Multi Subnet Failover=False"));

	while (!app.applicationShouldClose())
	{
		app.startApplication();
	}
}