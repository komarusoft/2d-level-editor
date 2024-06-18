#include "../inc/level.h"

int main(){
    SetTargetFPS(60);
    int isGridEnable = 1;
    const int screenWidth = LEVEL_WIDTH * GRID_SIZE;
    const int screenHeight = LEVEL_HEIGHT * GRID_SIZE;
    InitWindow(screenWidth, screenHeight, "2d-level-editor");

    level lvl = { 0 };
    Vector2 mousePosition;
    int selectedTile = 1;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(GRAY);
            
            if(isGridEnable == 1)
                drawGrid();

            drawLevel(&lvl);
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
}