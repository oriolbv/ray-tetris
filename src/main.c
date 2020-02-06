#include "raylib.h"
#include "const.h"


int main(void) 
{
    

    // Window initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ray Tetris");

    SetTargetFPS(60); 


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawRectangleLines(0, 0, GRID_CELL_WIDTH, GRID_CELL_HEIGHT, BLACK);

            DrawText("Let's play ray Tetris!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;

}