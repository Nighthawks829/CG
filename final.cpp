#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include <cmath>

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

void drawBroom(double X, double Y, double scale);
void drawCircle(double cx, double cy, double r, int num_segments);
void drawCircle(double cx, double cy, double r, int num_segments);
void drawEllipse(double centerX, double centerY, double radiusX, double radiusY, int numVertices);
void drawFlower(double X, double Y, double scale);
void drawGround(float dx, float dy);
void drawHalfEllipse(double centerX, double centerY, double radiusX, double radiusY, int numVertices);
void drawHorse(double X, double Y, double scale, int rot);
void drawHouse(double X, double Y, double scale);
void drawInverseHorse(double X, double Y, double scale);
void drawEllipse(double centerX, double centerY, double radiusX, double radiusY, int numVertices);
void drawKangarooInverse(double X, double Y, double scale);
void drawMagic(double X, double Y, double scale);
void drawMountain(double X, double Y, double scale);
void drawPrince(double X, double Y, double scale);
void drawPrincess(double X, double Y, double scale);
void drawRiver(double X, double Y, double scale);
void drawSky(float dx, float dy);
void drawSun(float cx, float cy, float r, int num_segments);
void drawWitch(double X, double Y, double scale);
void drawTower(double X, double Y, double scale);
void drawTree(double X, double Y, double scale);
void drawWitch(double X, double Y, double scale);

void drawBroom(double X, double Y, double scale)
{
    double scaleX = 300;
    double scaleY = 150;

    scaleX *= scale;
    scaleY *= scale;
    // broom
    glColor3ub(106, 52, 14);
    glRectf(X, Y, X + 0.8 * scaleX, Y - 0.15 * scaleY);

    glColor3ub(221, 223, 35);
    glBegin(GL_POLYGON);
    glVertex2f(X + 0.8 * scaleX, Y - 0.22 * scaleY);
    glVertex2f(X + 0.8 * scaleX, Y + 0.07 * scaleY);
    glVertex2f(X + 0.9 * scaleX, Y + 0.22 * scaleY);
    glVertex2f(X + 0.9 * scaleX, Y - 0.37 * scaleY);

    glEnd();
}

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

void drawFlower(double X, double Y, double scale)
{
    double scaleX = 200;
    double scaleY = 200;

    scaleX *= scale;
    scaleY *= scale;

    // Start leaf 1
    glPushMatrix();
    glColor3ub(92, 169, 4);
    drawCircle(X + 0.4 * scaleX, Y + 0.3 * scaleY, 0.3 * scaleX, 200);
    glPopMatrix();
    // End leaf 1

    // Start leaf 2
    glPushMatrix();
    glColor3ub(92, 169, 4);
    drawCircle(X + 0.3 * scaleX + 0.4 * scaleX, Y + 0.2 * scaleY, 0.2 * scaleX, 200);
    glPopMatrix();
    // End leaf 2

    // Start cut leaf
    glPushMatrix();
    glColor3ub(0, 154, 23);
    glRectf(X, Y, X + 0.9 * scaleX, Y + 0.1 * scaleY);
    glPopMatrix();
    // End cut leaf

    // Start flower
    glPushMatrix();
    glColor3ub(255, 0, 0);
    drawCircle(X + 0.3 * scaleX, Y + 0.4 * scaleY, 0.02 * scaleX, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 0);
    drawCircle(X + 0.5 * scaleX, Y + 0.3 * scaleY, 0.02 * scaleX, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 0);
    drawCircle(X + 0.8 * scaleX, Y + 0.3 * scaleY, 0.02 * scaleX, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 0, 0);
    drawCircle(X + 0.7 * scaleX, Y + 0.2 * scaleY, 0.02 * scaleX, 100);
    glPopMatrix();
}

void drawGround(float dx, float dy)
{
    glColor3ub(0, 154, 23);
    glRectf(0, 0, SCREENWIDTH, 0.6 * SCREENHEIGHT);
}

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

void drawHouse(double X, double Y, double scale)
{
    double scaleX = 250;
    double scaleY = 200;

    scaleX *= scale;
    scaleY *= scale;

    // side roof
    glColor3ub(132, 75, 45);
    glBegin(GL_POLYGON);
    glVertex2f(X + 0.2 * scaleX, Y + 0.6 * scaleY);
    glVertex2f(X + 0.2 * scaleX, Y + 0.9 * scaleY);
    glVertex2f(X + 0.8 * scaleX, Y + 0.9 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y + 0.6 * scaleY);
    glEnd();

    // main door wall
    glColor3ub(206, 52, 42);
    glRectf(X + 0.1 * scaleX, Y, X + 0.3 * scaleX, Y + 0.8 * scaleY);

    // main door roof
    glBegin(GL_TRIANGLES);
    glColor3ub(184, 107, 63);
    glVertex2f(X, Y + 0.8 * scaleY);
    glVertex2f(X + 0.2 * scaleX, Y + 1.0 * scaleY);
    glVertex2f(X + 0.4 * scaleX, Y + 0.8 * scaleY);
    glEnd();

    // main door
    glColor3ub(130, 73, 11);
    glRectf(X + 0.17 * scaleX, Y, X + 0.23 * scaleX, Y + 0.2 * scaleY);

    // main door window
    glColor3ub(225, 235, 227);
    glRectf(X + 0.17 * scaleX, Y + 0.5 * scaleY, X + 0.23 * scaleX, Y + 0.6 * scaleY);

    // side wall
    glColor3ub(177, 44, 35);
    glRectf(X + 0.3 * scaleX, Y, X + 1.0 * scaleX, Y + 0.6 * scaleY);

    // side window
    glColor3ub(225, 235, 227);
    glRectf(X + 0.4 * scaleX, Y + 0.2 * scaleY, X + 0.9 * scaleX, Y + 0.35 * scaleY);
}

void drawKangaroo(double X, double Y, double scale, int rot)
{
    double scaleX = 300;
    double scaleY = 250;

    scaleX *= scale;
    scaleY *= scale;

    if (rot == -1)
    {
        drawKangarooInverse(X, Y, scale);
        return;
    }

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

void drawKangarooInverse(double X, double Y, double scale)
{
    double scaleX = 300;
    double scaleY = 250;

    scaleX = scaleX * scale;
    scaleY = scaleY * scale;

    // boder
    // glColor3ub(0, 0, 0);
    // glRectf(X, Y, X + scaleX, Y + scaleY);
    // Start right ear
    glPushMatrix();
    glTranslatef(X + 1 - 0.725 * scaleX, Y + 0.8 * scaleY, 0.0);
    glRotatef(360 - 50, 0, 0, 1);
    glColor3ub(133, 99, 64);
    glRectf(1 - 0, 0, 1 - 0.25 * scaleX, 0.03 * scaleY);
    glPopMatrix();
    // End right ear

    // Start right leg
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 1 - 0.60 * scaleX, Y + 0.09 * scaleY, X + 1 - 0.7 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // End left leg

    // Start right feet
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 1 - 0.6 * scaleX, Y + 0.09 * scaleY, X + 1 - 0.75 * scaleX, Y + 0.14 * scaleY);
    glPopMatrix();
    // End right feet

    // Start right hand
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glTranslatef(X + 1 - 0.75 * scaleX, Y + 0.43 * scaleY, 0.0);
    glRotatef(60, 0, 0, 1);
    glRectf(1 - 0, 0, 1 - 0.2 * scaleX, 0.03 * scaleX);
    glPopMatrix();
    // End right hand

    // Start right paw
    glPushMatrix();
    glColor3ub(90, 79, 71);
    glRectf(X + 1 - 0.75 * scaleX, Y + 0.09 * scaleY, X + 1 - 0.8 * scaleX, Y + 0.14 * scaleY);
    glPopMatrix();
    // End right paw

    // Start dummy
    glPushMatrix();
    glTranslatef(X + 1 - 0.6 * scaleX, Y + 0.33 * scaleY, 0.0);
    glRotatef(335, 0, 0, 1);
    glColor3ub(162, 155, 125);
    drawEllipse(1 - 0, 1 - 0, 0.15 * scaleX, 0.12 * scaleY, 100);
    glPopMatrix();
    // End dummy

    // Start tail
    glPushMatrix();
    glColor3ub(145, 113, 76);
    glRectf(X, Y + 0.2 * scaleY, X + 1 - 0.2 * scaleX, Y + 0.25 * scaleY);
    glPopMatrix();
    // End tail

    // Start tail second part
    glPushMatrix();
    glTranslatef(X + 1 - 0.2 * scaleX, Y + 0.175 * scaleY, 0.0);
    glRotatef(340, 0, 0, 1);
    glRectf(1.0, 0.0, 1 - 0.2 * scaleX, 0.1 * scaleY);
    // End tail second part

    // Start body
    glRectf(1 - 0.2 * scaleX, 0 - 0.05 * scaleY, 1 - 0.65 * scaleX, 0.15 * scaleY);
    // End body

    glPopMatrix();
    // End tail second part

    // Start left leg
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 1 - 0.45 * scaleX, Y, X + 1 - 0.55 * scaleX, Y + 0.3 * scaleY);
    glPopMatrix();
    // End left leg

    // Start left feet
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 1 - 0.45 * scaleX, Y, X + 1 - 0.65 * scaleX, Y + 0.05 * scaleY);
    glPopMatrix();
    // End left feet

    // Start left paw
    glPushMatrix();
    glColor3ub(90, 79, 71);
    glRectf(X + 1 - 0.65 * scaleX, Y, X + 1 - 0.7 * scaleX, Y + 0.05 * scaleY);
    glPopMatrix();
    // End left paw

    // Start neck
    glPushMatrix();
    glColor3ub(137, 105, 67);
    glRectf(X + 1 - 0.65 * scaleX, Y + 0.45 * scaleY, X + 1 - 0.8 * scaleX, Y + 0.65 * scaleY);
    glPopMatrix();
    // End neck

    // Start left hand
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glTranslatef(X + 1 - 0.72 * scaleX, Y + 0.4 * scaleY, 0.0);
    glRotatef(60, 0, 0, 1);
    glRectf(1 - 0 * scaleX, 0, 1 - 0.2 * scaleX, 0.03 * scaleX);
    glPopMatrix();
    // End left hand

    // Start head
    glPushMatrix();
    glColor3ub(133, 99, 64);
    glRectf(X + 1 - 0.65 * scaleX, Y + 0.65 * scaleY, X - scaleX, Y + 0.8 * scaleY);
    glPopMatrix();
    // End head

    // Start eye
    glPushMatrix();
    glColor3ub(13, 10, 7);
    glRectf(X + 1 - 0.75 * scaleX, Y + 0.75 * scaleY, X + 1 - 0.8 * scaleX, Y + 0.78 * scaleY);
    glPopMatrix();
    // End eye

    // Start Noise
    glPushMatrix();
    glColor3ub(64, 54, 49);
    glRectf(X + 1 - 0.95 * scaleX, Y + 0.75 * scaleY, X + 1 - 1 * scaleX, Y + 0.8 * scaleY);
    glPopMatrix();
    // End Noise

    // Start left ear
    glPushMatrix();
    glTranslatef(X + 1 - 0.725 * scaleX, Y + 0.8 * scaleY, 0.0);
    glRotatef(230, 0, 0, 1);
    glColor3ub(133, 99, 64);
    glRectf(1 - 0 * scaleX, 0, 1 - 0.25 * scaleX, 0.05 * scaleY);
    glPopMatrix();
    // End left ear
    glPopMatrix();
}

void drawMagic(double X, double Y, double scale)
{

    double scaleX = 200;
    double scaleY = 100;

    scaleX *= scale;
    scaleY *= scale;

    glPushMatrix();
    glColor3ub(247, 87, 0);
    drawCircle(X + 0.5 * scaleX, Y + 0.5 * scaleY, 0.05 * scaleX, 100);
    glPopMatrix();
}

void drawMountain(double X, double Y, double scale)
{
    double scaleX = 150;
    double scaleY = 100;

    scaleX *= scale;
    scaleY *= scale;

    glBegin(GL_TRIANGLES);
    glColor3ub(0.0, 255.0, 0.0);
    glVertex2f(X, Y);
    glVertex2f(X + 0.5 * scaleX, Y + 1.0 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y);
    glEnd();
}

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

void drawRiver(double X, double Y, double scale)
{
    double scaleX = 300;
    double scaleY = 300;

    glPushMatrix();
    glColor3ub(28, 163, 236);
    drawHalfEllipse(X, Y, 0.5 * scaleX, 0.3 * scaleY, 200);
    glPopMatrix();
}

void drawSky(float dx, float dy)
{
    glColor3ub(135, 206, 235);
    glRectf(0, 0.6 * SCREENHEIGHT, SCREENWIDTH, SCREENHEIGHT);
    drawSun(20, 450, 50, 300);
}

void drawSun(float cx, float cy, float r, int num_segments)
{

    float t;
    int i;
    glColor3ub(239, 142, 56);
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

void drawTower(double X, double Y, double scale)
{
    double scaleX = 200;
    double scaleY = 400;

    scaleX = scaleX * scale;
    scaleY = scaleY * scale;

    // border
    // glPushMatrix();
    // glColor3ub(0, 0, 0);
    // glRectf(X, Y, X + scaleX, Y + scaleY);
    // glPopMatrix();

    // base
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(181, 72, 58);
    glVertex2f(X, Y);
    glVertex2f(X + 1.0 * scaleX, Y);
    glVertex2f(X + 0.9 * scaleX, Y + 0.2 * scaleY);
    glVertex2f(X + 0.1 * scaleX, Y + 0.2 * scaleY);
    glEnd();
    glPopMatrix();

    // body
    glPushMatrix();
    glColor3ub(136, 140, 141);
    glRectf(X + 0.1 * scaleX, Y + 0.2 * scaleY, X + 0.9 * scaleX, Y + 0.6 * scaleY);
    glPopMatrix();

    // edge
    glPushMatrix();
    glColor3ub(203, 65, 84);
    glRectf(X, Y + 0.6 * scaleY, X + scaleX, Y + 0.65 * scaleY);
    glPopMatrix();

    // room outside
    glPushMatrix();
    glColor3ub(136, 140, 141);
    glRectf(X + 0.1 * scaleX, Y + 0.65 * scaleY, X + 0.9 * scaleX, Y + 0.85 * scaleY);
    glPopMatrix();

    // room
    glPushMatrix();
    glColor3ub(175, 154, 119);
    glRectf(X + 0.15 * scaleX, Y + 0.65 * scaleY, X + 0.85 * scaleX, Y + 0.82 * scaleY);
    glPopMatrix();

    // roof
    glPushMatrix();
    glColor3ub(157, 96, 85);
    glBegin(GL_TRIANGLES);
    glVertex2f(X + 0.1 * scaleX, Y + 0.85 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + scaleY);
    glVertex2f(X + 0.9 * scaleX, Y + 0.85 * scaleY);
    glEnd();
    glPopMatrix();
}

void drawTree(double X, double Y, double scale)
{
    double scaleX = 150;
    double scaleY = 300;

    scaleX *= scale;
    scaleY *= scale;

    // trunk
    glColor3ub(102, 51, 0);
    glRectf(X + 0.4 * scaleX, Y, X + 0.6 * scaleX, Y + 0.2 * scaleY);

    // 3 layer leaf
    glBegin(GL_TRIANGLES);
    glColor3ub(0.0, 200, 0.0);
    glVertex2f(X, Y + 0.2 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + 0.45 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y + 0.2 * scaleY);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0.0, 200, 0.0);
    glVertex2f(X, Y + 0.4 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + 0.65 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y + 0.4 * scaleY);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0.0, 200, 0.0);
    glVertex2f(X, Y + 0.6 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + 0.85 * scaleY);
    glVertex2f(X + 1.0 * scaleX, Y + 0.6 * scaleY);
    glEnd();
}

void drawWitch(double X, double Y, double scale)
{
    double scaleX = 150;
    double scaleY = 300;

    scaleX *= scale;
    scaleY *= scale;

    // feet
    glColor3ub(96, 69, 50);
    glRectf(X + 0.3 * scaleX, Y, X + 0.7 * scaleX, Y + 0.1 * scaleY);

    // hair
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(X + 0.1 * scaleX, Y + 0.35 * scaleY);
    glVertex2f(X + 0.2 * scaleX, Y + 0.8 * scaleY);
    glVertex2f(X + 0.8 * scaleX, Y + 0.8 * scaleY);
    glVertex2f(X + 0.9 * scaleX, Y + 0.35 * scaleY);
    glEnd();

    // leg
    glColor3ub(55, 0, 166);
    glRectf(X + 0.25 * scaleX, Y + 0.1 * scaleY, X + 0.75 * scaleX, Y + 0.35 * scaleY);

    // shirt
    glColor3ub(55, 0, 166);
    glRectf(X, Y + 0.35 * scaleY, X + 1.0 * scaleX, Y + 0.55 * scaleY);

    // zip
    glColor3ub(0, 51, 12);
    glRectf(X + 0.45 * scaleX, Y + 0.1 * scaleY, X + 0.55 * scaleX, Y + 0.35 * scaleY);

    // hand
    glColor3ub(26, 0, 81);
    glRectf(X, Y + 0.35 * scaleY, X + 1.0 * scaleX, Y + 0.4 * scaleY);

    // sleeve
    glColor3ub(18, 0, 56);
    glRectf(X + 0.45 * scaleX, Y + 0.35 * scaleY, X + 0.55 * scaleX, Y + 0.55 * scaleY);

    // face
    glColor3ub(209, 180, 152);
    glRectf(X + 0.25 * scaleX, Y + 0.55 * scaleY, X + 0.75 * scaleX, Y + 0.80 * scaleY);

    // eyebrow
    glColor3ub(0, 0, 0);
    glRectf(X + 0.28 * scaleX, Y + 0.75 * scaleY, X + 0.72 * scaleX, Y + 0.77 * scaleY);

    // left eye
    glColor3ub(98, 89, 79);
    glRectf(X + 0.35 * scaleX, Y + 0.69 * scaleY, X + 0.40 * scaleX, Y + 0.72 * scaleY);

    // right eye
    glColor3ub(98, 89, 79);
    glRectf(X + 0.6 * scaleX, Y + 0.69 * scaleY, X + 0.65 * scaleX, Y + 0.72 * scaleY);

    // nose
    glColor3ub(140, 71, 71);
    glRectf(X + 0.45 * scaleX, Y + 0.59 * scaleY, X + 0.55 * scaleX, Y + 0.69 * scaleY);

    // hat
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(X + 0.1 * scaleX, Y + 0.8 * scaleY);
    glVertex2f(X + 0.5 * scaleX, Y + 1 * scaleY);
    glVertex2f(X + 0.9 * scaleX, Y + 0.8 * scaleY);
    glEnd();

    // emerland
    glColor3ub(0, 105, 25);
    glRectf(X + 0.4 * scaleX, Y + 0.82 * scaleY, X + 0.6 * scaleX, Y + 0.87 * scaleY);
}

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

void drawScene()
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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);
    glLineWidth(4.0);

    drawScene();
    sceneController();

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
    // std::cout << count << "\n";

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