#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

int main() {
    float x1, y1, x2, y2;
    cout << "Enter first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter second point (x2 y2): ";
    cin >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    float xi = dx / steps;
    float yi = dy / steps;

    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xi;
        y += yi;
    }

    getch();
    closegraph();
    return 0;
}
