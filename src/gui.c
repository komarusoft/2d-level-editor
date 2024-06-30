#define RAYGUI_IMPLEMENTATION
#include "../inc/raygui.h"

//TODO: дописати
void DrawToolbar(int *selectedTile, bool *eraseMode) {
    const int toolbarWidth = 120;
    const int screenHeight = GetScreenHeight();

    DrawRectangle(0, 0, toolbarWidth, screenHeight, DARKGRAY);

    DrawText("Tools", 10, 10, 10, WHITE);

    bool block1Checked = (*selectedTile == 1);
    bool block2Checked = (*selectedTile == 2);

    if (GuiCheckBox((Rectangle){ 10, 30, 20, 20 }, "Block 1", &block1Checked)) {
        *selectedTile = 1;
        *eraseMode = false;
    }
    if (GuiCheckBox((Rectangle){ 10, 60, 20, 20 }, "Block 2", &block2Checked)) {
        *selectedTile = 2;
        *eraseMode = false;
    }
    if (GuiCheckBox((Rectangle){ 10, 90, 20, 20 }, "Erase", eraseMode)) {
        *eraseMode = true;
    }
}

