#include <stdio.h>
#include "raylib.h"

int velocity_x = 5;
int velocity_y = 5;

void drawPacMan(Texture2D player, int x, int y);
void updatePosition(int *x, int *y);

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int frameRate = 60;
    int frameCounter = 0;

    int x = 400;
    int y = 400;

    InitWindow(screenWidth, screenHeight, "PacMan");
    SetTargetFPS(frameRate);

    Texture2D playerNarrow = LoadTexture("pacman.png");
    Texture2D playerWide = LoadTexture("pacman2.png");
    Texture2D player = playerNarrow;

    while (!WindowShouldClose() && !IsKeyDown(KEY_ESCAPE)) {

        if (frameCounter == frameRate / 4 ) {
            player = playerWide;
        }
        if (frameCounter == frameRate / 2 ) {
            player = playerNarrow;
            frameCounter = 0;
        }

        updatePosition(&x,&y);

        BeginDrawing();
        ClearBackground(BLACK);
        drawPacMan(player, x, y);
        EndDrawing();

        frameCounter++;
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
