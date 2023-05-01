#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include <cmath>
#include "drawSun.cpp"

#define SCREENWIDTH 500
#define SCREENHEIGHT 500
#define PI 3.1415926535897932384626433832795
#define FPS 60

void drawSky()
{
    glColor3ub(135, 206, 235);
    glRectf(0, 0.6 * SCREENHEIGHT, SCREENWIDTH, SCREENHEIGHT);
    drawSun(20, 450, 50, 300);
}


