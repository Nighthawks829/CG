#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include <cmath>
void drawArrow(double X, double Y, double scale, double rot)
{
    double scaleX = 200;
    double scaleY = 100;

    scaleX = scaleX * scale;
    scaleY = scaleY * scale;

    glPushMatrix();
    glTranslatef(X, Y, 0);
    glRotatef(rot, 0, 0, 1);
    // // head
    // glPushMatrix();
    // glBegin(GL_TRIANGLES);
    // glColor3ub(192, 192, 192);
    // glVertex2f(X + 0.8 * scaleX, Y + scaleY);
    // glVertex2f(X + 0.8 * scaleX, Y);
    // glVertex2f(X + scaleX, Y + 0.5 * scaleY);
    // glEnd();
    // glPopMatrix();

    // // rod
    // glPushMatrix();
    // glColor3ub(133, 94, 66);
    // glRectf(X + 0.2 * scaleX, Y + 0.35 * scaleY, X + 0.8 * scaleX, Y + 0.65 * scaleY);
    // glPopMatrix();

    // // feather
    // glPushMatrix();
    // glBegin(GL_POLYGON);
    // glColor3ub(239, 234, 230);
    // glVertex2f(X + 0.2 * scaleX, Y + 0.65 * scaleY);
    // glVertex2f(X, Y + 0.75 * scaleY);
    // glVertex2f(X, Y + 0.25 * scaleY);
    // glVertex2f(X + 0.2 * scaleX, Y + 0.35 * scaleY);
    // glEnd();
    // glPopMatrix();
    // head
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3ub(192, 192, 192);
    glVertex2f(0.8 * scaleX, scaleY);
    glVertex2f(0.8 * scaleX, 0);
    glVertex2f(scaleX, 0.5 * scaleY);
    glEnd();
    glPopMatrix();

    // rod
    glPushMatrix();
    glColor3ub(133, 94, 66);
    glRectf(0.2 * scaleX, 0.35 * scaleY, 0.8 * scaleX, 0.65 * scaleY);
    glPopMatrix();

    // feather
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(239, 234, 230);
    glVertex2f(0.2 * scaleX, 0.65 * scaleY);
    glVertex2f(0, 0.75 * scaleY);
    glVertex2f(0, 0.25 * scaleY);
    glVertex2f(0.2 * scaleX, 0.35 * scaleY);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}