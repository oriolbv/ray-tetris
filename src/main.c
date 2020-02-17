#include "raylib.h"
#include "const.h"
#include "grid.c"
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int game_velocity_ms = 500;

void msleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void *threadproc(void *arg)
{
    bool done = false;
    while(!done)
    {
        msleep(game_velocity_ms);
        updateGameGrid();
    }
    return 0;
}

void writeMessageLogger(char *msg) {
    DrawText(msg, 265, 20, 10, BLACK);
}

void userKeysPressed() {
    // Piece user control
    if (IsKeyDown(KEY_LEFT)) 
    {
        writeMessageLogger("Left");
        if (position.y > LEN(O_BLOCK[0])) {
            int *flat_grid = (int *)GameGrid;
            int temp_it = flat_grid[0];

            // We will iterate the grid as a 1-D array.
            for (int i = 1; i < GRID_ROWS*GRID_COLUMNS; ++i)
                flat_grid[i-1] = flat_grid[i];

            flat_grid[GRID_ROWS*GRID_COLUMNS-1] = temp_it;

            // Update Y position.
            position.y -= 1;
        }
    }
    if (IsKeyDown(KEY_RIGHT)) 
    {
        writeMessageLogger("Right");
        // If position Y is smaller than the total number of columns
        if (position.y < LEN(GameGrid[0])) {
            int *flat_grid = (int *)GameGrid;
            int temp_it = flat_grid[GRID_ROWS*GRID_COLUMNS - 1];

            // We will iterate the grid as a 1-D array.
            for (int i = GRID_ROWS*GRID_COLUMNS - 2; i >= 0; --i) 
                flat_grid[i+1] = flat_grid[i];

            flat_grid[0] = temp_it;

            // Update Y position.
            position.y += 1;
        }
    }

    if (IsKeyDown(KEY_DOWN)) 
    {
        writeMessageLogger("DOWN");
        game_velocity_ms = 50;
    } 
    else 
    {
        game_velocity_ms = 500;
    }

    
}

int main(void) 
{
    // Window initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ray Tetris");

    SetTargetFPS(60); 

    pthread_t tid;
    pthread_create(&tid, NULL, &threadproc, NULL);
    
    initGameGrid();
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(SKYBLUE);

            userKeysPressed();

            paintGameGrid();
        EndDrawing();
    }
    CloseWindow();

    return 0;

}