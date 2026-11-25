#include "raylib.h"
#include "Spring_mass/data.h"
#include <math.h>
int main(void)
{
    InitWindow(800, 450, "Physics Engine");
    int frame = 0;
    SetTargetFPS(60);
    float t = 0.0f;
    while (!WindowShouldClose())
    {
        t += GetFrameTime();
        float m = 2.0f; float k = 0.2f;
        float x0 = 1.0f; float v0 = -1.5f; // Initial pos and initial velocity
        float A = (powf(x0,2) + powf(v0,2)*m/k);// amplitude 
        float w = sqrt(k/m);
        float phi = atan2(v0,w*x0);
        float x = A*(1+ cos(w*t - phi));
        float v = -A*w*sin(w*t-phi);

        Vector2 rec_center = {origin.x + x*10+size.x/2,origin.y - size.y/2};
        Rectangle rec ={rec_center.x-size.x/2,rec_center.y-size.y/2,50,50};
        Vector2 spring_start = {origin.x, origin.y -size.y/2};
        float line_thick = 2.0;
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLineEx(wall_start,wall_end,2.0,BLACK);
            DrawLineEx(origin,ground_end,2.0,BLACK);
            DrawLineEx(spring_start,rec_center,line_thick,BROWN);
            DrawRectangleRec(rec,RED);
        EndDrawing();
        frame++;
    }

    CloseWindow();

    return 0;
}