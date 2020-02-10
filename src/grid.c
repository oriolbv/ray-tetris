#include "raylib.h"
#include "const.h"
#include "pieces.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>


struct Position 
{ 
   int x, y; 
} position;


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
        // All pieces are in the ground.
        // Calculate the position where the new piece will appear.
        int center_pos = (GRID_H_CELLS_NUMBER / 2) - 2;
        for(int i = 0; i < LEN(O_BLOCK); ++i)
        {
            for(int j = center_pos; j < center_pos + LEN(O_BLOCK[0]); ++j)
            {
                GameGrid[i][j] = O_BLOCK[i][j - center_pos];
            }
        }

        // Store the actual position of the piece down-right corner.
        position.x = 0 + LEN(O_BLOCK);
        position.y = center_pos + LEN(O_BLOCK[0]);

        activePiece = true;

    }
    else 
    {
        // There is a piece falling and we need to update its position.
        for(int i = LEN(O_BLOCK); i >= 0; --i)
        {
            for(int j = LEN(O_BLOCK[0]); j >= 0; --j)
            {
                if ((i <= position.x) && (j <= position.y)) 
                {
                    GameGrid[i][j] = 0;
                    GameGrid[i+1][j] = O_BLOCK[i][j - position.y];
                }
                else 
                {
                    GameGrid[i][j] = 1;
                }
                
            }
        }

        // Store the actual position of the piece upper-left corner.
        position.x = position.x + 1;
        // position.y = position.y;

        activePiece = true;
        // GameGrid[position.x][4] = 1;
    }
}