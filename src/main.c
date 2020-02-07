#include "raylib.h"
#include "const.h"
#include "background.c"

int main(void) 
{
    

    // Window initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ray Tetris");

    SetTargetFPS(60); 


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(SKYBLUE);

            generateGameGrid();

            // DrawText("Let's play ray Tetris!", 190, 200, 20, SKYBLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;

}