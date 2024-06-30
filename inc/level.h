#ifndef LEVEL_H
#define LEVEL_H

#include <raylib.h>

#define GRID_SIZE 32
#define LEVEL_WIDTH 25
#define LEVEL_HEIGHT 19
typedef struct 
{
    int data[LEVEL_HEIGHT][LEVEL_WIDTH];
}level;

void drawGrid();
void drawLevel(level *level);
void saveLevel(level *level, const char *filename);
void loadLevel(level *level, const char *filename);

#endif