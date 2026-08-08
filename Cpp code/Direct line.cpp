#include <iostream>
#include <graphics.h>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    float x1, y1, x2, y2, m, c, x, y;
    int xmax, ymax;
    int gd = DETECT, gm;

    cout << "--- Direct Line Drawing Algorithm (Equation Method) ---" << endl;
    cout << "Enter first point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter second point (x2 y2): ";
    cin >> x2 >> y2;

    initgraph(&gd, &gm, "");

    xmax = getmaxx();
    ymax = getmaxy();

    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);

    m = (y2 - y1) / (x2 - x1);
    c = y1 - (m * x1);

    if (abs(x2 - x1) >= abs(y2 - y1)) {
        for (x = x1; x <= x2; x++) {
            y = (m * x) + c;
            putpixel((xmax / 2 + (int)round(x)), (ymax / 2 - (int)round(y)), WHITE);
        }
    } else {
        for (y = y1; y <= y2; y++) {
            x = (y - c) / m;
            putpixel((xmax / 2 + (int)round(x)), (ymax / 2 - (int)round(y)), WHITE);
        }
    }

    getch();
    closegraph();
    return 0;
}