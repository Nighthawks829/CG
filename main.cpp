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
#include "drawPrincess.cpp"
#include "drawKangaroo.cpp"

#define SCREENWIDTH 500
#define SCREENHEIGHT 500
#define PI 3.1415926535897932384626433832795
#define FPS 60

float kangarooInitX = 100;
float kangarooInitY = 0;
float dx = 5;
float dy = 5;

void drawBackground()
{
    drawSky();

    drawGround();

    drawMountain(300, 300, 1);

    drawTree(100, 250, 0.5);

    drawPrincess(130, 150, 0.5);
    drawHouse(220, 50, 1.1);

    drawHorse(200, 0.6*SCREENHEIGHT, 0.5);

    drawKangaroo(kangarooInitX, kangarooInitY, 0.5);
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

void idle()
{
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS)
        ;
    kangarooInitX += dx;
    dy = dy + 0.15;
    kangarooInitY = pow(10 * sin(dy), 2);

    if (kangarooInitX < 0 || kangarooInitX > SCREENWIDTH)
        dx *= -1;
    // if (kangarooInitY < 0 || kangarooInitY > SCREENHEIGHT)
    //     dy *= -1;

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(SCREENWIDTH, SCREENHEIGHT);
    glutCreateWindow("Test Window");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    initGL();
    glutMainLoop();
}
