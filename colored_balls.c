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

const int screen_width = 640;
const int screen_height = 480;

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
    S2D_Sound *snd;
}ball;

ball firstBall[10];


void update() {
    int i;
    for (i = 0; i < 10; i++){
        if(firstBall[i].x > (screen_width-firstBall[i].r)){ //hit right side
            firstBall[i].dir_x = LEFT; //bounce back by going left
            firstBall[i].hit_x = TRUE;
        }    else if(firstBall[i].x < firstBall[i].r) { //hit left side
                firstBall[i].dir_x = RIGHT; //bounce back right
                firstBall[i].hit_x = TRUE;
                } else {firstBall[i].hit_x = FALSE;}

        firstBall[i].x = firstBall[i].x + (firstBall[i].speed * firstBall[i].dir_x); //position ball x pos

        if(firstBall[i].y > (screen_height-firstBall[i].r)){ //hit bottom
            firstBall[i].dir_y = UP; //bounce up
            firstBall[i].hit_y = TRUE;
        }    else if(firstBall[i].y < firstBall[i].r){ //hit top
                firstBall[i].dir_y = DOWN; //bounce down
                firstBall[i].hit_y = TRUE;
                } else {firstBall[i].hit_y = FALSE;}

        firstBall[i].y = firstBall[i].y + (firstBall[i].speed * firstBall[i].dir_y); //position ball y pos
    }
}

void render() {
    int i;
    for (i = 0; i < 10; i++){
        S2D_DrawCircle(firstBall[i].x, firstBall[i].y, firstBall[i].r, 50, firstBall[i].red, firstBall[i].green, firstBall[i].blue, 1);

        if(firstBall[i].hit_x||firstBall[i].hit_y){
            //S2D_PlaySound(firstBall[i].snd);//play bounce sound
        }
    }
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 10; i++){
        firstBall[i].r = (rand() % 40)+10;
        firstBall[i].x = rand() % (screen_width - firstBall[i].r);
        firstBall[i].y = rand() % (screen_height - firstBall[i].r);
        firstBall[i].speed = 5;
        firstBall[i].dir_x = 1;
        firstBall[i].dir_y = 1;
        firstBall[i].hit_x = FALSE;
        firstBall[i].hit_y = FALSE;
        firstBall[i].red = ((rand() % 99)+1)/100;
        firstBall[i].green = ((rand() % 99)+1)/100;
        firstBall[i].blue = ((rand() % 99)+1)/100;
        firstBall[i].snd = S2D_CreateSound("bounce.wav");
    }

    S2D_Window *window = S2D_CreateWindow(
        "Hello Triangle", screen_width, screen_height, update, render, 0);//init the window
    S2D_Show(window);//show the window
    S2D_FreeSound(firstBall[0].snd); //free sound from mem
  return 0;
}


