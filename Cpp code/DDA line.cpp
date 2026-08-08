#include <iostream>
#include <graphics.h>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    float x1, y1, x2, y2, i, xi, yi;
    float x, y, dx, dy, length;
    int xmax, ymax;
    int gd = DETECT, gm;

    cout << "--- DDA Line Drawing Algorithm ---" << endl;
    cout << "Enter first point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter second point (x2 y2): ";
    cin >> x2 >> y2;

    initgraph(&gd, &gm, "");

    xmax = getmaxx();
    ymax = getmaxy();

    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) >= abs(dy)) {
        length = abs(dx);
    } else {
        length = abs(dy);
    }

    xi = dx / length;
    yi = dy / length;

    x = x1;
    y = y1;
    i = 0;

    while (i <= length) {
        putpixel((xmax / 2 + (int)round(x)), (ymax / 2 - (int)round(y)), WHITE);
        x = x + xi;
        y = y + yi;
        i++;
    }

    getch();
    closegraph();
    return 0;
}