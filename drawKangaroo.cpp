#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include <cmath>

void drawEllipse(double centerX, double centerY, double radiusX, double radiusY, int numVertices)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center of the ellipse

    // Generate vertices along the ellipse circumference
    for (int i = 0; i <= numVertices; ++i)
    {
        float angle = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numVertices);
        float x = centerX + radiusX * cos(angle);
        float y = centerY + radiusY * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void drawKangaroo(double X, double Y, double scale)
{
    double scaleX = 300;
    double scaleY = 250;

    scaleX *= scale;
    scaleY *= scale;

    // boder
    // glColor3ub(0, 0, 0);
    // glRectf(X, Y, X + scaleX, Y + scaleY);
    // Start right ear
    glPushMatrix();
    glTranslatef(X + 0.725 * scaleX, Y + 0.8 * scaleY, 0.0);
    glRotatef(50, 0, 0, 1);
    glColor3ub(133, 99, 64);
    glRectf(0, 0, 0.25 * scaleX, 0.03 * scaleY);
    glPopMatrix();
    // End right ear

    // Start right leg
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 0.60 * scaleX, Y + 0.09 * scaleY, X + 0.7 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // End left leg

    // Start right feet
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 0.6 * scaleX, Y + 0.09 * scaleY, X + 0.75 * scaleX, Y + 0.14 * scaleY);
    glPopMatrix();
    // End right feet

    // Start right hand
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glTranslatef(X + 0.75 * scaleX, Y + 0.43 * scaleY, 0.0);
    glRotatef(-60, 0, 0, 1);
    glRectf(0, 0, 0.2 * scaleX, 0.03 * scaleX);
    glPopMatrix();
    // End right hand

    // Start right paw
    glPushMatrix();
    glColor3ub(90, 79, 71);
    glRectf(X + 0.75 * scaleX, Y + 0.09 * scaleY, X + 0.8 * scaleX, Y + 0.14 * scaleY);
    glPopMatrix();
    // End right paw

    // Start dummy
    glPushMatrix();
    glTranslatef(X + 0.6 * scaleX, Y + 0.33 * scaleY, 0.0);
    glRotatef(25, 0, 0, 1);
    glColor3ub(162, 155, 125);
    drawEllipse(0, 0, 0.15 * scaleX, 0.12 * scaleY, 100);
    glPopMatrix();
    // End dummy

    // Start tail
    glPushMatrix();
    glColor3ub(145, 113, 76);
    glRectf(X, Y + 0.2 * scaleY, X + 0.2 * scaleX, Y + 0.25 * scaleY);
    glPopMatrix();
    // End tail

    // Start tail second part
    glPushMatrix();
    glTranslatef(X + 0.2 * scaleX, Y + 0.175 * scaleY, 0.0);
    glRotatef(20, 0, 0, 1);
    glRectf(0.0, 0.0, 0.2 * scaleX, 0.1 * scaleY);
    // End tail second part

    // Start body
    glRectf(0.2 * scaleX, 0 - 0.05 * scaleY, 0.65 * scaleX, 0.15 * scaleY);
    // End body

    glPopMatrix();
    // End tail second part

    // Start left leg
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 0.45 * scaleX, Y, X + 0.55 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // End left leg

    // Start left feet
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 0.45 * scaleX, Y, X + 0.65 * scaleX, Y + 0.05 * scaleY);
    glPopMatrix();
    // End left feet

    // Start left paw
    glPushMatrix();
    glColor3ub(90, 79, 71);
    glRectf(X + 0.65 * scaleX, Y, X + 0.7 * scaleX, Y + 0.05 * scaleY);
    glPopMatrix();
    // End left paw

    // Start neck
    glPushMatrix();
    glColor3ub(137, 105, 67);
    glRectf(X + 0.65 * scaleX, Y + 0.45 * scaleY, X + 0.8 * scaleX, Y + 0.65 * scaleY);
    glPopMatrix();
    // End neck

    // Start left hand
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glTranslatef(X + 0.72 * scaleX, Y + 0.4 * scaleY, 0.0);
    glRotatef(-60, 0, 0, 1);
    glRectf(0, 0, 0.2 * scaleX, 0.03 * scaleX);
    glPopMatrix();
    // End left hand

    // Start head
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 0.65 * scaleX, Y + 0.65 * scaleY, X + scaleX, Y + 0.8 * scaleY);
    glPopMatrix();
    // End head

    // Start eye
    glPushMatrix();
    glColor3ub(13, 10, 7);
    glRectf(X + 0.75 * scaleX, Y + 0.75 * scaleY, X + 0.8 * scaleX, Y + 0.78 * scaleY);
    glPopMatrix();
    // End eye

    // Start Noise
    glPushMatrix();
    glColor3ub(64, 54, 49);
    glRectf(X + 0.95 * scaleX, Y + 0.75 * scaleY, X + 1 * scaleX, Y + 0.8 * scaleY);
    glPopMatrix();
    // End Noise

    // Start left ear
    glPushMatrix();
    glTranslatef(X + 0.725 * scaleX, Y + 0.8 * scaleY, 0.0);
    glRotatef(130, 0, 0, 1);
    glColor3ub(133, 99, 64);
    glRectf(0, 0, 0.25 * scaleX, 0.05 * scaleY);
    glPopMatrix();
    // End left ear
}