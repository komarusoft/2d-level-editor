#ifndef LEVEL_H
#define LEVEL_H

#include "../cJSON/cJSON.h"
#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>

#define GRID_SIZE 32
#define LEVEL_WIDTH 25
#define LEVEL_HEIGHT 19

typedef struct{
    int x;
    int y;
}coordinates;

typedef struct 
{
    coordinates coordinates;
    bool isBlockExist;
    char* texturePath;
    Color color; // Can be null if block have texture
    bool isBlockHaveCollider;
} block;

typedef struct 
{
    // add it later to set different size to different level
    // int LEVEL_HEIGHT
    // int LEVEL_WIDTH

    block blocks[LEVEL_HEIGHT][LEVEL_WIDTH];
}level;


void drawGrid();
void drawLevel(level *level);
void saveLevel(level *level, const char *filename);
void loadLevel(level *level, const char *filename);

#endif