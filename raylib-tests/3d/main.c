#include "raylib.h"

int main() {
    InitWindow(800, 600, "test 3d");
    Camera3D camera = {0};
    camera.fovy = 90;
    camera.position = (Vector3){0.0f, 0.0f, 0.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};

    while(!WindowShouldClose()) {
        BeginDrawing();
        BeginMode3D(camera);

            ClearBackground(SKYBLUE);

        EndMode3D();
        EndDrawing();
    }
    
    CloseWindow();
}