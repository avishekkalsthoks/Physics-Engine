#ifndef SPRING_MASS_DATA_H
#define SPRING_MASS_DATA_H
#include "raylib.h"
#include "raygui.h"
#include "data.h"
#include <math.h>
#include <stdio.h>
Vector2 origin ={100,300};
Vector2 wall_start ={100,325};
Vector2 wall_end = {100,100};
Vector2 ground_end = {700,300};
Vector2 size = {50,50};
Rectangle sliders[5] ={{600,100,100,10},{600,112,100,10},{600,124,100,10},{600,88,100,10},{600,76,100,10}};
Vector2 spring[20];
void Spring(float t);
#endif