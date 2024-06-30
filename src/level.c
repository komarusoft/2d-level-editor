#include "../inc/level.h"
//TODO: add load and draw lvl
//TODO: add save lvl to file
void drawGrid(){
    for(int i = 0; i <= LEVEL_WIDTH; i++) 
        DrawLine(i * GRID_SIZE, 0, i * GRID_SIZE, LEVEL_HEIGHT * GRID_SIZE, WHITE);
    
    for(int i = 0; i <= LEVEL_HEIGHT; i++)
        DrawLine(0, i * GRID_SIZE, LEVEL_WIDTH * GRID_SIZE, i * GRID_SIZE, WHITE);
}

void drawLevel(level *level){
    for(int y = 0; y < LEVEL_HEIGHT; y++){
        for(int x = 0; x < LEVEL_WIDTH; x++){
            if(level->data[y][x] == 1){
                DrawRectangle(x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE, GRID_SIZE, RED);
            }
        }
    }
}