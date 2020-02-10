#include "raylib.h"
#include "const.h"
#include <stdio.h>
#include <string.h>


int GameGrid[GRID_V_CELLS_NUMBER][GRID_H_CELLS_NUMBER];
bool activePiece = false;

void initGameGrid() 
{
    // Initialization of the grid with zero's content
    memset(GameGrid, 0, sizeof GameGrid);
}

void paintGameGrid() 
{
    // Generation of the game grid
    for(int i = 0; i < GRID_V_CELLS_NUMBER; ++i)
    {
        for(int j = 0; j < GRID_H_CELLS_NUMBER; ++j) 
        {
            if (GameGrid[i][j] != 0) 
            {
                // If there is a block of any piece in the actual cell, we have to paint it with
                // the piece color.
                DrawRectangle((j*GRID_CELL_WIDTH) + MARGIN_LEFT, (i*GRID_CELL_HEIGHT) + MARGIN_TOP,
                                GRID_CELL_WIDTH, GRID_CELL_HEIGHT, YELLOW);
            }
            else 
            {
                // If there is not a block, we just paint an empty cell
                DrawRectangleLines((j*GRID_CELL_WIDTH) + MARGIN_LEFT, (i*GRID_CELL_HEIGHT) + MARGIN_TOP,
                    GRID_CELL_WIDTH, GRID_CELL_HEIGHT, BLACK);
            }
        }
    }
}

void updateGameGrid() 
{
    if (!activePiece) 
    {
        // All pieces are in the ground
    }
    else 
    {
        // There is a piece falling
    }

    GameGrid[3][3] = 1;
}