#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include <cmath>

void drawCircle(double cx, double cy, double r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // center of circle
    for (int i = 0; i <= num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // get the current angle
        float x = r * cosf(theta);                                        // calculate the x component
        float y = r * sinf(theta);                                        // calculate the y component
        glVertex2f(x + cx, y + cy);                                       // output vertex
    }
    glEnd();
}