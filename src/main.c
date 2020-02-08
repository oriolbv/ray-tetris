#include "raylib.h"
#include "const.h"
#include "grid.c"

int main(void) 
{
    // Window initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ray Tetris");

    SetTargetFPS(60); 
    
    initGameGrid();
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(SKYBLUE);

            paintGameGrid();

            // DrawText("Let's play ray Tetris!", 190, 200, 20, SKYBLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;

}