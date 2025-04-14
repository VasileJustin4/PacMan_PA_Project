#include <stdio.h>
#include "raylib.h"

typedef enum Direction {
    IDLE,
    UP,
    DOWN,
    RIGHT,
    LEFT
} DIRECTION;

int velocity_x = 5;
int velocity_y = 5;

void drawPacMan(Texture2D player, int x, int y, DIRECTION direction);
void updatePosition(int *x, int *y, DIRECTION *direction);

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int frameRate = 60;
    int frameCounter = 0;

    int x = 400;
    int y = 400;

    InitWindow(screenWidth, screenHeight, "PacMan");
    SetTargetFPS(frameRate);

    DIRECTION direction = IDLE;

    Texture2D playerNarrow = LoadTexture("pacman.png");
    Texture2D playerWide = LoadTexture("pacman2.png");
    Texture2D player = playerNarrow;

    while (!WindowShouldClose() && !IsKeyDown(KEY_ESCAPE)) {
        if (frameCounter == frameRate / 4) {
            player = playerWide;
        }
        if (frameCounter == frameRate / 2) {
            player = playerNarrow;
            frameCounter = 0;
        }

        updatePosition(&x, &y, &direction);

        BeginDrawing();
        ClearBackground(BLACK);
        drawPacMan(player, x, y, direction);
        EndDrawing();

        frameCounter++;
    }

    UnloadTexture(playerNarrow);
    UnloadTexture(playerWide);
    CloseWindow();

    return 0;
}

void drawPacMan(Texture2D player, int x, int y, DIRECTION direction) {
    Rectangle sourceRec = {0.0f, 0.0f, (float)player.width, (float)player.height};
    Rectangle destRec = {x, y, (float)player.width, (float)player.height};
    Vector2 origin = {(float)player.width / 2, (float)player.height / 2};

    float rotation = 0.0f;
    switch (direction) {
        case RIGHT: rotation = 0.0f; break;
        case LEFT:  rotation = 180.0f; break;
        case UP:    rotation = -90.0f; break;
        case DOWN:  rotation = 90.0f; break;
        default: break;
    }

    DrawTexturePro(player, sourceRec, destRec, origin, rotation, WHITE);
}

void updatePosition(int *x, int *y, DIRECTION *direction) {
    if (IsKeyDown(KEY_UP)) {
        *y -= velocity_y;
        *direction = UP;
    }
    else if (IsKeyDown(KEY_DOWN)) {
        *y += velocity_y;
        *direction = DOWN;
    }
    else if (IsKeyDown(KEY_RIGHT)) {
        *x += velocity_x;
        *direction = RIGHT;
    }
    else if (IsKeyDown(KEY_LEFT)) {
        *x -= velocity_x;
        *direction = LEFT;
    }
}