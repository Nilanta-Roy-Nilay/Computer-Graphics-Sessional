#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, i, xi, yi;
    float x, y, dx, dy, length;
    int xmax, ymax;
    int gd = DETECT, gm;

    printf("Enter first point : ");
    scanf("%f%f", &x1, &y1);

    printf("Enter second point : ");
    scanf("%f%f", &x2, &y2);

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
        putpixel((xmax / 2 + x), (ymax / 2 - y), WHITE);
        x = x + xi;
        y = y + yi;
        i++;
    }

    getch();
    closegraph();
    return 0;
}