#include <simple2d.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//constants to use for ball direction and boolean
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1
#define FALSE 0
#define TRUE 1

const int screen_width = 640;
const int screen_height = 480;

typedef struct {
	float x;
	float y;
}velocity;

typedef struct { //ball struct template
    int r;
    int speed;
    int y;
    int x;
    int dir_y;
    int dir_x;
    bool hit_x;
    bool hit_y;
    velocity v;
		int angle;
    S2D_Sound *snd;
}ball;

ball balls[10];


void update() {
		int i;
    for (i = 0; i < 10; i++){
        if(balls[i].x > (screen_width-balls[i].r)){ //hit right side
            balls[i].dir_x = LEFT; //bounce back by going left
            balls[i].hit_x = TRUE;
        }    else if(balls[i].x < balls[i].r) { //hit left side
                balls[i].dir_x = RIGHT; //bounce back right
                balls[i].hit_x = TRUE;
                } else {balls[i].hit_x = FALSE;}

        balls[i].x = balls[i].x + (balls[i].speed * balls[i].dir_x); //position ball x pos
        if(balls[i].y > (screen_height-balls[i].r)){ //hit bottom
            balls[i].dir_y = UP; //bounce up
            balls[i].hit_y = TRUE;
        }    else if(balls[i].y < balls[i].r){ //hit top
                balls[i].dir_y = DOWN; //bounce down
                balls[i].hit_y = TRUE;
                } else {balls[i].hit_y = FALSE;}

        balls[i].y += balls[i].speed * balls[i].dir_y; //position ball y pos
    }
}

void render() {
    int i;
    for (i = 0; i < 10; i++){
        S2D_DrawCircle(balls[i].x, balls[i].y, balls[i].r, 50, 0, 0, 1, 1);

        if(balls[i].hit_x||balls[i].hit_y){
            S2D_PlaySound(balls[i].snd);//play bounce sound
        }
    }
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 10; i++){
        balls[i].r = rand() % 50;
        balls[i].x = rand() % (screen_width - balls[i].r);
        balls[i].y = rand() % (screen_height - balls[i].r);
        balls[i].speed = 5;
        balls[i].dir_x = 1;
        balls[i].dir_y = 1;
        balls[i].hit_x = FALSE;
        balls[i].hit_y = FALSE;
        balls[i].snd = S2D_CreateSound("bounce.wav");
    }

    S2D_Window *window = S2D_CreateWindow(
        "Hello Triangle", screen_width, screen_height, update, render, 0);//init the window
    S2D_Show(window);//show the window
    S2D_FreeSound(balls[0].snd); //free sound from mem
  return 0;
}
