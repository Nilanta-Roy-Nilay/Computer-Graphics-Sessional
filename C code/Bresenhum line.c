#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main() {
    int x, y, x1, y1, x2, y2, dx, dy, p, i;
    int xmax, ymax;
    int gd = DETECT, gm;

    printf("Enter first point : ");
    scanf("%d%d", &x1, &y1);

    printf("Enter second point : ");
    scanf("%d%d", &x2, &y2);

    initgraph(&gd, &gm, "");

    xmax = getmaxx();
    ymax = getmaxy();

    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);

    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * dy - dx;

    x = x1;
    y = y1;
    i = 0;

    while (x < x2) {
        putpixel((xmax / 2 + x), (ymax / 2 - y), WHITE);
        
        if (p < 0) {
            x = x + 1;
            p = p + 2 * dy;
        } else {
            x = x + 1;
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
    }

    getch();
    closegraph();
    return 0;
}