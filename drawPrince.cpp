#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include <cmath>

void drawPrince(double X, double Y, double scale)
{
    double scaleX = 100;
    double scaleY = 200;

    scaleX = scaleX * scale;
    scaleY = scaleY * scale;

    // border
    // glPushMatrix();
    // glColor3ub(0, 0, 0);
    // glRectf(X, Y, X + scaleX, Y + scaleY);
    // glPopMatrix();

    // hair
    glPushMatrix();
    glColor3ub(35, 35, 35);
    glRectf(X + 0.17 * scaleX, Y + 0.75 * scaleY, X + 0.83 * scaleX, Y + 0.95 * scaleY);
    glPopMatrix();

    // left shoes
    glPushMatrix();
    glColor3ub(42, 43, 49);
    glRectf(X + 0.2 * scaleX, Y, X + 0.4 * scaleX, Y + 0.05 * scaleY);
    glPopMatrix();

    // right shoes
    glPushMatrix();
    glColor3ub(42, 43, 49);
    glRectf(X + 0.6 * scaleX, Y, X + 0.8 * scaleX, Y + 0.05 * scaleY);
    glPopMatrix();

    // left leg
    glPushMatrix();
    glColor3ub(63, 61, 55);
    glRectf(X + 0.2 * scaleX, Y + 0.05 * scaleY, X + 0.4 * scaleX, Y + 0.25 * scaleY);
    glPopMatrix();

    // right leg
    glPushMatrix();
    glColor3ub(63, 61, 55);
    glRectf(X + 0.6 * scaleX, Y + 0.05 * scaleY, X + 0.8 * scaleX, Y + 0.25 * scaleY);
    glPopMatrix();

    // pants
    glPushMatrix();
    glColor3ub(20, 15, 11);
    glRectf(X + 0.2 * scaleX, Y + 0.25 * scaleY, X + 0.8 * scaleX, Y + 0.35 * scaleY);
    glPopMatrix();

    // white shirt
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glRectf(X + 0.2 * scaleX, Y + 0.35 * scaleY, X + 0.8 * scaleX, Y + 0.7 * scaleY);
    glPopMatrix();

    // coat
    glPushMatrix();
    glColor3ub(206, 16, 18);
    glRectf(X + 0.2 * scaleX, Y + 0.35 * scaleY, X + 0.4 * scaleX, Y + 0.65 * scaleY);
    glRectf(X + 0.6 * scaleX, Y + 0.35 * scaleY, X + 0.8 * scaleX, Y + 0.65 * scaleY);
    glPopMatrix();

    // shoulder
    glPushMatrix();
    glColor3ub(206, 16, 18);
    glRectf(X + 0 * scaleX, Y + 0.65 * scaleY, X + 1 * scaleX, Y + 0.7 * scaleY);
    glPopMatrix();

    // shoulder gold
    glPushMatrix();

    glBegin(GL_TRIANGLES);
    glColor3ub(252, 193, 51);
    glVertex2f(X, Y + 0.7 * scaleY);
    glVertex2f(X, Y + 0.65 * scaleY);
    glVertex2f(X + 0.1 * scaleX, Y + 0.7 * scaleY);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(252, 193, 51);
    glVertex2f(X + scaleX, Y + 0.7 * scaleY);
    glVertex2f(X + scaleX, Y + 0.65 * scaleY);
    glVertex2f(X + 0.9 * scaleX, Y + 0.7 * scaleY);
    glEnd();
    glPopMatrix();

    // sleeve
    glPushMatrix();
    glColor3ub(206, 16, 18);
    glRectf(X, Y + 0.65 * scaleY, X + 0.19 * scaleX, Y + 0.4 * scaleY);
    glRectf(X + 1.0 * scaleX, Y + 0.65 * scaleY, X + 0.81 * scaleX, Y + 0.4 * scaleY);
    glPopMatrix();

    // hand
    glPushMatrix();
    glColor3ub(255, 204, 149);
    glRectf(X + 0.03 * scaleX, Y + 0.4 * scaleY, X + 0.16 * scaleX, Y + 0.35 * scaleY);
    glRectf(X + 0.97 * scaleX, Y + 0.4 * scaleY, X + 0.84 * scaleX, Y + 0.35 * scaleY);
    glPopMatrix();

    // collar
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(X + 0.4 * scaleX, Y + 0.65 * scaleY);
    glVertex2f(X + 0.6 * scaleX, Y + 0.65 * scaleY);
    glVertex2f(X + 0.7 * scaleX, Y + 0.7 * scaleY);
    glVertex2f(X + 0.3 * scaleX, Y + 0.7 * scaleY);
    glEnd();
    glPopMatrix();

    // neck
    glPushMatrix();
    glColor3ub(255, 204, 149);
    glBegin(GL_POLYGON);
    glVertex2f(X + 0.35 * scaleX, Y + 0.7 * scaleY);
    glVertex2f(X + 0.65 * scaleX, Y + 0.7 * scaleY);
    glVertex2f(X + 0.6 * scaleX, Y + 0.75 * scaleY);
    glVertex2f(X + 0.4 * scaleX, Y + 0.75 * scaleY);
    glEnd();
    glPopMatrix();

    // face

    double r = 0.25 * scaleX;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 204, 149);
    glVertex2f(X + 0.5 * scaleX, Y + 0.85 * scaleY); // center of circle
    for (int i = 0; i <= 100; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(100); // get the current angle
        float x = r * cosf(theta);                               // calculate the x component
        float y = r * sinf(theta);                               // calculate the y component
        glVertex2f(x + X + 0.5 * scaleX, y + Y + 0.85 * scaleY); // output vertex
    }
    glEnd();

    // eye
    glPushMatrix();
    glColor3ub(255, 251, 248);
    drawCircle(X + 0.4 * scaleX, Y + 0.85 * scaleY, 0.05 * scaleX, 200);
    glColor3ub(91, 60, 52);
    drawCircle(X + 0.41 * scaleX, Y + 0.84 * scaleY, 0.03 * scaleX, 200);
    glColor3ub(255, 251, 248);
    drawCircle(X + 0.6 * scaleX, Y + 0.85 * scaleY, 0.05 * scaleX, 200);
    glColor3ub(91, 60, 52);
    drawCircle(X + 0.61 * scaleX, Y + 0.84 * scaleY, 0.03 * scaleX, 200);

    glPopMatrix();

    // mouth
    glPushMatrix();
    glColor3ub(255, 179, 179);
    drawHalfEllipse(X + 0.5 * scaleX, Y + 0.78 * scaleY, 0.05 * scaleX, 0.02 * scaleY, 100);
    glPopMatrix();

    // crown
    glPushMatrix();
    glColor3ub(237, 183, 2);
    glRectf(X + 0.17 * scaleX, Y + 0.9 * scaleY, X + 0.83 * scaleX, Y + 1 * scaleY);
    glPopMatrix();

    // crown triangle
    glPushMatrix();
    glColor3ub(237, 183, 2);
    glBegin(GL_TRIANGLES);
    glVertex2f(X + 0.17 * scaleX, Y + 1 * scaleY);
    glVertex2f(X + 0.17 * scaleX, Y + 1.05 * scaleY);
    glVertex2f(X + 0.22 * scaleX, Y + 1 * scaleY);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(X + 0.45 * scaleX, Y + 1 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + 1.05 * scaleY);
    glVertex2f(X + 0.55 * scaleX, Y + 1 * scaleY);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(X + 0.83 * scaleX, Y + 1 * scaleY);
    glVertex2f(X + 0.83 * scaleX, Y + 1.05 * scaleY);
    glVertex2f(X + 0.78 * scaleX, Y + 1 * scaleY);
    glEnd();

    glPopMatrix();
}
