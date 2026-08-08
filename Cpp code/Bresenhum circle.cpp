#include <iostream>
#include <graphics.h>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    int gd = DETECT, gm;
    int x, y, xc, yc, r, p, xmax, ymax;

    cout << "--- Bresenham's Circle Drawing Algorithm ---" << endl;
    cout << "Input center of the circle (xc yc): ";
    cin >> xc >> yc;

    cout << "Input the radius of the circle (r): ";
    cin >> r;

    initgraph(&gd, &gm, "");

    xmax = getmaxx();
    ymax = getmaxy();

    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);

    p = 3 - (2 * r);
    x = 0;
    y = r;

    while (x <= y) {
        putpixel((xmax / 2 + xc + x), (ymax / 2 - yc + y), WHITE);
        putpixel((xmax / 2 + xc - x), (ymax / 2 - yc + y), WHITE);
        putpixel((xmax / 2 + xc + x), (ymax / 2 - yc - y), WHITE);
        putpixel((xmax / 2 + xc - x), (ymax / 2 - yc - y), WHITE);
        putpixel((xmax / 2 + xc + y), (ymax / 2 - yc + x), WHITE);
        putpixel((xmax / 2 + xc - y), (ymax / 2 - yc + x), WHITE);
        putpixel((xmax / 2 + xc + y), (ymax / 2 - yc - x), WHITE);
        putpixel((xmax / 2 + xc - y), (ymax / 2 - yc - x), WHITE);

        if (p < 0) {
            x = x + 1;
            p = p + (4 * x) + 6;
        } else {
            x = x + 1;
            y = y - 1;
            p = p + (4 * (x - y)) + 10;
        }
    }

    getch();
    closegraph();
    return 0;
}