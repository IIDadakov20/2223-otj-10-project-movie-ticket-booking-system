#include "HeaderFiles/applicationSetUp.h"
#include "nanodbc/nanodbc.h"

int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "MTBS");

	Application app;

	nanodbc::connection conn(NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=localhost\\SQLEXPRESS;Database=CinemaManagement;Trusted_Connection=yes"));

	while (!app.applicationShouldClose())
	{
		app.startApplication();
	}
}