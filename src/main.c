#include "../inc/level.h"
#include "../inc/raygui.h"
#include <raylib.h>

int main(void) {
    const int screenWidth = 800;  // Ширина окна по умолчанию
    const int screenHeight = 600;  // Высота окна по умолчанию

    InitWindow(screenWidth, screenHeight, "Level Editor");

    level lvl = { 0 };
    Vector2 mousePosition;
    int selectedTile = 1;
    bool eraseMode = false;
    
    // Камера для управления прокруткой
    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ 0, 0 };
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) camera.target.x += 5;
        if (IsKeyDown(KEY_LEFT)) camera.target.x -= 5;
        if (IsKeyDown(KEY_UP)) camera.target.y -= 5;
        if (IsKeyDown(KEY_DOWN)) camera.target.y += 5;

        mousePosition = GetScreenToWorld2D(GetMousePosition(), camera);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int x = (mousePosition.x - 120) / GRID_SIZE;
            int y = mousePosition.y / GRID_SIZE;
            if (x >= 0 && x < LEVEL_WIDTH && y < LEVEL_HEIGHT) {
                lvl.data[y][x] = eraseMode ? 0 : selectedTile;
            }
        }

        // if (IsKeyPressed(KEY_S)) {
        //     saveLevel(&lvl, "levels/level1.lvl");
        // }

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

            DrawToolbar(&selectedTile, &eraseMode);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}