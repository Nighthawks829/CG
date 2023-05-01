#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include <cmath>

#define SCREENWIDTH 500
#define SCREENHEIGHT 500
#define PI 3.1415926535897932384626433832795
#define FPS 60

void drawGround()
{
    glColor3ub(0, 154, 23);
    glRectf(0, 0, SCREENWIDTH, 0.6 * SCREENHEIGHT);
}