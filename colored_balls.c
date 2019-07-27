#include <simple2d.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//constants to use for ball direction and boolean
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1
#define FALSE 0
#define TRUE 1
#define NUM_BALLS 30

#define torad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)

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
    float red;
    float green;
    float blue;
    velocity v;
    int angle;
    S2D_Sound *snd;
}ball;

ball balls[NUM_BALLS];


void update() {
    int i;
    for (i = 0; i < NUM_BALLS; i++){
        if(balls[i].x > (screen_width-balls[i].r)){ //hit right side
            balls[i].dir_x = LEFT; //bounce back by going left
            balls[i].hit_x = TRUE;
        }    else if(balls[i].x < balls[i].r) { //hit left side
                balls[i].dir_x = RIGHT; //bounce back right
                balls[i].hit_x = TRUE;
                } else {balls[i].hit_x = FALSE;}

        balls[i].x += (balls[i].speed * balls[i].dir_x * balls[i].v.x); //position ball x pos

        if(balls[i].y > (screen_height-balls[i].r)){ //hit bottom
            balls[i].dir_y = UP; //bounce up
            balls[i].hit_y = TRUE;
        }    else if(balls[i].y < balls[i].r){ //hit top
                balls[i].dir_y = DOWN; //bounce down
                balls[i].hit_y = TRUE;
                } else {balls[i].hit_y = FALSE;}

        balls[i].y += (balls[i].speed * balls[i].dir_y * balls[i].v.y); //position ball y pos
    }
}

void render() {
    int i;
    for (i = 0; i < NUM_BALLS; i++){
        S2D_DrawCircle(balls[i].x, balls[i].y, balls[i].r, 50, balls[i].red, balls[i].green, balls[i].blue, 1);

        if(balls[i].hit_x||balls[i].hit_y){
            //S2D_PlaySound(balls[i].snd);//play bounce sound
        }
    }
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_BALLS; i++){
        balls[i].r = (rand() % 30)+5;
        balls[i].x = rand() % (screen_width - balls[i].r);
        balls[i].y = rand() % (screen_height - balls[i].r);
        balls[i].speed = (rand() % 10)+5;
        balls[i].dir_x = (rand() % 2)+1;
        if(balls[i].dir_x == 2){
            balls[i].dir_x = RIGHT;
          }else balls[i].dir_x = LEFT;
        balls[i].dir_y = (rand() % 2)+1;
        if(balls[i].dir_y == 2){
            balls[i].dir_y = DOWN;
          }else balls[i].dir_y = UP;
        balls[i].hit_x = FALSE;
        balls[i].hit_y = FALSE;
        balls[i].red = (rand() % 99)+1;
        balls[i].red = balls[i].red/100;
        balls[i].green = (rand() % 99)+1;
        balls[i].green = balls[i].green / 100;
        balls[i].blue = (rand() % 99)+1;
        balls[i].blue = balls[i].blue / 100;
        balls[i].angle = (rand() % 90)+20;
        balls[i].v.x = 1;
        balls[i].v.y = tan(torad(balls[i].angle));
        balls[i].snd = S2D_CreateSound("bounce.wav");
    }
	S2D_Diagnostics(true);
    S2D_Window *window = S2D_CreateWindow(
        "Hello Triangle", screen_width, screen_height, update, render, 0);//init the window
    S2D_Show(window);//show the window
    for(i = 0; i < NUM_BALLS; i++){
        S2D_FreeSound(balls[i].snd); //free sound from mem
    }
  return 0;
}
