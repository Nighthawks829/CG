#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include <cmath>

void drawTower(double X, double Y, double scale)
{
    double scaleX = 200;
    double scaleY = 400;

    scaleX = scaleX * scale;
    scaleY = scaleY * scale;

    // border
    // glPushMatrix();
    // glColor3ub(0, 0, 0);
    // glRectf(X, Y, X + scaleX, Y + scaleY);
    // glPopMatrix();

    // base
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(181, 72, 58);
    glVertex2f(X, Y);
    glVertex2f(X + 1.0 * scaleX, Y);
    glVertex2f(X + 0.9 * scaleX, Y + 0.2 * scaleY);
    glVertex2f(X + 0.1 * scaleX, Y + 0.2 * scaleY);
    glEnd();
    glPopMatrix();

    // body
    glPushMatrix();
    glColor3ub(136, 140, 141);
    glRectf(X + 0.1 * scaleX, Y + 0.2 * scaleY, X + 0.9 * scaleX, Y + 0.6 * scaleY);
    glPopMatrix();

    // edge
    glPushMatrix();
    glColor3ub(203, 65, 84);
    glRectf(X, Y + 0.6 * scaleY, X + scaleX, Y + 0.65 * scaleY);
    glPopMatrix();

    // room outside
    glPushMatrix();
    glColor3ub(136, 140, 141);
    glRectf(X + 0.1 * scaleX, Y + 0.65 * scaleY, X + 0.9 * scaleX, Y + 0.85 * scaleY);
    glPopMatrix();

    // room
    glPushMatrix();
    glColor3ub(175, 154, 119);
    glRectf(X + 0.15 * scaleX, Y + 0.65 * scaleY, X + 0.85 * scaleX, Y + 0.82 * scaleY);
    glPopMatrix();

    // roof
    glPushMatrix();
    glColor3ub(157, 96, 85);
    glBegin(GL_TRIANGLES);
    glVertex2f(X + 0.1 * scaleX, Y + 0.85 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + scaleY);
    glVertex2f(X + 0.9 * scaleX, Y + 0.85 * scaleY);
    glEnd();
    glPopMatrix();
}