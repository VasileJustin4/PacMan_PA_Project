#include <stdio.h>
#include "raylib.h"

int velocity_x = 6;
int velocity_y = 6;

void drawPacMan(Texture2D player, int x, int y);
void updatePosition(int *x, int *y);

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;

    int x = 400;
    int y = 400;

    InitWindow(screenWidth, screenHeight, "PacMan");
    SetTargetFPS(60);

    Texture2D playerNarrow = LoadTexture("pacman.png");
    Texture2D playerWide = LoadTexture("pacman2.png");

    while (!WindowShouldClose() && !IsKeyDown(KEY_ESCAPE)) {

        updatePosition(&x,&y);

        BeginDrawing();
        ClearBackground(BLACK);
        drawPacMan(playerNarrow, x, y);
        drawPacMan(playerWide, x, y);
        EndDrawing();
    }

    UnloadTexture(playerNarrow);
    UnloadTexture(playerWide);
    CloseWindow();

    return 0;
}

void drawPacMan(Texture2D player, int x, int y) {
    DrawTextureV(player, (Vector2){x, y}, WHITE);
}

void updatePosition(int *x, int *y) {
    if (IsKeyDown(KEY_UP)) {
        *y -= velocity_y;
    }
    if (IsKeyDown(KEY_DOWN)) {
        *y += velocity_y;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        *x += velocity_x;
    }
    if (IsKeyDown(KEY_LEFT)) {
        *x -= velocity_x;
    }
}
