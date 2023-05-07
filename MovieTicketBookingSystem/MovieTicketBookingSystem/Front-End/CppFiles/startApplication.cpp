#include "../HeaderFiles/startApplication.h"

void Application::startApplication()
{
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(mainMenuBackground, 0, 0, WHITE);
        

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
}