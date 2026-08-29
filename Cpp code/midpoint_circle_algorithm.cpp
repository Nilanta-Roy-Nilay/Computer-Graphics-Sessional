#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

int main() {
    int xc, yc, r;
    cout << "Enter xc: "; cin >> xc;
    cout << "Enter yc: "; cin >> yc;
    cout << "Enter r: ";  cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 0;
    int y = r;
    int p = 1 - r;

    while (x <= y) {
        putpixel(xc + x, yc + y, RED);
        putpixel(xc + y, yc + x, RED);
        putpixel(xc + x, yc - y, RED);
        putpixel(xc + y, yc - x, RED);
        putpixel(xc - x, yc - y, RED);
        putpixel(xc - y, yc - x, RED);
        putpixel(xc - x, yc + y, RED);
        putpixel(xc - y, yc + x, RED);

        x = x + 1;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y = y - 1;
            p = p + 2 * (x - y) + 1;
        }
    }

    getch();
    closegraph();
    return 0;
}
