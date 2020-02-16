#include "raylib.h"
#include "const.h"
#include "grid.c"
#include <pthread.h>
#include <unistd.h>

void *threadproc(void *arg)
{
    bool done = false;
    while(!done)
    {
        sleep(GAME_VELOCITY);
        updateGameGrid();
    }
    return 0;
}

void writeMessageLogger(char *msg) {
    DrawText(msg, 265, 20, 10, BLACK);
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
        
            paintGameGrid();
        EndDrawing();
    }

    CloseWindow();

    return 0;

}