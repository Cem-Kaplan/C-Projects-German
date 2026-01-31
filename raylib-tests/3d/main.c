#include "raylib.h"
#include "raymath.h"
#include <math.h>

#define MAP_SIZE    128
#define SCALE       1.0f
#define HEIGHT      10.0f

float heightmap[MAP_SIZE][MAP_SIZE];

float Noise2D(int x, int z) {
    int n = x + z * 57;
    n = (n << 13) ^ n;
    return (1.0f - ((n * (n * n * 15731 + 789221) + 1376312589)
        & 0x7fffffff) / 1073741824.0f);
}

void GenerateHeightmap() {
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int z = 0; z < MAP_SIZE; z++) {

            float nx = (float)x / MAP_SIZE;
            float nz = (float)z / MAP_SIZE;

            float h = 0.0f;
            h += Noise2D(x, z) * 0.6f;
            h += Noise2D(x * 2, z * 2) * 0.3f;
            h += Noise2D(x * 4, z * 4) * 0.1f;

            heightmap[x][z] = (h * 0.5 + 0.5f) * HEIGHT;
        }
    }
}

Mesh GenerateLowPolyTerrain() {
    Mesh mesh = { 0 };

    int quads = (MAP_SIZE - 1) * (MAP_SIZE - 1);
    int triangles = quads * 2;

    mesh.vertexCount = triangles * 3;
    mesh.triangleCount = triangles;

    mesh.vertices   = MemAlloc(mesh.vertexCount * 3 * sizeof(float));
    mesh.normals    = MemAlloc(mesh.vertexCount * 3 * sizeof(float));
    mesh.colors     = MemAlloc(mesh.vertexCount * 4 * sizeof(unsigned char));

    int v = 0;

    for (int x = 0; x < MAP_SIZE - 1; x++) {
        for (int z = 0; z < MAP_SIZE - 1; z++) {

            Vector3 p1 = { x * SCALE,       heightmap[x][z],        z * SCALE };
            Vector3 p2 = { (x+1) * SCALE,   heightmap[x+1][z],      z * SCALE };
            Vector3 p3 = { x * SCALE,       heightmap[x][z+1],      (z+1) * SCALE };
            Vector3 p4 = { (x+1) * SCALE,   heightmap[x+1][z+1],    (z+1) * SCALE };
        
            Vector3 n1 = Vector3Normalize(
                Vector3CrossProduct(
                    Vector3Subtract(p2, p1),
                    Vector3Subtract(p3, p1)
                )
            );

            Vector3 n2 = Vector3Normalize(
                Vector3CrossProduct(
                    Vector3Subtract(p4, p2),
                    Vector3Subtract(p3, p2)
                )
            );

            Color color = GREEN;
            if (p1.y > HEIGHT * 0.6f) color = GRAY;
            if (p1.y > HEIGHT * 0.8f) color = RAYWHITE;

            Vector3 t1[3] = { p1, p2, p3};
            Vector3 t2[3] = { p2, p4, p3};
            
            for (int i = 0; i < 3; i++) {
                mesh.vertices[v*3+0] = t1[i].x;
                mesh.vertices[v*3+1] = t1[i].y;
                mesh.vertices[v*3+2] = t1[i].z;

                mesh.normals[v*3+0] = n1.x;
                mesh.normals[v*3+1] = n1.y;
                mesh.normals[v*3+2] = n1.z;

                mesh.colors[v*4+0] = color.r;
                mesh.colors[v*4+1] = color.g;
                mesh.colors[v*4+2] = color.b;
                mesh.colors[v*4+3] = 255;
                v++;
            }

            for (int i = 0; i < 3; i++) {
                mesh.vertices[v*3+0] = t2[i].x;
                mesh.vertices[v*3+1] = t2[i].y;
                mesh.vertices[v*3+2] = t2[i].z;
                
                mesh.normals[v*3+0] = n2.x;
                mesh.normals[v*3+1] = n2.y;
                mesh.normals[v*3+2] = n2.z;

                mesh.colors[v*4+0] = color.r;
                mesh.colors[v*4+1] = color.g;
                mesh.colors[v*4+2] = color.b;
                mesh.colors[v*4+3] = 255;
                v++;
            }
        }
    }
    UploadMesh(&mesh, false);
    return mesh;
}


int main() {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(800, 600, "test 3d");
    SetTargetFPS(60);

    Camera3D camera = {0};
    camera.fovy = 60.0f;
    camera.position = (Vector3){40.0f, 25.0f, 0.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.projection = CAMERA_PERSPECTIVE;

    DisableCursor();

    GenerateHeightmap();
    Model terrain = LoadModelFromMesh(GenerateLowPolyTerrain());


while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);

        BeginDrawing();
        ClearBackground(SKYBLUE);

        BeginMode3D(camera);
            DrawModel(terrain,
                (Vector3){ -MAP_SIZE/2, 0, -MAP_SIZE/2 },
                1.0f, WHITE);
        EndMode3D();

        DrawFPS(20, 20);
        DrawText("Low Poly Terrain (no voxels)", 20, 45, 20, DARKGRAY);
        EndDrawing();
    }

    UnloadModel(terrain);
    CloseWindow();
    return 0;
}