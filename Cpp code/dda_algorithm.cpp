#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

int main() {
    float x1, y1, x2, y2;
    cout << "Enter first point: ";
    cin >> x1 >> y1;
    cout << "Enter second point: ";
    cin >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xmax = getmaxx(), ymax = getmaxy();

    line(xmax/2, 0, xmax/2, ymax);
    line(0, ymax/2, xmax, ymax/2);

    float dx = x2 - x1;
    float dy = y2 - y1;

    float length;
    if (abs((int)dx) >= abs((int)dy))
        length = abs((int)dx);
    else
        length = abs((int)dy);

    float xi = dx / length;
    float yi = dy / length;

    float x = x1, y = y1;
    for (int i = 0; i <= length; i++) {
        putpixel(xmax/2 + (int)(x+0.5), ymax/2 - (int)(y+0.5), WHITE);
        x += xi; y += yi;
    }

    getch();
    closegraph();
    return 0;
}
