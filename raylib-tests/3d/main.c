#include "raylib.h"
#include <math.h>
#include <stdlib.h>

#define TERRAIN_SIZE 50   // Größe des Terrains (TERRAIN_SIZE x TERRAIN_SIZE)
#define TILE_SIZE 1.0f    // Größe jeder Kachel
#define HEIGHT_SCALE 5.0f

// Funktion, um zufällige Höhen für das Low-Poly-Terrain zu erzeugen
float GetHeight(int x, int z) {
    float height = sinf(x * 0.3f) * cosf(z * 0.3f) * HEIGHT_SCALE;
    height += (float)(rand() % 100) / 100.0f; // zufällige Variation
    return height;
}

int main(void) {
    // Fenster initialisieren
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Low-Poly World Generator - Raylib 3D");

    // Kamera initialisieren
    Camera3D camera = { 0 };
    camera.position = (Vector3){25.0f, 15.0f, 50.0f}; // Kamera weiter weg und leicht schräg
    camera.target = (Vector3){25.0f, 0.0f, 25.0f};   // Blickpunkt auf Terrain    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Up-Vektor
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Terrain-Daten
    float terrain[TERRAIN_SIZE][TERRAIN_SIZE];
    for (int x = 0; x < TERRAIN_SIZE; x++) {
        for (int z = 0; z < TERRAIN_SIZE; z++) {
            terrain[x][z] = GetHeight(x, z);
        }
    }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE); // Kamera steuern

        BeginDrawing();
        ClearBackground(SKYBLUE);

        BeginMode3D(camera);

        // Low-Poly Terrain rendern
        for (int x = 0; x < TERRAIN_SIZE - 1; x++) {
            for (int z = 0; z < TERRAIN_SIZE - 1; z++) {
                // 4 Ecken eines Tiles
                Vector3 v0 = { x * TILE_SIZE, terrain[x][z], z * TILE_SIZE };
                Vector3 v1 = { (x+1) * TILE_SIZE, terrain[x+1][z], z * TILE_SIZE };
                Vector3 v2 = { x * TILE_SIZE, terrain[x][z+1], (z+1) * TILE_SIZE };
                Vector3 v3 = { (x+1) * TILE_SIZE, terrain[x+1][z+1], (z+1) * TILE_SIZE };

                // Zwei Dreiecke pro Tile (Low-Poly Stil)
                Color tileColor = (terrain[x][z] > HEIGHT_SCALE * 0.5f) ? GREEN : (terrain[x][z] > HEIGHT_SCALE * 0.2f ? BROWN : DARKBROWN);

                DrawTriangle3D(v0, v1, v2, tileColor);
                DrawTriangle3D(v2, v1, v3, tileColor);
            }
        }

        EndMode3D();

        DrawText("Use WASD + Mouse to move the camera", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
