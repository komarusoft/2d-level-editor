#include "../inc/level.h"
#include "../inc/toolchain.h"
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
            if(level->blocks[y][x].isBlockExist){
                DrawRectangle(x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE, GRID_SIZE, level->blocks[y][x].color);
            }
            level->blocks[y][x].coordinates.x = x;
            level->blocks[y][x].coordinates.y = y;            
        }
    }
}

void saveLevel(level *level, const char *filename) {
    // cJSON *json
    cJSON *jsonArray = cJSON_CreateArray();
    
    for (int x = 0; x < LEVEL_WIDTH; x++) {
        for (int y = 0; y < LEVEL_HEIGHT; y++) {
            cJSON *jsonBlock = serializeLevelBlockToJson(&level->blocks[y][x]);
            cJSON_AddItemToArray(jsonArray, jsonBlock);
        }
    }

    char* jsonString = cJSON_Print(jsonArray);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error");
        cJSON_Delete(jsonArray);
        free(jsonString);
        return;
    }

    fprintf(file, "%s", jsonString);

    fclose(file);
    cJSON_Delete(jsonArray);
    free(jsonString);

    TraceLog(LOG_INFO, "Level saved successfully");
}