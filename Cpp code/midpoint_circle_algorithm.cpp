#include <graphics.h>
#include <iostream>
#include <cmath>
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
    initwindow(800, 600, (char*)"Midpoint Circle Drawing");

    int xc, yc, r;
    cout << "Enter center (xc yc) and radius r: ";
    cin >> xc >> yc >> r;

    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y) {
        drawCirclePoints(xc, yc, x, y);
        x++;
        if (p < 0) {
            p += 2*x + 1;
        } else {
            y--;
            p += 2*(x - y) + 1;
        }
    }

    outtextxy(50, 30, (char*)"Midpoint Circle");
    getch();
    closegraph();
}
