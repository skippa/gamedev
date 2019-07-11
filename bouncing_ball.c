#include <simple2d.h>
#include <stdio.h>

//constants to use for ball direction and boolean
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1
#define FALSE 0
#define TRUE 1

const int screen_width = 640;
const int screen_height = 480;
const int ball_r = 30;
const int speed = 5;
int ball_y, ball_x = 0;
int dir_y, dir_x = 1;
bool hit_x,hit_y = FALSE;
S2D_Sound *snd = NULL;

void update() {
    if(ball_x == (screen_width-ball_r)){ //hit right side
        dir_x = LEFT; //bounce back by going left
        hit_x = TRUE;
    }    else if(ball_x == ball_r) { //hit left side
            dir_x = RIGHT; //bounce back right
            hit_x = TRUE;
            } else {hit_x = FALSE;}

    ball_x = ball_x + (speed * dir_x); //position ball x pos

    if(ball_y == (screen_height-ball_r)){ //hit bottom
        dir_y = UP; //bounce up
        hit_y = TRUE;
    }    else if(ball_y == ball_r){ //hit top
            dir_y = DOWN; //bounce down
            hit_y = TRUE;
            } else {hit_y = FALSE;}

    ball_y = ball_y + (speed * dir_y); //position ball y pos
}

void render() {
    S2D_DrawCircle(ball_x, ball_y, ball_r, 50, 1, 0, 0, 1);

    if(hit_x||hit_y){
        S2D_PlaySound(snd);//play bounce sound
    }
}

int main() {
    ball_x = ball_r; //set ball start x point
    ball_y = ball_r; //set ball start y point
    snd = S2D_CreateSound("bounce.wav"); //initialise sound
    S2D_Window *window = S2D_CreateWindow(
        "Hello Triangle", screen_width, screen_height, update, render, 0);//init the window
    S2D_Show(window);//show the window
    S2D_FreeSound(snd); //free sound from mem
  return 0;
}
