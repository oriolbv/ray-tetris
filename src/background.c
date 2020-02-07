#include "raylib.h"
#include "const.h"


void generateGameGrid() {
    // Generation of the game grid
    for(int i = 0; i < GRID_V_CELLS_NUMBER; ++i)
    {
        for(int j = 0; j < GRID_H_CELLS_NUMBER; ++j) {
            DrawRectangleLines((j*GRID_CELL_WIDTH) + MARGIN_LEFT, (i*GRID_CELL_HEIGHT) + MARGIN_TOP,
                                    GRID_CELL_WIDTH, GRID_CELL_HEIGHT, BLACK);
        }
    }
}