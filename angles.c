#include <simple2d.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define torad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)

const int screen_width = 640;
const int screen_height = 480;

int angle = 0;
float x = 0;
float y = 0;
float vx = 0;
float vy = 0;
int dir_x = 1;
int dir_y = 1;


int main(){
  int i;
  angle = 25;
  x = 5;
  y = 5;

for (i = 0; i < 10; i++){
  y = y + tan(torad(angle));
  x++;
  printf("x: %f", x);
  printf("\n");
  printf("y: %f", y);
  printf("\n");
}

}
