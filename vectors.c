#include <simple2d.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//constants to use for ball direction and boolean
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1
#define FALSE 0
#define TRUE 1

#define torad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)

float previousTime = 0;
float currentTime;
float dt;

typedef struct {
  float x;
  float y;
}vector;

typedef struct {
  float x;
  float y;
}point;

typedef struct {
  int r;
  point p;
  vector v;
  vector g;
  int dir_x;
  int dir_y;
}ball;

ball _ball;

const int screen_width = 640;
const int screen_height = 480;

vector Vector(float x, float y){
  vector _Vector;
  _Vector.x = x;
  _Vector.y = y;

  return _Vector;
}

vector addV(vector va, vector vb){

    vector returnVector;

    returnVector.x = va.x + vb.x;
    returnVector.y = va.y + vb.y;

    return returnVector;

}

vector subV(vector va, vector vb){

    vector returnVector;

    returnVector.x = va.x - vb.x;
    returnVector.y = va.y - vb.y;

    return returnVector;

}

vector dotV(vector va, vector vb){

    vector returnVector;

    returnVector.x = va.x * vb.x;
    returnVector.y = va.y * vb.y;

    return returnVector;

}

vector applyV(vector va, float coef){

    vector returnVector;

    returnVector.x = va.x * coef;
    returnVector.y = va.y * coef;

    return returnVector;

}

point Pt(float x, float y){

    point returnPoint;

    returnPoint.x = x;
    returnPoint.y = y;

    return returnPoint;

}

void update() {
  previousTime = currentTime;
  currentTime = time(NULL);
  dt = currentTime - previousTime;

    if(_ball.p.x >= (screen_width-_ball.r)){ //hit right side
        _ball.dir_x = LEFT; //bounce back by going left
    }    else if(_ball.p.x <= _ball.r) { //hit left side
            _ball.dir_x = RIGHT; //bounce back right
            }

    _ball.p.x += _ball.v.x * _ball.dir_x; //position _ball x pos

    if(_ball.p.y >= (screen_height-_ball.r)){ //hit bottom
        _ball.dir_y = UP; //bounce up
    }    else if(_ball.p.y <= _ball.r){ //hit top
            _ball.dir_y = DOWN; //bounce down
            }

    _ball.p.y += _ball.v.y * _ball.dir_y; //position _ball y pos
}

void render() {
    S2D_DrawCircle(_ball.p.x, _ball.p.y, _ball.r, 50, 1, 0, 0, 1);
    S2D_DrawLine(320, 240, _ball.p.x, _ball.p.y, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1);
}

int main() {
    currentTime = time(NULL);
    int angle;
    srand(time(NULL));
    _ball.g = Vector(0,-2);
    _ball.r = 30;
    _ball.p.x = 320;
    _ball.p.y = 240;
    angle = (rand() % 90)+1;
    if(angle >= 0 && angle <= 45){
      _ball.v.y = 5;
      _ball.v.x = tan(torad(angle)) * _ball.v.y;
    } else {
      _ball.v.x = 5;
      _ball.v.y = (1 - tan(torad(angle-45))) * _ball.v.x;
    }
    _ball.dir_x = RIGHT;
    _ball.dir_y = UP;

    S2D_Window *window = S2D_CreateWindow(
        "Hello Triangle", screen_width, screen_height, update, render, S2D_HIGHDPI);//init the window
    S2D_Show(window);//show the window

    return 0;
}
