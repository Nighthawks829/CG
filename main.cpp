#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include <cmath>
#include "drawCircle.cpp"
#include "drawHalfEllipse.cpp"
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
#include "drawFlower.cpp"
#include "drawRiver.cpp"
#include "drawTower.cpp"
#include "drawPrince.cpp"
#include "drawArrow.cpp"
#include "drawMagic.cpp"

#define SCREENWIDTH 500
#define SCREENHEIGHT 500
#define PI 3.1415926535897932384626433832795
#define FPS 60

float count = 0;
int kangarooRot = 1;
int horseRot = 1;

float witchMoveX;
float witchMoveY;
float princessX;
float princessY;
float houseX;
float houseY;
float towerX;
float towerY;
float kangarooX;
float kangarooY;
float dx = 0;
float dy = 0;
float proj = 0;
float riverX;
float riverY;
float princeX;
float princeY;
float horseX;
float horseY;
float magicX = 0;
float magicY = 0;

void sceneController()
{
    if (count == 0)
    {
        dx = 0;
        dy = 0;
    }
    else if (count > 1350 && count < 1550)
    {
        dx += 5;
    }
    else if (count > 2050 && count < 2250)
    {
        dx += 3;
    }
    else if (count > 2800 && count < 3120)
    {
        dx -= 5;
    }
}
void drawstring(float x, float y, float z, char *string)
{
    char *c;
    glRasterPos3f(x, y, z);

    for (c = string; *c != '\0'; c++)
    {
        glColor3f(0.0, 0.0, 0.0);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void princessController()
{
    if (count < 50)
    {
        princessX = 0.45 * SCREENWIDTH;
        princessY = 0.02 * SCREENHEIGHT;
    }
    else if (count > 50 && count < 150)
    {
        princessX -= 1;
    }
    else if (count > 550 && count < 650)
    {
        drawstring(princessX, princessY + 0.3 * SCREENHEIGHT, 0, "Yes, what can I help you?");
    }
    else if (count > 750 && count < 850)
    {
        princessY += 5;
    }
    else if (count > 850 && count < 900)
    {
        princessX += 5;
    }
    else if (count > 1100 && count < 1150)
    {
        drawstring(princessX, princessY + 0.3 * SCREENHEIGHT, 0, "Kangaroo help me!");
    }
    else if (count > 3220 && count < 3320)
    {
        drawstring(princessX, princessY + 0.3 * SCREENHEIGHT, 0, "Owhh thank you!");
    }
    else if (count > 3850 && count < 3950)
    {
        princessY -= 5;
    }
    else if (count > 4150 && count < 4250)
    {
        drawstring(princessX, princessY + 0.3 * SCREENHEIGHT, 0, "Owhh Thank you very much prince~~");
    }
    else if (count > 4350 && count < 4450)
    {
        drawstring(princessX, princessY + 0.3 * SCREENHEIGHT, 0, "Thank you for your invitation but I love my life now");
    }
}

void witchController()
{
    if (count == 0)
    {
        witchMoveX = SCREENWIDTH;
        witchMoveY = 0.5 * SCREENHEIGHT;
    }
    else if (count > 100 && count < 450)

    {
        witchMoveX -= 2;
    }
    else if (count > 450 && count < 550)
    {
        drawstring(witchMoveX, witchMoveY + 0.2 * SCREENHEIGHT, 0, "Are you Rapunzel?");
    }
    else if (count > 650 && count < 750)
    {
        drawstring(witchMoveX, witchMoveY + 0.2 * SCREENHEIGHT, 0, "hahahaha, I finally found you");
    }
    else if (count > 2800 && count < 2850)
    {
        witchMoveX = SCREENWIDTH + 10;
        witchMoveY = 0.5 * SCREENHEIGHT;
    }
    else if (count > 3470 && count < 3570)
    {
        witchMoveX -= 2.5;
        if (count > 3500)
        {
            drawstring(witchMoveX, witchMoveY + 0.2 * SCREENHEIGHT, 0, "Who is trying to save her! I will not let you succeed!!");
        }
    }
    else if (count > 3640 && count < 3740)
    {
        witchMoveX += 5;
        witchMoveY += 5;
        if (count > 3650)
        {
            drawstring(witchMoveX, witchMoveY + 0.2 * SCREENHEIGHT, 0, "AHhhhhhh!!! Nooooooo!!!");
        }
    }
}

void houseController()
{
    if (count == 0)
    {
        houseX = 0.5 * SCREENWIDTH;
        houseY = 0.01 * SCREENHEIGHT;
    }
    else if (count > 750 && count < 850)
    {
        houseY -= 10;
    }
    else if (count > 3950 && count < 4050)
    {
        houseY += 10;
    }
}

void towerController()
{
    if (count == 0)
    {
        towerX = 0.5 * SCREENWIDTH;
        towerY = -400;
    }
    else if (count > 750 && count < 850)
    {
        towerY += 10;
        if (towerY > 0.01 * SCREENHEIGHT)
        {
            towerY = 0.01 * SCREENHEIGHT;
        }
    }
    else if (count > 3850 && count < 3950)
    {
        towerY -= 10;
    }
}

void kangarooController()
{
    if (count == 0)
    {
        kangarooX = -250;
        kangarooY = 0.1 * SCREENHEIGHT;
    }
    else if (count > 900 && count < 1020)
    {
        if (kangarooX < 0.4 * SCREENWIDTH)
        {
            kangarooX += 8;
        }
        proj += 0.15;
        kangarooY = pow(8 * sin(proj), 2);
    }
    else if (count > 1000 && count < 1100)
    {
        drawstring(kangarooX, kangarooY + 0.2 * SCREENHEIGHT, 0, "Rapunzel!!!");
    }
    else if (count > 1150 && count < 1250)
    {
        drawstring(kangarooX, kangarooY + 0.2 * SCREENHEIGHT, 0, "Don't cry Rapunzel, I will find someone to save you.");
    }
    else if (count > 1250 && count < 1300)
    {
        kangarooRot = -1;
    }
    else if (count > 1330 && count < 1550)
    {
        proj += 0.15;
        kangarooY = pow(8 * sin(proj), 2);
        kangarooX += 1;
    }
    else if (count > 1650 && count < 1750)
    {
        drawstring(kangarooX, kangarooY + 0.2 * SCREENHEIGHT, 0, "My friend Rapunzel is locked by the witch in a tower, I'm finding someone with magic to lift the spell");
    }
    else if (count > 1850 && count < 1950)
    {

        drawstring(kangarooX, kangarooY + 0.2 * SCREENHEIGHT, 0, "Ohh that's great can you pls bring me to him?");
    }
    else if (count > 2100 && count < 2340)
    {

        proj += 0.15;
        kangarooY = pow(8 * sin(proj), 2);
        kangarooX += 1;
    }
    else if (count > 2650 && count < 2750)
    {
        drawstring(kangarooX, kangarooY + 0.2 * SCREENHEIGHT, 0, "Please help her.");
    }
    else if (count > 2750 && count < 2800)
    {
        kangarooRot = 1;
    }
    else if (count > 2800 && count < 3120)
    {
        kangarooX -= 3;
        proj += 0.15;
        kangarooY = pow(8 * sin(proj), 2);
        kangarooX += 1;
    }
    else if (count > 3120 && count < 3220)
    {
        drawstring(kangarooX, kangarooY + 0.2 * SCREENHEIGHT, 0, "Rapunzel!!! I found the prince to help you!");
    }
}

void riverController()
{
    if (count == 0)
    {
        riverX = -200;
        riverY = 0.6 * SCREENHEIGHT;
    }
    else if (count > 2150 && count < 2350)
    {
        riverX += 1.5;
    }
    else if (count > 2800 && count < 3000)
    {
        riverX -= 3;
    }
}

void princeController()
{
    if (count == 0)
    {
        princeX = -100;
        princeY = 0.05 * SCREENHEIGHT;
    }
    else if (count > 2150 && count < 2350)
    {
        princeX += 3;
    }
    else if (count > 2450 && count < 2550)
    {
        drawstring(princeX, princeY + 0.3 * SCREENHEIGHT, 0, "???");
    }
    else if (count > 2650 && count < 2750)
    {

        drawstring(princeX, princeY + 0.3 * SCREENHEIGHT, 0, "Okay sure, bring me to the tower.");
    }
    else if (count > 2800 && count < 3120)
    {
        princeX -= 1;
    }
    else if (count > 3320 && count < 3370)
    {
        princeX += 1;
    }
    else if (count > 3370 && count < 3470)
    {
        drawstring(princeX, princeY + 0.3 * SCREENHEIGHT, 0, "?>@#$%^");
    }
    else if (count > 3570 && count < 3640)
    {

        magicX += 6;
        magicY += 5.5;
        drawMagic(princeX + magicX, princeY + magicY, 1);
    }
    else if (count > 3750 && count < 3850)
    {

        drawstring(princeX, princeY + 0.3 * SCREENHEIGHT, 0, "You are not suppose to hurt anyone with your magic.");
    }
    else if (count > 4250 && count < 4350)
    {
        drawstring(princeX, princeY + 0.3 * SCREENHEIGHT, 0, "It 's nothing, do you want to follow me to my castle?");
    }
    else if (count > 4450 && count < 4550)
    {
        drawstring(princeX, princeY + 0.3 * SCREENHEIGHT, 0, "Okayyy byeee");
    }
    else if (count > 4600 && count < 4700)
    {
        princeX -= 3;
    }
}

void horseController()
{
    if (count == 0)
    {
        horseX = -150;
        horseY = 0.15 * SCREENHEIGHT;
    }
    else if (count > 1450 && count < 1550)
    {
        horseX += 8;
    }
    else if (count > 1550 && count < 1650)
    {
        drawstring(horseX, horseY + 0.2 * SCREENHEIGHT, 0, "hi, why are you in a hurry, anything that I can help?");
    }
    else if (count > 1750 && count < 1850)
    {
        drawstring(horseX, horseY + 0.2 * SCREENHEIGHT, 0, "Ohhh, I think I know who can help you. My master, the prince of M country, he know magic.");
    }
    else if (count > 1950 && count < 2050)
    {

        drawstring(horseX, horseY + 0.2 * SCREENHEIGHT, 0, " Sure!! Follow me!!");
    }
    else if (count > 2050 && count < 2100)
    {
        horseRot = -1;
    }
    else if (count > 2350 && count < 2450)
    {
        drawstring(horseX, horseY + 0.2 * SCREENHEIGHT, 0, "Master!! Kangaroo needs your help!");
    }
    else if (count > 2550 && count < 2650)
    {
        drawstring(horseX, horseY + 0.2 * SCREENHEIGHT, 0, " Its friend is locked by the witch in a tower.");
    }
    else if (count > 2750 && count < 2800)
    {
        horseRot = 1;
    }
    else if (count > 2800 && count < 3120)
    {
        horseX -= 1;
    }
    else if (count > 4550 && count < 4600)
    {
        horseRot = -1;
    }
    else if (count > 4600)
    {
        horseX -= 5;
    }
}

void drawScene1()
{
    drawGround(dx, dy);
    drawSky(dx, dy);

    drawMountain(0 + dx, 0.6 * SCREENHEIGHT + dy, 1);
    drawMountain(0.2 * SCREENWIDTH + 0.05 * dx, 0.6 * SCREENHEIGHT + dy, 0.7);
    drawMountain(0.7 * SCREENWIDTH + 0.05 * dx, 0.6 * SCREENHEIGHT + dy, 1.3);
    drawMountain(0.4 * SCREENWIDTH + 0.05 * dx, 0.6 * SCREENHEIGHT + dy, 0.8);

    drawRiver(riverX, riverY, 1);
    riverController();

    drawTree(0.45 * SCREENWIDTH + 0.1 * dx, 0.55 * SCREENHEIGHT + dy, 0.2);
    drawTree(0.4 * SCREENWIDTH + 0.1 * dx, 0.5 * SCREENHEIGHT + dy, 0.2);
    drawTree(0.2 * SCREENWIDTH + 0.1 * dx, 0.5 * SCREENHEIGHT + dy, 0.3);
    drawTree(0.05 * SCREENWIDTH + 0.1 * dx, 0.4 * SCREENHEIGHT + dy, 0.3);
    drawTree(0.25 * SCREENWIDTH + 0.1 * dx, 0.4 * SCREENHEIGHT + dy, 0.3);
    drawTree(0.05 * SCREENWIDTH + 0.1 * dx, 0.2 * SCREENHEIGHT + dy, 0.5);
    drawTree(0.7 * SCREENWIDTH + 0.1 * dx, 0.3 * SCREENHEIGHT + dy, 0.8);
    drawTree(0.3 * SCREENWIDTH + 0.1 * dx, 0.3 * SCREENHEIGHT + dy, 0.5);
    drawTree(0.55 * SCREENWIDTH + 0.1 * dx, 0.2 * SCREENHEIGHT + dy, 1);
    drawTree(0.1 * SCREENWIDTH + 0.1 * dx, 0.3 * SCREENHEIGHT + dy, 0.5);
    drawTree(0.4 * SCREENWIDTH + 0.1 * dx, 0.2 * SCREENHEIGHT + dy, 0.7);

    drawFlower(0 + 1.5 * dx, 0 + dy, 0.7);

    drawHouse(houseX, houseY, 1.1);
    houseController();

    drawTower(towerX + dx, towerY, 1);
    towerController();

    drawHorse(horseX, horseY, 0.7, horseRot);
    horseController();

    drawPrincess(princessX + dx, princessY + dy, 0.45);
    princessController();

    drawPrince(princeX, princeY, 0.7);
    princeController();

    drawWitch(witchMoveX + dx, witchMoveY + dy, 0.3);
    drawBroom(witchMoveX + dx, witchMoveY + dy, 0.3);
    witchController();

    drawKangaroo(kangarooX, kangarooY, 0.4, kangarooRot);
    kangarooController();
}

void drawBackground()
{
    drawSky(dx, dy);

    drawGround(dx, dy);

    drawMountain(300, 300, 1);

    drawTree(100, 250, 0.5);

    drawHorse(300, 100, 1, 1);
    drawHorse(300, 100, 1, -1);

    drawMagic(100, 100, 1);

    // drawTower(200, 50, 1.2);

    // drawPrince(100, 100, 1);

    // drawArrow(300, 300, 1, arrowAngle);

    // drawPrincess(200, 200, 0.5);
    // drawHouse(220, 50, 1.1);

    // drawHorse(200, 0.6 * SCREENHEIGHT, 0.5);
    // drawFlower(30, 30, 0.7);
    // drawRiver(0,0.6*SCREENHEIGHT,1);
    // glRectf(100,100,200,200);
}

// void drawScene2()
// {
//     drawKangaroo(kangarooX, kangarooY, 0.5);
// }

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);
    glLineWidth(4.0);

    drawScene1();
    sceneController();
    // drawBackground();

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
    // kangarooInitX += dx;
    // dy = dy + 0.15;
    // kangarooInitY = pow(10 * sin(dy), 2);
    count += 2;
    std::cout << count << "\n";

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
