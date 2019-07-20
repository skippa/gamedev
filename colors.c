#include <simple2d.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float r;
float g;
float b;

void render() {
    S2D_DrawCircle(300, 400, 50, 50, r, g, b, 1);
}

void main(){
    r = ((rand() % 99)+1)/100;
    g = ((rand() % 99)+1)/100;
    b = ((rand() % 99)+1)/100;
	S2D_Window *window = S2D_CreateWindow(
        "Hello Triangle", 640, 480, NULL, render, 0);//init the window
    S2D_Show(window);//show the window

}
