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

void drawRiver(double X, double Y, double scale)
{
        double scaleX = 300;
    double scaleY = 300;

    glPushMatrix();
    glColor3ub(28, 163, 236);
    drawHalfEllipse(X,Y,0.5*scaleX,0.3*scaleY,200);
    glPopMatrix();
}

