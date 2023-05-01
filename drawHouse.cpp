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

void drawHouse(double X, double Y, double scale)
{
    double scaleX = 250;
    double scaleY = 200;

    scaleX *= scale;
    scaleY *= scale;

    // side roof
    glColor3ub(132, 75, 45);
    glBegin(GL_POLYGON);
    glVertex2f(X + 0.2 * scaleX, Y + 0.6 * scaleY);
    glVertex2f(X + 0.2 * scaleX, Y + 0.9 * scaleY);
    glVertex2f(X + 0.8 * scaleX, Y + 0.9 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y + 0.6 * scaleY);
    glEnd();

    // main door wall
    glColor3ub(206, 52, 42);
    glRectf(X + 0.1 * scaleX, Y, X + 0.3 * scaleX, Y + 0.8 * scaleY);

    // main door roof
    glBegin(GL_TRIANGLES);
    glColor3ub(184, 107, 63);
    glVertex2f(X, Y + 0.8 * scaleY);
    glVertex2f(X + 0.2 * scaleX, Y + 1.0 * scaleY);
    glVertex2f(X + 0.4 * scaleX, Y + 0.8 * scaleY);
    glEnd();

    // main door
    glColor3ub(130, 73, 11);
    glRectf(X + 0.17 * scaleX, Y, X + 0.23 * scaleX, Y + 0.2 * scaleY);

    // main door window
    glColor3ub(225, 235, 227);
    glRectf(X + 0.17 * scaleX, Y + 0.5 * scaleY, X + 0.23 * scaleX, Y + 0.6 * scaleY);

    // side wall
    glColor3ub(177, 44, 35);
    glRectf(X + 0.3 * scaleX, Y, X + 1.0 * scaleX, Y + 0.6 * scaleY);

    // side window
    glColor3ub(225, 235, 227);
    glRectf(X + 0.4 * scaleX, Y + 0.2 * scaleY, X + 0.9 * scaleX, Y + 0.35 * scaleY);
}