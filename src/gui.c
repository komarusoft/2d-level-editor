#define RAYGUI_IMPLEMENTATION
#include "../inc/raygui.h"

//TODO: дописати
void DrawToolbar(int *selectedTile, bool *eraseMode, Vector2 *mousePosition) {
    const int toolbarWidth = 120;
    const int screenHeight = GetScreenHeight();

    DrawRectangle(0, 0, toolbarWidth, screenHeight, DARKGRAY);

    DrawText("Tools", 10, 10, FONT_SIZE, WHITE);

    char mousePositionText[50];
    snprintf(mousePositionText, sizeof(mousePositionText), "X: %.1f, Y: %.1f", mousePosition->x, mousePosition->y);
    DrawText(mousePositionText, 10, screenHeight - 20, TEXT_SIZE, WHITE);
    
    bool blockChecked = (*selectedTile == 1);

    //TODO: нужно пофиксить, сделать белый цвет шрифта, и размер шрифта увеличить
    if (GuiCheckBox((Rectangle){ 10, 30, 20, 20 }, "Block", &blockChecked)) {
        *selectedTile = 1;
        *eraseMode = false;
    }
    if (GuiCheckBox((Rectangle){ 10, 60, 20, 20 }, "Erase", eraseMode)) {
        *eraseMode = true;
        *selectedTile = 0;
    }
}

