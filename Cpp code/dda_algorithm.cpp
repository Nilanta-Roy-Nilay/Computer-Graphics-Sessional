#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initwindow(800, 600, (char*)"DDA Line Drawing");

    int x1, y1, x2, y2;
    cout << "Enter line coordinates (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += Xinc;
        y += Yinc;
    }

    outtextxy(50, 30, (char*)"DDA Line");
    getch();
    closegraph();
}
