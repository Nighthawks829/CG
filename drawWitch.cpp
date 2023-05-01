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

void drawWitch(double X, double Y, double scale)
{
    double scaleX = 150;
    double scaleY = 300;

    scaleX *= scale;
    scaleY *= scale;

    // feet
    glColor3ub(96, 69, 50);
    glRectf(X + 0.3 * scaleX, Y, X + 0.7 * scaleX, Y + 0.1 * scaleY);

    // hair
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(X + 0.1 * scaleX, Y + 0.35 * scaleY);
    glVertex2f(X + 0.2 * scaleX, Y + 0.8 * scaleY);
    glVertex2f(X + 0.8 * scaleX, Y + 0.8 * scaleY);
    glVertex2f(X + 0.9 * scaleX, Y + 0.35 * scaleY);
    glEnd();

    // leg
    glColor3ub(55, 0, 166);
    glRectf(X + 0.25 * scaleX, Y + 0.1 * scaleY, X + 0.75 * scaleX, Y + 0.35 * scaleY);

    // shirt
    glColor3ub(55, 0, 166);
    glRectf(X, Y + 0.35 * scaleY, X + 1.0 * scaleX, Y + 0.55 * scaleY);

    // zip
    glColor3ub(0, 51, 12);
    glRectf(X + 0.45 * scaleX, Y + 0.1 * scaleY, X + 0.55 * scaleX, Y + 0.35 * scaleY);

    // hand
    glColor3ub(26, 0, 81);
    glRectf(X, Y + 0.35 * scaleY, X + 1.0 * scaleX, Y + 0.4 * scaleY);

    // sleeve
    glColor3ub(18, 0, 56);
    glRectf(X + 0.45 * scaleX, Y + 0.35 * scaleY, X + 0.55 * scaleX, Y + 0.55 * scaleY);

    // face
    glColor3ub(209, 180, 152);
    glRectf(X + 0.25 * scaleX, Y + 0.55 * scaleY, X + 0.75 * scaleX, Y + 0.80 * scaleY);

    // eyebrow
    glColor3ub(0, 0, 0);
    glRectf(X + 0.28 * scaleX, Y + 0.75 * scaleY, X + 0.72 * scaleX, Y + 0.77 * scaleY);

    // left eye
    glColor3ub(98, 89, 79);
    glRectf(X + 0.35 * scaleX, Y + 0.69 * scaleY, X + 0.40 * scaleX, Y + 0.72 * scaleY);

    // right eye
    glColor3ub(98, 89, 79);
    glRectf(X + 0.6 * scaleX, Y + 0.69 * scaleY, X + 0.65 * scaleX, Y + 0.72 * scaleY);

    // nose
    glColor3ub(140, 71, 71);
    glRectf(X + 0.45 * scaleX, Y + 0.59 * scaleY, X + 0.55 * scaleX, Y + 0.69 * scaleY);

    // hat
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(X + 0.1 * scaleX, Y + 0.8 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + 1 * scaleY);
    glVertex2f(X + 0.9 * scaleX, Y + 0.8 * scaleY);
    glEnd();

    // emerland
    glColor3ub(0, 105, 25);
    glRectf(X + 0.4 * scaleX, Y + 0.82 * scaleY, X + 0.6 * scaleX, Y + 0.87 * scaleY);
}