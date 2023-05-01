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

void drawBroom(double X, double Y, double scale)
{
    double scaleX = 300;
    double scaleY = 150;

    scaleX *= scale;
    scaleY *= scale;
    // broom
    glColor3ub(106, 52, 14);
    glRectf(X, Y, X + 0.8 * scaleX, Y - 0.15 * scaleY);

    glColor3ub(221, 223, 35);
    glBegin(GL_POLYGON);
    glVertex2f(X + 0.8 * scaleX, Y - 0.22 * scaleY);
    glVertex2f(X + 0.8 * scaleX, Y + 0.07 * scaleY);
    glVertex2f(X + 0.9 * scaleX, Y + 0.22 * scaleY);
    glVertex2f(X + 0.9 * scaleX, Y - 0.37 * scaleY);

    glEnd();
}