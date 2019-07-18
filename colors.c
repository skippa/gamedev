#include <simple2d.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float r = 1;
float g = 1;
float b = 1;

void render() {
    S2D_DrawCircle(300, 400, 50, 50, r, g, b, 1);
}

void main() {
    r = 0.980000;//((rand() % 99)+1)/100;
    g = 0.120000;//((rand() % 99)+1)/100;
    b = 0.680000;//((rand() % 99)+1)/100;
	S2D_Window *window = S2D_CreateWindow(
        "Hello Triangle", 640, 480, NULL, render, 0);//init the window
    S2D_Show(window);//show the window

}
