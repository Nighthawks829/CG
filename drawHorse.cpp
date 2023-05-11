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

void drawInverseHorse(double X, double Y, double scale);

void drawHorse(double X, double Y, double scale,int rot)
{

    double scaleX = 200;
    double scaleY = 100;

    scaleX *= scale;
    scaleY *= scale;

    if(rot==-1)
    {
        drawInverseHorse(X,Y,scale);
        return;
    }

    // 1) Start left leg
    glPushMatrix();
    glColor3ub(94, 72, 62);
    glRectf(X + 0.2 * scaleX, Y, X + 0.3 * scaleX, Y + 0.1 * scaleY);
    glPopMatrix();
    // end left leg

    // 2) Start right leg
    glPushMatrix();
    glColor3ub(94, 72, 62);
    glRectf(X + 0.5 * scaleX, Y, X + 0.6 * scaleX, Y + 0.1 * scaleY);
    glPopMatrix();
    // end right leg

    // 3) Start left elbow
    glPushMatrix();
    glColor3ub(43, 29, 23);
    glRectf(X + 0.2 * scaleX, Y + 0.1 * scaleY, X + 0.3 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // end left elbow

    // 4) Start right elbow
    glPushMatrix();
    glColor3ub(43, 29, 23);
    glRectf(X + 0.5 * scaleX, Y + 0.1 * scaleY, X + 0.6 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // End right elbow

    // 5) Start body
    glPushMatrix();
    glColor3ub(209, 209, 211);
    glRectf(X + 0.15 * scaleX, Y + 0.3 * scaleY, X + 0.7 * scaleX, Y + 0.7 * scaleY);
    glPopMatrix();
    // End body

    // 6) Start neck, head, eye, eyeball, mouth
    glPushMatrix();

    // 6.1) Start neck
    glTranslatef(X + (0.55 * scaleX), Y + (0.65 * scaleY), 0);
    glRotatef(330, 0, 0, 1);
    glColor3ub(209, 209, 211);
    glRectf(0.0, 0.0, 0.15 * scaleX, 0.45 * scaleY);
    // End neck

    // 6.2) Start head
    glTranslatef(0, (0.45 * scaleY) + (0.1 * scaleX), 0);
    glRotatef(270, 0, 0, 1);
    glColor3ub(209, 209, 211);
    glRectf(0.0, 0.0, 0.15 * scaleX, 0.5 * scaleY);
    // End head

    // 6.3) Start eye and eye ball
    glPushMatrix();

    // 6.3.1) Start eye
    glTranslatef(0.05 * scaleX, 0.05 * scaleX, 0);
    glColor3ub(0, 0, 0);
    glRectf(0.0, 0.0, 0.06 * scaleX, 0.08 * scaleY);
    // End eye

    // 6.3.2) Start eyeball
    glTranslatef(0.01 * scaleX, 0.01 * scaleX, 0);
    glColor3ub(128, 128, 128);
    glRectf(0.0, 0.0, 0.03 * scaleX, 0.03 * scaleY);
    // End eye ball

    glPopMatrix();
    // End eye and eyeball

    // 6.4) Start mouth
    glPushMatrix();
    glTranslatef(0.15 * scaleX, 0.35 * scaleY, 0);
    glColor3ub(0, 0, 0);
    glRectf(0.0, 0.0, -(0.03 * scaleX), 0.15 * scaleY);
    glPopMatrix();
    // End mouth

    glPopMatrix();
    // End neck , head, eye, eyeball and mouth
}


void drawInverseHorse(double X, double Y, double scale)
{

    double scaleX = 200;
    double scaleY = 100;

    scaleX *= scale;
    scaleY *= scale;

    // 1) Start left leg
    glPushMatrix();
    glColor3ub(94, 72, 62);
    glRectf(X + 1-0.2 * scaleX, Y, X + 1-0.3 * scaleX, Y + 0.1 * scaleY);
    glPopMatrix();
    // end left leg

    // 2) Start right leg
    glPushMatrix();
    glColor3ub(94, 72, 62);
    glRectf(X + 1-0.5 * scaleX, Y, X +1- 0.6 * scaleX, Y + 0.1 * scaleY);
    glPopMatrix();
    // end right leg

    // 3) Start left elbow
    glPushMatrix();
    glColor3ub(43, 29, 23);
    glRectf(X + 1-0.2 * scaleX, Y + 0.1 * scaleY, X + 1-0.3 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // end left elbow

    // 4) Start right elbow
    glPushMatrix();
    glColor3ub(43, 29, 23);
    glRectf(X + 1-0.5 * scaleX, Y + 0.1 * scaleY, X + 1-0.6 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // End right elbow

    // 5) Start body
    glPushMatrix();
    glColor3ub(209, 209, 211);
    glRectf(X + 1-0.15 * scaleX, Y + 0.3 * scaleY, X +1- 0.7 * scaleX, Y + 0.7 * scaleY);
    glPopMatrix();
    // End body

    // 6) Start neck, head, eye, eyeball, mouth
    glPushMatrix();

    // 6.1) Start neck
    glTranslatef(X + (-0.55 * scaleX), Y + (0.65 * scaleY), 0);
    glRotatef(30, 0, 0, 1);
    glColor3ub(209, 209, 211);
    glRectf(0, 0.0, 1-0.15 * scaleX, 0.45 * scaleY);
    // End neck

    // 6.2) Start head
    glTranslatef(0, (0.45 * scaleY) + (0.1 * scaleX), 0);
    glRotatef(90, 0, 0, 1);
    glColor3ub(209, 209, 211);
    glRectf(0.0, 0.0, 1-0.15 * scaleX, 0.5 * scaleY);
    // End head

    // 6.3) Start eye and eye ball
    glPushMatrix();

    // 6.3.1) Start eye
    glTranslatef(-0.05 * scaleX, 0.05 * scaleX, 0);
    glColor3ub(0, 0, 0);
    glRectf(0.0, 0.0, 1-0.06 * scaleX, 0.08 * scaleY);
    // End eye

    // 6.3.2) Start eyeball
    glTranslatef(-0.01 * scaleX, 0.01 * scaleX, 0);
    glColor3ub(128, 128, 128);
    glRectf(0.0, 0.0, 1-0.03 * scaleX, 0.03 * scaleY);
    // End eye ball

    glPopMatrix();
    // End eye and eyeball

    // 6.4) Start mouth
    glPushMatrix();
    glTranslatef(-0.15 * scaleX, 0.35 * scaleY, 0);
    glColor3ub(0, 0, 0);
    glRectf(0.0, 0.0, (0.03 * scaleX), 0.15 * scaleY);
    glPopMatrix();
    // End mouth

    glPopMatrix();
    // End neck , head, eye, eyeball and mouth
}