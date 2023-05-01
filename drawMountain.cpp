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

void drawMountain(double X, double Y, double scale)
{
    double scaleX = 150;
    double scaleY = 100;

    scaleX *= scale;
    scaleY *= scale;

    glBegin(GL_TRIANGLES);
    glColor3ub(0.0, 255.0, 0.0);
    glVertex2f(X, Y);
    glVertex2f(X + 0.5 * scaleX, Y + 1.0 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y);
    glEnd();
}