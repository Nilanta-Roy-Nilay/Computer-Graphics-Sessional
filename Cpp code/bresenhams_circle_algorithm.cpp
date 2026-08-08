#include <graphics.h>
#include <iostream>
using namespace std;

void drawCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc+x, yc+y, WHITE);
    putpixel(xc-x, yc+y, WHITE);
    putpixel(xc+x, yc-y, WHITE);
    putpixel(xc-x, yc-y, WHITE);
    putpixel(xc+y, yc+x, WHITE);
    putpixel(xc-y, yc+x, WHITE);
    putpixel(xc+y, yc-x, WHITE);
    putpixel(xc-y, yc-x, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initwindow(800, 600, (char*)"Bresenham Circle Drawing");

    int xc, yc, r;
    cout << "Enter center (xc yc) and radius r: ";
    cin >> xc >> yc >> r;

    int x = 0, y = r;
    int p = 3 - 2*r;

    while (x <= y) {
        drawCirclePoints(xc, yc, x, y);
        if (p < 0) {
            p += 4*x + 6;
        } else {
            p += 4*(x - y) + 10;
            y--;
        }
        x++;
    }

    outtextxy(50, 30, (char*)"Bresenham Circle");
    getch();
    closegraph();
}
