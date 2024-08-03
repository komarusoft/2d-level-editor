#include "../inc/toolchain.h"

cJSON* serializeLevelBlockToJson(const block* blk){
    cJSON *jsonBlock = cJSON_CreateObject();

    cJSON *coordinates = cJSON_CreateObject();
    cJSON_AddNumberToObject(coordinates, "x", blk->coordinates.x);
    cJSON_AddNumberToObject(coordinates, "y", blk->coordinates.y);
    cJSON_AddItemToObject(jsonBlock, "coordinates", coordinates);

    cJSON_AddBoolToObject(jsonBlock, "isBlockExist", blk->isBlockExist);
    if(blk->texturePath != NULL){
        cJSON_AddStringToObject(jsonBlock, "texturePath", blk->texturePath);
    } else {
        cJSON_AddNullToObject(jsonBlock, "texturePath");
    }

     if(blk->texturePath == NULL){
        cJSON *color = cJSON_CreateObject();
        cJSON_AddNumberToObject(color, "r", blk->color.r);
        cJSON_AddNumberToObject(color, "g", blk->color.g);
        cJSON_AddNumberToObject(color, "b", blk->color.b);
        cJSON_AddNumberToObject(color, "a", blk->color.a);

        cJSON_AddItemToObject(jsonBlock, "color", color);

    } else {
        cJSON_AddNullToObject(jsonBlock, "color");
    }

    cJSON_AddBoolToObject(jsonBlock, "isBlockHaveCollider", blk->isBlockHaveCollider);

    return jsonBlock;
}
