#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include <cmath>

void drawHalfEllipse(double centerX, double centerY, double radiusX, double radiusY, int numVertices)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center of the ellipse

    // Generate vertices along the ellipse circumference
    for (int i = 0; i <= numVertices; ++i)
    {
        float angle = 2.0f * M_PI / 2 * static_cast<float>(i) / static_cast<float>(numVertices);
        float x = centerX + radiusX * cos(-angle);
        float y = centerY + radiusY * sin(-angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void drawPrincess(double X, double Y, double scale)
{
    double scaleX = 200;
    double scaleY = 300;

    scaleX *= scale;
    scaleY *= scale;

    // Start hair behind face
    double r = 0.25 * scaleX;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 204, 71);
    glVertex2f(X + 0.325 * scaleX, Y + 0.7 * scaleY); // center of circle
    for (int i = 0; i <= 100; i++)
    {
        float theta = 2.0f * 3.1415926f / 2 * float(i) / float(100); // get the current angle
        float x = r * cosf(theta);                                   // calculate the x component
        float y = r * sinf(theta);                                   // calculate the y component
        glVertex2f(x + X + 0.325 * scaleX, y + Y + 0.7 * scaleY);    // output vertex
    }
    glEnd();
    // End hair behind face

    // Start Rectangle hair
    glPushMatrix();
    glColor3ub(255, 204, 71);
    glRectf(X + 0.075 * scaleX, Y + 0.7 * scaleY, X + 0.575 * scaleX, Y);
    glPopMatrix();
    // Start rectangle hair

    // Start hair on floor
    glPushMatrix();
    glColor3ub(255, 204, 71);
    glRectf(X + 0.575 * scaleX, Y, X + 1 * scaleX, Y + 0.1 * scaleY);
    glPopMatrix();
    // End hair on floor

    // Start shirt
    glPushMatrix();
    glColor3ub(112, 61, 117);
    glRectf(X + 0.1 * scaleX, Y + 0.15 * scaleY, X + 0.55 * scaleX, Y + 0.5 * scaleY);
    glPopMatrix();
    // End shirt

    // Start Shoulder
    glPushMatrix();
    glColor3ub(203, 142, 158);
    glRectf(X + 0 * scaleX, Y + 0.5 * scaleY, X + 0.65 * scaleX, Y + 0.55 * scaleY);
    glPopMatrix();
    // End shoulder

    // Start left hand
    glPushMatrix();
    glColor3ub(255, 204, 149);
    glRectf(X + 0.03 * scaleX, Y + 0.5 * scaleY, X + 0.1 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // End left hand

    // Start right hand
    glPushMatrix();
    glColor3ub(255, 204, 149);
    glRectf(X + 0.55 * scaleX, Y + 0.5 * scaleY, X + 0.62 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // End left hand

    // Start left leg
    glPushMatrix();
    glColor3ub(255, 204, 149);
    glRectf(X + 0.215 * scaleX, Y, X + 0.285 * scaleX, Y + 0.2 * scaleY);
    glPopMatrix();
    // End left leg

    // Start right leg
    glPushMatrix();
    glColor3ub(255, 204, 149);
    glRectf(X + 0.365 * scaleX, Y, X + 0.435 * scaleX, Y + 0.2 * scaleY);
    glPopMatrix();
    // End left leg

    // Start skirt
    glPushMatrix();
    glColor3ub(85, 48, 116);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(X + 0.1 * scaleX, Y + 0.3 * scaleY);
    glVertex2f(X + 0.1 * scaleX, Y + 0.1 * scaleY);
    glVertex2f(X + 0.25 * scaleX, Y + 0.25 * scaleY);
    glVertex2f(X + 0.25 * scaleX, Y + 0.05 * scaleY);
    glVertex2f(X + 0.4 * scaleX, Y + 0.25 * scaleY);
    glVertex2f(X + 0.4 * scaleX, Y + 0.05 * scaleY);
    glVertex2f(X + 0.55 * scaleX, Y + 0.3 * scaleY);
    glVertex2f(X + 0.55 * scaleX, Y + 0.1 * scaleY);
    glEnd();
    glPopMatrix();
    // End skirt

    // Start left skirt line
    glPushMatrix();
    glColor3ub(105, 47, 111);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(X + 0.2 * scaleX, Y + 0.27 * scaleY);
    glVertex2f(X + 0.2 * scaleX, Y + 0.07 * scaleY);
    glVertex2f(X + 0.25 * scaleX, Y + 0.25 * scaleY);
    glVertex2f(X + 0.25 * scaleX, Y + 0.05 * scaleY);
    glVertex2f(X + 0.27 * scaleX, Y + 0.25 * scaleY);
    glVertex2f(X + 0.27 * scaleX, Y + 0.05 * scaleY);
    glEnd();
    glPopMatrix();
    // End left skirt line

    // Start right skirt line
    glPushMatrix();
    glColor3ub(105, 47, 111);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(X + 0.37 * scaleX, Y + 0.25 * scaleY);
    glVertex2f(X + 0.37 * scaleX, Y + 0.05 * scaleY);
    glVertex2f(X + 0.4 * scaleX, Y + 0.25 * scaleY);
    glVertex2f(X + 0.4 * scaleX, Y + 0.05 * scaleY);
    glVertex2f(X + 0.45 * scaleX, Y + 0.27 * scaleY);
    glVertex2f(X + 0.45 * scaleX, Y + 0.07 * scaleY);
    glEnd();
    glPopMatrix();
    // End right skirt line

    // Start neck
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(255, 204, 149);
    glVertex2f(X + 0.285 * scaleX, Y + 0.52 * scaleY);
    glVertex2f(X + 0.365 * scaleX, Y + 0.52 * scaleY);
    glVertex2f(X + 0.385 * scaleX, Y + 0.55 * scaleY);
    glVertex2f(X + 0.265 * scaleX, Y + 0.55 * scaleY);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRectf(X + 0.265 * scaleX, Y + 0.55 * scaleY, X + 0.385 * scaleX, Y + 0.6 * scaleY);
    glPopMatrix();
    // End neck

    // Start face
    r = 0.2 * scaleX;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 204, 149);
    glVertex2f(X + 0.325 * scaleX, Y + 0.7 * scaleY); // center of circle
    for (int i = 0; i <= 100; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);  // get the current angle
        float x = r * cosf(theta);                                // calculate the x component
        float y = r * sinf(theta);                                // calculate the y component
        glVertex2f(x + X + 0.325 * scaleX, y + Y + 0.7 * scaleY); // output vertex
    }
    glEnd();
    // End face

    // Start left eye
    glPushMatrix();
    glColor3ub(16, 14, 14);
    glRectf(X + 0.23 * scaleX, Y + 0.7 * scaleY, X + 0.265 * scaleX, Y + 0.73 * scaleY);
    glPopMatrix();
    // End left eye

    // Start left eye ball
    glPushMatrix();
    glColor3ub(255, 251, 248);
    glRectf(X + 0.25 * scaleX, Y + 0.715 * scaleY, X + 0.265 * scaleX, Y + 0.73 * scaleY);
    glPopMatrix();
    // End left eye ball

    // Start right eye
    glPushMatrix();
    glColor3ub(16, 14, 14);
    glRectf(X + 0.385 * scaleX, Y + 0.7 * scaleY, X + 0.42 * scaleX, Y + 0.73 * scaleY);
    glPopMatrix();
    // End right eye

    // Start right eye ball
    glPushMatrix();
    glColor3ub(255, 251, 248);
    glRectf(X + 0.385 * scaleX, Y + 0.73 * scaleY, X + 0.405 * scaleX, Y + 0.715 * scaleY);
    glPopMatrix();
    // End right eye ball

    // Start mouth
    glPushMatrix();
    glColor3ub(255, 179, 179);
    drawHalfEllipse(X + 0.325 * scaleX, Y + 0.63 * scaleY, 0.05 * scaleX, 0.02 * scaleY, 100);
    glPopMatrix();
    // End mouth
}