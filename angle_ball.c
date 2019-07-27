#include <simple2d.h>
#include <stdio.h>

//constants to use for ball direction and boolean
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1
#define FALSE 0
#define TRUE 1

#define torad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)

const int screen_width = 640;
const int screen_height = 480;
const int ball_r = 30;
const int speed = 1;
float ball_y = 240;
float ball_x = 320;
int dir_y = DOWN;
int dir_x = RIGHT;
int angle = 190;
float fx = 0;
float fy = 0;
bool hit_x,hit_y = FALSE;
S2D_Sound *snd = NULL;

void update() {
    /*if(ball_x == (screen_width-ball_r)){ //hit right side
        dir_x = LEFT; //bounce back by going left
        hit_x = TRUE;
    }    else if(ball_x == ball_r) { //hit left side
            dir_x = RIGHT; //bounce back right
            hit_x = TRUE;
          } else {hit_x = FALSE;}*/


    /*if(ball_y == (screen_height-ball_r)){ //hit bottom
        dir_y = UP; //bounce up
        hit_y = TRUE;
    }    else if(ball_y == ball_r){ //hit top
            dir_y = DOWN; //bounce down
            hit_y = TRUE;
          } else {hit_y = FALSE;}*/
    if(angle > 0 && angle < 90){
        dir_y = UP;
        dir_x = RIGHT;
        ball_x = ball_x + (tan(torad(angle))*speed*dir_x);
        ball_y = ball_y + (speed * dir_y);
      }else if(angle > 90 && angle < 180){
          dir_y = DOWN;
          dir_x = RIGHT;
          ball_y = ball_y + (tan(torad(angle-90))*speed*dir_y);
          ball_x = ball_x + (speed * dir_x);
        }else if(angle > 180 && angle < 270){
            dir_y = DOWN;
            dir_x = LEFT;
            ball_x = ball_x + (tan(torad(angle-180))*speed*dir_x);
            ball_y = ball_y + (speed * dir_y);
          }else if(angle > 270 && angle < 360){
              dir_y = UP;
              dir_x = LEFT;
              ball_y = ball_y + (tan(torad(angle-270))*speed*dir_y);
              ball_x = ball_x + (speed * dir_x);
    }


}

void render() {
    S2D_DrawCircle(ball_x, ball_y, ball_r, 50, 1, 0, 0, 1);

    if(hit_x||hit_y){
        S2D_PlaySound(snd);//play bounce sound
    }
}

int main() {
    snd = S2D_CreateSound("bounce.wav"); //initialise sound
    S2D_Window *window = S2D_CreateWindow(
        "Hello Triangle", screen_width, screen_height, update, render, 0);//init the window
    S2D_Show(window);//show the window
    S2D_FreeSound(snd); //free sound from mem
  return 0;
}
