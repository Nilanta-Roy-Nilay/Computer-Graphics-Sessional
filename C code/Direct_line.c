#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2;
    float dx, dy, steps, xi, yi, x, y;
    int i, gd = DETECT, gm;

    printf("Enter first point (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter second point (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    initgraph(&gd, &gm, "");

    dx = x2 - x1;
    dy = y2 - y1;
    steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    xi = dx / steps;
    yi = dy / steps;

    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xi;
        y += yi;
    }

    getch();
    closegraph();
    return 0;
}
