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

            // Generation of the game grid
            for(i = 0; i < GRID_V_CELLS_NUMBER; ++i)
            {
                for(j = 0; j < GRID_H_CELLS_NUMBER; ++j) {
                    DrawRectangleLines(j*GRID_CELL_WIDTH, i*GRID_CELL_HEIGHT, GRID_CELL_WIDTH, GRID_CELL_HEIGHT, BLACK);
                }
            }
            DrawRectangleLines(0, 0, GRID_CELL_WIDTH, GRID_CELL_HEIGHT, BLACK);

            DrawText("Let's play ray Tetris!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;

}