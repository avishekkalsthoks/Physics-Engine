#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "Spring_mass/raygui.h"
#undef RAYGUI_IMPLEMENTATION
#include "Spring_mass/spring.h"


int main(void)
{
    InitWindow(800, 450, "Physics Engine");
    SetTargetFPS(60);
    float t;
    while (!WindowShouldClose())
    {
        t += GetFrameTime();
        BeginDrawing();
           Spring(t);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}