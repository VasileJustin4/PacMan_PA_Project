#include <stdio.h>
#include "raylib.h"

int main(void) {

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "PacMan");

    SetTargetFPS(60);

    while (!WindowShouldClose() || IsKeyDown(KEY_ESCAPE)) {

        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}