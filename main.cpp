#include <GL/glut.h>
#include <cmath>
#include <string>
int n = 360;

int i1 = 0;
int speed1 = 16;
float x = 0.0;
float y = 550.0;
float radius1 = 2.6;

int i2 = 0;
int speed2 = 48;
float x2 = 0.0;
float y2 = 615.0;
float radius2 = 3.70;

int i3 = 0;
int speed3 = 64;
float x3 = 0.0;
float y3 = 685.0;
float radius3 = 5.1;

int i4 = 0;
int speed4 = 96;
float x4 = 0.0;
float y4 = 765.0;
float radius4 = 6.5;	

int i5 = 0;
int speed5 = 128;
float x5 = 0.0;
float y5 = 870.0;
float radius5 = 8.4;

int i6 = 0;
int speed6 = 160;
float x6 = 0.0;
float y6 = 990.0;
float radius6 = 10.5;

int i7 = 0;
int speed7 = 192;
float x7 = 0.0;
float y7 = 1100.0;
float radius7 = 12.3;

int i8 = 0;
int speed8 = 224;
float x8 = 0.0;
float y8 = 1210.0;
float radius8 = 14.1;

int i9 = 0;
int speed9 = 256;
float x9 = 0.0;
float y9 = 1300.0;
float radius9 = 15.5;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 960, 0, 720);
}

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawFilledBresenhamCircle(int centerX, int centerY, int radius, 
                               float r, float g, float b) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    glColor3f(r, g, b);
    while (x <= y) {
        for (int i = centerX - x; i <= centerX + x; i++) {
            drawPixel(i, centerY + y);
            drawPixel(i, centerY - y);
        }
        for (int i = centerX - y; i <= centerX + y; i++) {
            drawPixel(i, centerY + x);
            drawPixel(i, centerY - x);
        }
        if (d < 0)
            d += 4 * x + 6;
        else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void drawBresenhamCircleOutline(int centerX, int centerY, int radius, 
                                float r, float g, float b) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    glColor3f(r, g, b);
    while (x <= y) {
        drawPixel(centerX + x, centerY + y);
        drawPixel(centerX - x, centerY + y);
        drawPixel(centerX + x, centerY - y);
        drawPixel(centerX - x, centerY - y);
        drawPixel(centerX + y, centerY + x);
        drawPixel(centerX - y, centerY + x);
        drawPixel(centerX + y, centerY - x);
        drawPixel(centerX - y, centerY - x);
        
        if (d < 0)
            d += 4 * x + 6;
        else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, 
                  float y3,float red, float green, float blue) {
    glBegin(GL_TRIANGLES);
    glColor3f(red, green, blue);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}

void drawText(float x, float y, std::string text, float red,
              float green, float blue) {
    glColor3f(red, green, blue);
    glRasterPos2f(x, y);

    for (int i = 0; i < text.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void drawEllipse(float centerX, float centerY, float radiusX, 
        float radiusY, float red, float green, float blue) {
    glBegin(GL_POINTS); 
    glColor3f(red, green, blue);

    for (float angle = 0; angle <= 180; angle += 0.1) { 
        float radians = angle * (3.14159265 / 180.0);

        float x = centerX + radiusX * cos(radians);
        float y = centerY - radiusY * sin(radians); 
        glVertex2f(x, y);
    }

    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);  
    
    // Sun
    drawFilledBresenhamCircle(0, 400, 100, 1.0, 1.0, 0.0);
    drawText(0, 510, "Sun", 1.0, 1.0, 1.0);
    
    // Mercury Orbit
    drawBresenhamCircleOutline(0, 400, 150.0, 1.0, 1.0, 1.0);
    // Mercury
    drawFilledBresenhamCircle(x, y, 15, 0.5, 0.5, 0.5);
    drawText(x + 20, y + 20, "Mercury", 1.0, 1.0, 1.0);
    
    // Venus Orbit
    drawBresenhamCircleOutline(0, 400, 210, 1.0, 1.0, 1.0);
    // Venus
    drawFilledBresenhamCircle(x2, y2, 22, 1.0, 0.5, 0.0);
    drawText(x2 + 20, y2 + 20, "Venus", 1.0, 1.0, 1.0);

    // Earth Orbit
    drawBresenhamCircleOutline(0, 400, 290, 1.0, 1.0, 1.0);
    // Earth
    drawFilledBresenhamCircle(x3, y3, 30, 0.0, 0.0, 1.0);
    drawText(x3 + 25, y3 + 25, "Earth", 1.0, 1.0, 1.0);

    // Mars Orbit
    drawBresenhamCircleOutline(0, 400, 370, 1.0, 1.0, 1.0);
    // Mars
    drawFilledBresenhamCircle(x4, y4, 26, 1.0, 0.0, 0.0);
    drawText(x4 + 20, y4 + 20, "Mars", 1.0, 1.0, 1.0);
    
    // Jupiter Orbit
    drawBresenhamCircleOutline(0, 400, 480, 1.0, 1.0, 1.0);
    // Jupiter
    drawFilledBresenhamCircle(x5, y5, 55, 0.4, 0.2, 0.0);
    drawText(x5 + 40, y5 + 40, "Jupiter", 1.0, 1.0, 1.0);
    
    // Saturn Orbit
    drawBresenhamCircleOutline(0, 400, 600, 1.0, 1.0, 1.0);
    // Saturn
    drawFilledBresenhamCircle(x6, y6, 43, 0.5, 0.25, 0.0);
    drawText(x6 + 30, y6 + 30, "Saturn", 1.0, 1.0, 1.0);
    // Saturn ring
    drawEllipse(x6, y6, 60, 30, 1.0, 1.0, 0.0);
    
    // Uranus Orbit
    drawBresenhamCircleOutline(0, 400, 700, 1.0, 1.0, 1.0);
    // Uranus
    drawFilledBresenhamCircle(x7, y7, 40, 0.0, 0.5, 1.0);
    drawText(x7 + 30, y7 + 30, "Uranus", 1.0, 1.0, 1.0);
    
    // Neptune Orbit
    drawBresenhamCircleOutline(0, 400, 800, 1.0, 1.0, 1.0);
    // Neptune
    drawFilledBresenhamCircle(x8, y8, 30, 0.0, 0.0, 0.5);
    drawText(x8 + 25, y8 + 25, "Neptune", 1.0, 1.0, 1.0);
    
    // Pluto Orbit
    drawBresenhamCircleOutline(0, 400, 880, 1.0, 1.0, 1.0);
    // Pluto
    drawFilledBresenhamCircle(x9, y9, 16, 0.1, 0.1, 0.0);
    drawText(x9 + 20, y9 + 20, "Pluto", 1.0, 1.0, 1.0);
     
    // Stars
    drawTriangle(530.0f, 360.0f, 540.0f, 360.0f, 535.0f, 368.0f, 1.0f, 1.0f, 1.0f);
    drawTriangle(530.0f, 365.0f, 540.0f, 365.0f, 535.0f, 357.0f, 1.0f, 1.0f, 1.0f);
    
    drawTriangle(900.0f, 60.0f, 910.0f, 60.0f, 905.0f, 68.0f, 1.0f, 1.0f, 1.0f);
    drawTriangle(900.0f, 65.0f, 910.0f, 65.0f, 905.0f, 57.0f, 1.0f, 1.0f, 1.0f);

    drawTriangle(300.0f, 260.0f, 310.0f, 260.0f, 305.0f, 268.0f, 1.0f, 1.0f, 1.0f);
    drawTriangle(300.0f, 265.0f, 310.0f, 265.0f, 305.0f, 257.0f, 1.0f, 1.0f, 1.0f);
    
    drawTriangle(250.0f, 80.0f, 260.0f, 80.0f, 255.0f, 88.0f, 1.0f, 1.0f, 1.0f);
    drawTriangle(250.0f, 85.0f, 260.0f, 85.0f, 255.0f, 77.0f, 1.0f, 1.0f, 1.0f);

    drawTriangle(710.0f, 160.0f, 720.0f, 160.0f, 715.0f, 168.0f, 1.0f, 1.0f, 1.0f);
    drawTriangle(710.0f, 165.0f, 720.0f, 165.0f, 715.0f, 157.0f, 1.0f, 1.0f, 1.0f);
    
    drawTriangle(730.0f, 560.0f, 740.0f, 560.0f, 735.0f, 568.0f, 1.0f, 1.0f, 1.0f);
    drawTriangle(730.0f, 565.0f, 740.0f, 565.0f, 735.0f, 557.0f, 1.0f, 1.0f, 1.0f);

    drawTriangle(400.0f, 460.0f, 410.0f, 460.0f, 405.0f, 468.0f, 1.0f, 1.0f, 1.0f);
    drawTriangle(400.0f, 465.0f, 410.0f, 465.0f, 405.0f, 457.0f, 1.0f, 1.0f, 1.0f);
    
    drawTriangle(900.0f, 660.0f, 910.0f, 660.0f, 905.0f, 668.0f, 1.0f, 1.0f, 1.0f);
    drawTriangle(900.0f, 665.0f, 910.0f, 665.0f, 905.0f, 657.0f, 1.0f, 1.0f, 1.0f);
    
    drawTriangle(100.0f, 620.0f, 110.0f, 620.0f, 105.0f, 628.0f, 1.0f, 1.0f, 1.0f);
    drawTriangle(100.0f, 625.0f, 110.0f, 625.0f, 105.0f, 617.0f, 1.0f, 1.0f, 1.0f);
    glFlush();
}



void update1(int value) {
    i1 += 1;
    float theta = -2.0f * 3.1415926f * float(i1) / float(n);
    
    float x01 = radius1 * cosf(theta);
    float y01 = radius1 * sinf(theta);
    
    x += x01;
    y += y01;
    
    glutPostRedisplay();
    glutTimerFunc(speed1, update1, 0);
}

void update2(int value) {
    i2 += 1;
    float theta = -2.0f * 3.1415926f * float(i2) / float(n);
    
    float x02 = radius2 * cosf(theta);
    float y02 = radius2 * sinf(theta);

    x2 += x02;
    y2 += y02;
    
    glutPostRedisplay();
    glutTimerFunc(speed2, update2, 0);
}

void update3(int value) {
    i3 += 1;
    float theta = -2.0f * 3.1415926f * float(i3) / float(n);
    
    float x03 = radius3 * cosf(theta);
    float y03 = radius3 * sinf(theta);

    x3 += x03;
    y3 += y03;
    
    glutPostRedisplay();
    glutTimerFunc(speed3, update3, 0);
}

void update4(int value) {
    i4 += 1;
    float theta = -2.0f * 3.1415926f * float(i4) / float(n);
    
    float x04 = radius4 * cosf(theta);
    float y04 = radius4 * sinf(theta);

    x4 += x04;
    y4 += y04;
    
    glutPostRedisplay();
    glutTimerFunc(speed4, update4, 0);
}

void update5(int value) {
    i5 += 1;
    float theta = -2.0f * 3.1415926f * float(i5) / float(n);
    
    float x05 = radius5 * cosf(theta);
    float y05 = radius5 * sinf(theta);

    x5 += x05;
    y5 += y05;
    
    glutPostRedisplay();
    glutTimerFunc(speed5, update5, 0);
}

void update6(int value) {
    i6 += 1;
    float theta = -2.0f * 3.1415926f * float(i6) / float(n);
    
    float x06 = radius6 * cosf(theta);
    float y06 = radius6 * sinf(theta);

    x6 += x06;
    y6 += y06;
    
    glutPostRedisplay();
    glutTimerFunc(speed6, update6, 0);
}

void update7(int value) {
    i7 += 1;
    float theta = -2.0f * 3.1415926f * float(i7) / float(n);
    
    float x07 = radius7 * cosf(theta);
    float y07 = radius7 * sinf(theta);

    x7 += x07;
    y7 += y07;
    
    glutPostRedisplay();
    glutTimerFunc(speed7, update7, 0);
}

void update8(int value) {
    i8 += 1;
    float theta = -2.0f * 3.1415926f * float(i8) / float(n);
    
    float x08 = radius8 * cosf(theta);
    float y08 = radius8 * sinf(theta);

    x8 += x08;
    y8 += y08;
    
    glutPostRedisplay();
    glutTimerFunc(speed8, update8, 0);
}

void update9(int value) {
    i9 += 1;
    float theta = -2.0f * 3.1415926f * float(i9) / float(n);
    
    float x09 = radius9 * cosf(theta);
    float y09 = radius9 * sinf(theta);

    x9 += x09;
    y9 += y09;
    
    glutPostRedisplay();
    glutTimerFunc(speed9, update9, 0);
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(960, 720);
    glutInitWindowPosition(565, 0);
    glutCreateWindow("Solar System");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update1, 0);
    glutTimerFunc(0, update2, 0);
    glutTimerFunc(0, update3, 0);
    glutTimerFunc(0, update4, 0);
    glutTimerFunc(0, update5, 0);
    glutTimerFunc(0, update6, 0);
    glutTimerFunc(0, update7, 0);
    glutTimerFunc(0, update8, 0);
    glutTimerFunc(0, update9, 0);
    
    glutMainLoop();
    return 0;
}

