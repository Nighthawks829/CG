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

void drawTree(double X, double Y, double scale)
{
    double scaleX = 150;
    double scaleY = 300;

    scaleX *= scale;
    scaleY *= scale;

    // trunk
    glColor3ub(102, 51, 0);
    glRectf(X + 0.4 * scaleX, Y, X + 0.6 * scaleX, Y + 0.2 * scaleY);

    // 3 layer leaf
    glBegin(GL_TRIANGLES);
    glColor3ub(0.0, 200, 0.0);
    glVertex2f(X, Y + 0.2 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + 0.45 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y + 0.2 * scaleY);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0.0, 200, 0.0);
    glVertex2f(X, Y + 0.4 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + 0.65 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y + 0.4 * scaleY);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0.0, 200, 0.0);
    glVertex2f(X, Y + 0.6 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + 0.85 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y + 0.6 * scaleY);
    glEnd();
}