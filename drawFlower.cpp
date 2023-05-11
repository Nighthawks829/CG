#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include <cmath>
// #include "drawCircle.cpp"
#define SCREENWIDTH 500
#define SCREENHEIGHT 500
#define PI 3.1415926535897932384626433832795
#define FPS 60

void drawFlower(double X, double Y, double scale)
{
    double scaleX = 200;
    double scaleY = 200;

    scaleX *= scale;
    scaleY *= scale;

    // Start leaf 1
    glPushMatrix();
    glColor3ub(92, 169, 4);
    drawCircle(X + 0.4 * scaleX, Y + 0.3 * scaleY, 0.3 * scaleX, 200);
    glPopMatrix();
    // End leaf 1

    // Start leaf 2
    glPushMatrix();
    glColor3ub(92, 169, 4);
    drawCircle(X + 0.3 * scaleX + 0.4 * scaleX, Y + 0.2 * scaleY, 0.2 * scaleX, 200);
    glPopMatrix();
    // End leaf 2

    // Start cut leaf
    glPushMatrix();
    glColor3ub(0, 154, 23);
    glRectf(X, Y, X + 0.9 * scaleX, Y + 0.1 * scaleY);
    glPopMatrix();
    // End cut leaf

    // Start flower
    glPushMatrix();
    glColor3ub(255, 0, 0);
    drawCircle(X + 0.3 * scaleX, Y + 0.4 * scaleY, 0.02 * scaleX, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 0);
    drawCircle(X + 0.5 * scaleX, Y + 0.3 * scaleY, 0.02 * scaleX, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 0);
    drawCircle(X + 0.8 * scaleX, Y + 0.3 * scaleY, 0.02 * scaleX, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 0, 0);
    drawCircle(X + 0.7 * scaleX, Y + 0.2 * scaleY, 0.02 * scaleX, 100);
    glPopMatrix();
}