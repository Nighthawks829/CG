#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include <cmath>
#include "drawGround.cpp"
#include "drawSky.cpp"
#include "drawMountain.cpp"
#include "drawTree.cpp"
#include "drawHouse.cpp"
#include "drawWitch.cpp"
#include "drawBroom.cpp"
#include "drawHorse.cpp"

#define SCREENWIDTH 500
#define SCREENHEIGHT 500
#define PI 3.1415926535897932384626433832795
#define FPS 60


void drawBackground()
{
    drawSky();

    drawGround();

    drawMountain(300, 300, 1);

    drawTree(100, 250, 0.5);

    drawHouse(220, 50, 1.1);

    drawHorse(30, 30, 1);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);
    glLineWidth(4.0);

    drawBackground();

    drawWitch(100, 400, 0.3);
    drawBroom(100, 400, 0.3);

    glutSwapBuffers();
}

void reshape(int w, int h)
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluOrtho2D(0, SCREENWIDTH, 0, SCREENHEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

void initGL()
{
    // glClearColor(0.22, 0.49, 0.92, 0.0);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(SCREENWIDTH, SCREENHEIGHT);
    glutCreateWindow("Test Window");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // glutIdleFunc(idle);
    initGL();
    glutMainLoop();
}