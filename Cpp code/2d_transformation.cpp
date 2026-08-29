#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Base rectangle coordinates
    int x1=100, y1=100;
    int x2=200, y2=100;
    int x3=200, y3=200;
    int x4=100, y4=200;

    // Draw original rectangle
    setcolor(WHITE);
    rectangle(x1, y1, x3, y3);

    // --- Translation ---
    int tx=100, ty=50;
    setcolor(GREEN);
    rectangle(x1+tx, y1+ty, x3+tx, y3+ty);

    // --- Scaling ---
    float sx=1.5, sy=2.0;
    setcolor(BLUE);
    rectangle((int)(x1*sx), (int)(y1*sy), (int)(x3*sx), (int)(y3*sy));

    // --- Rotation (about origin) ---
    float angle=30; // degrees
    float rad=angle*3.1416/180;
    int nx1=x1*cos(rad)-y1*sin(rad);
    int ny1=x1*sin(rad)+y1*cos(rad);
    int nx2=x2*cos(rad)-y2*sin(rad);
    int ny2=x2*sin(rad)+y2*cos(rad);
    int nx3=x3*cos(rad)-y3*sin(rad);
    int ny3=x3*sin(rad)+y3*cos(rad);
    int nx4=x4*cos(rad)-y4*sin(rad);
    int ny4=x4*sin(rad)+y4*cos(rad);
    setcolor(RED);
    line(nx1,ny1,nx2,ny2);
    line(nx2,ny2,nx3,ny3);
    line(nx3,ny3,nx4,ny4);
    line(nx4,ny4,nx1,ny1);

    // --- Reflection about X-axis ---
    setcolor(CYAN);
    rectangle(x1, -y1, x3, -y3);

    // --- Shearing (x-direction) ---
    int shx=1;
    int sx1=x1+shx*y1;
    int sx2=x2+shx*y2;
    int sx3=x3+shx*y3;
    int sx4=x4+shx*y4;
    setcolor(MAGENTA);
    line(sx1,y1,sx2,y2);
    line(sx2,y2,sx3,y3);
    line(sx3,y3,sx4,y4);
    line(sx4,y4,sx1,y1);

    getch();
    closegraph();
    return 0;
}
