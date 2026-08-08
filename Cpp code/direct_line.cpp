#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initwindow(800, 600, (char*)"Direct Line Drawing Algorithm");

    int x1, y1, x2, y2;
    cout << "Enter line coordinates (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    float dx = x2 - x1;
    float dy = y2 - y1;

    if (dx == 0) {
        for (int y = min(y1, y2); y <= max(y1, y2); y++) {
            putpixel(x1, y, WHITE);
        }
    } else {
        float m = dy / dx;
        if (abs(m) <= 1) {
            for (int x = min(x1, x2); x <= max(x1, x2); x++) {
                float y = y1 + m * (x - x1);
                putpixel(x, round(y), WHITE);
            }
        } else {
            // Iterate over y
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                float x = x1 + (y - y1) / m;
                putpixel(round(x), y, WHITE);
            }
        }
    }

    outtextxy(50, 30, (char*)"Direct Line Algorithm");
    getch();
    closegraph();
    return 0;
}
