#include <iostream>
#include <graphics.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cout << "Enter first point: ";
    cin >> x1 >> y1;
    cout << "Enter second point: ";
    cin >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float m = (float)(y2 - y1) / (x2 - x1);
    float c = y1 - m * x1;

    for (int x = x1; x <= x2; x++) {
        int y = (int)(m * x + c + 0.5);
        putpixel(x, y, WHITE);
    }

    getch();
    closegraph();
    return 0;
}
