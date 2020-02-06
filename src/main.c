
#include "raylib.h"

int main(void) 
{
    // Window size
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Window initialization
    InitWindow(screenWidth, screenHeight, "ray Tetris");

    SetTargetFPS(60); 


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Let's play ray Tetris!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;

}