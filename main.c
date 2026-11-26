#include "raylib.h"
#include "Spring_mass/data.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
int main(void)
{
    InitWindow(800, 450, "Physics Engine");
    SetTargetFPS(60);
    float t = 0.2f;
    float m = 2.0f; float k =1.0f;
    float x0 = 1.0f;
    float v0 = -1.5f;
    char str[10][10];  
    float x_e = 2.0f;
    while (!WindowShouldClose())
    {
        t += GetFrameTime();
        float A = sqrtf(powf(x0,2) + powf(v0,2)*m/k);// amplitude 
        float w = sqrt(k/m);
        float phi = atan2(v0,w*x0);
        float x = (x_e+ A*cos(w*t - phi));
        float v = -A*w*sin(w*t-phi);
        Vector2 rec_center = {origin.x + x*100+size.x/2,origin.y - size.y/2};
        Rectangle rec ={rec_center.x-size.x/2,rec_center.y-size.y/2,50,50};
        float thick = x/A;
        int num_points = 14;
        float spring_length = rec.x - origin.x;
        float step = spring_length / (num_points - 1);
        float mid_y = origin.y - size.y / 2.0f;
        float coil_height = size.y * 0.4f;
        spring[0] = (Vector2){ origin.x, mid_y };
        for (int i = 1; i < num_points - 1; i++){
            float direction = (i % 2 == 1) ? -1.0f : 1.0f;
            spring[i].x = origin.x + i * step;
            spring[i].y = mid_y + direction * coil_height;
        }
        spring[num_points - 1] = (Vector2){ rec.x, origin.y - size.y/2 };
        float line_thick = 2.0;
        snprintf(str[0], sizeof(str), "%0.2f", x0);
        snprintf(str[1], sizeof(str), "%0.2f", v0);
        snprintf(str[2], sizeof(str), "%0.2f", x_e);
        snprintf(str[3], sizeof(str), "%0.2f", x);
        snprintf(str[4], sizeof(str), "%0.2f", v);
        snprintf(str[5], sizeof(str), "%0.2f", m);
        snprintf(str[6], sizeof(str), "%0.2f", k);



        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLineEx(wall_start,wall_end,2.0,BLACK);
            DrawLineEx(origin,ground_end,2.0,BLACK);
              for (int i = 0; i < num_points - 1; i++) {
                DrawLineEx(spring[i], spring[i + 1], line_thick, BROWN);
            }            DrawRectangleRec(rec,RED);
            GuiSlider(sliders[0],"Initial Position",NULL,&x0,0.00f,3.00f);
            GuiSlider(sliders[1],"Initial Velocity",NULL,&v0,-1.0f,1.0f);
            GuiSlider(sliders[2],"Equilibrium Position",NULL,&x_e,0.50f,2.00f);
            GuiSlider(sliders[3],"Mass",NULL,&m,0.50f,2.00f);
            GuiSlider(sliders[4],"Spring Constant",NULL,&k,0.50f,2.00f);
            DrawText("Spring-Mass System",300,400,20,PURPLE);
            DrawText(str[0],704,100,10,BLACK);
            DrawText(str[1],704,112,10,BLACK);
            DrawText(str[2],704,124,10,BLACK);
            DrawText(str[3],704,136,10,BLACK);
            DrawText(str[4],615,136,10,BLACK);
            DrawText(str[5],704,88,10,BLACK);
            DrawText(str[6],704,76,10,BLACK);
            DrawText("Position X =",640,136,10,BLUE);
            DrawText("Velocity V =",540,136,10,BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}