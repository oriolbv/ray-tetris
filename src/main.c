#include "raylib.h"
#include "const.h"
#include "grid.c"
#include <pthread.h>
#include <sys/time.h>

void *threadproc(void *arg)
{
    bool done = false;
    while(!done)
    {
        sleep(2);
        updateGameGrid();
    }
    return 0;
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