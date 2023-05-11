#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
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