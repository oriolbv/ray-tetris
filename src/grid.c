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


int GameGrid[GRID_ROWS][GRID_COLUMNS];
bool activePiece = false;
bool gas = false;
void initGameGrid() 
{
    // Initialization of the grid with zero's content
    memset(GameGrid, 0, sizeof GameGrid);
}

void paintGameGrid() 
{
    // Piece user control
    if (IsKeyDown(KEY_LEFT)) 
    {
        
        writeMessageLogger("Left");
        if (position.y > LEN(O_BLOCK[0])) {
            int *flat_grid = (int *)GameGrid;
            int temp_it = flat_grid[0];

            // We will iterate the grid as a 1-D array.
            for ( size_t i = 1; i < GRID_ROWS*GRID_COLUMNS; ++i )
                flat_grid[i-1] = flat_grid[i];

            flat_grid[GRID_ROWS*GRID_COLUMNS-1] = temp_it;

            // Update Y position.
            position.y -= 1;
        }
        


    }
    if (IsKeyDown(KEY_RIGHT)) 
    {
            position.y += 1;
            writeMessageLogger("Right");
    }

    // Generation of the game grid
    for(int i = 0; i < GRID_ROWS; ++i)
    {
        for(int j = 0; j < GRID_COLUMNS; ++j) 
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
        int center_pos = (GRID_COLUMNS / 2) - 2;
        for(int i = 1; i < LEN(O_BLOCK) + 1; ++i)
        {
            for(int j = center_pos; j < center_pos + LEN(O_BLOCK[0]); ++j)
            {
                GameGrid[i][j] = O_BLOCK[i - 1][j - center_pos];
            }
        }

        // Store the actual position of the piece down-right corner.
        position.x = LEN(O_BLOCK);
        position.y = center_pos + LEN(O_BLOCK[0]);

        activePiece = true;

    }
    else 
    {
        // There is a piece falling and we need to update its position.
        for(int i = sizeof(GameGrid)/sizeof(*GameGrid) - 1; i--; ) {
            for(int z = 0; z < sizeof(*GameGrid)/sizeof(**GameGrid); z++) {
                GameGrid[i+1][z] = GameGrid[i][z];
            }
        }

        // Store the actual position of the piece upper-left corner.
        position.x = position.x + 1;

        activePiece = true;
    }
}