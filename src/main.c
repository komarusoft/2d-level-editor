#include "../inc/level.h"
#include "../inc/raygui.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

int main(void) {
    const int screenWidth = 800; 
    const int screenHeight = 600;  
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);  
    InitWindow(screenWidth, screenHeight, "Level Editor");

    level lvl = { 0 };
    Vector2 mousePosition;
    int selectedTile = 1;
    bool eraseMode = false;
    
    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ 0, 0 };
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsWindowResized()) {
            int newScreenWidth = GetScreenWidth();
            int newScreenHeight = GetScreenHeight();
            SetWindowSize(newScreenWidth, newScreenHeight);
            camera.offset = (Vector2){ newScreenWidth/2.0f, newScreenHeight/2.0f };
        }

        if (IsKeyDown(KEY_RIGHT)) camera.target.x += 5;
        if (IsKeyDown(KEY_LEFT)) camera.target.x -= 5;
        if (IsKeyDown(KEY_UP)) camera.target.y -= 5;
        if (IsKeyDown(KEY_DOWN)) camera.target.y += 5;

        float wheel = GetMouseWheelMove();
        if(wheel != 0){
            camera.zoom += wheel * 0.1f;
            if (camera.zoom < 0.1f) camera.zoom = 0.1f;
            if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        }

        //dragging middle mouse button 
        static Vector2 dragStart = { 0 };
        if(IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON)){
            dragStart = GetMousePosition();
        }
        if(IsMouseButtonDown(MOUSE_MIDDLE_BUTTON)){
            Vector2 dragEnd = GetMousePosition();
            Vector2 dragDelta = Vector2Subtract(dragStart, dragEnd);

            camera.target = Vector2Add(camera.target, Vector2Scale(dragDelta, 1.0f / camera.zoom));
            dragStart = dragEnd;
        }

        mousePosition = GetScreenToWorld2D(GetMousePosition(), camera);

        //Place item to level grid
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int x = mousePosition.x / GRID_SIZE;
            int y = mousePosition.y / GRID_SIZE;
            if (x >= 0 && x < LEVEL_WIDTH && y < LEVEL_HEIGHT) {
                lvl.data[y][x] = eraseMode ? 0 : selectedTile;
            }
        }

        if (IsKeyPressed(KEY_S)) {
            // saveLevel(&lvl, "lvl.json");
        }

        // if (IsKeyPressed(KEY_L)) {
        //     loadLevel(&lvl, "levels/level1.lvl");
        // }

        if (IsKeyPressed(KEY_C)) {
            for (int y = 0; y < LEVEL_HEIGHT; y++) {
                for (int x = 0; x < LEVEL_WIDTH; x++) {
                    lvl.data[y][x] = 0;
                }
            }
        }

        BeginDrawing();
            ClearBackground(DARKGRAY);

            BeginMode2D(camera);
                drawGrid();
                drawLevel(&lvl);
            EndMode2D();

            DrawToolbar(&selectedTile, &eraseMode, &mousePosition);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}