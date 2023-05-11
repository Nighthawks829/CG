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

void drawMagic(double X, double Y, double scale)
{

    double scaleX = 200;
    double scaleY = 100;

    scaleX *= scale;
    scaleY *= scale;

    glPushMatrix();
    glColor3ub(247, 87, 0);
    drawCircle(X+0.5*scaleX,Y+0.5*scaleY,0.05*scaleX,100);
    glPopMatrix();
}
