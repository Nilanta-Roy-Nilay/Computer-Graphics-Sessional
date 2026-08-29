#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, dx, dy, length, xi, yi, x, y;
    int i, gd = DETECT, gm;

    printf("Enter first point: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter second point: ");
    scanf("%f %f", &x2, &y2);

    initgraph(&gd, &gm, "");
    int xmax = getmaxx(), ymax = getmaxy();

    // axes
    line(xmax/2, 0, xmax/2, ymax);
    line(0, ymax/2, xmax, ymax/2);

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs((int)dx) >= abs((int)dy))
        length = abs((int)dx);
    else
        length = abs((int)dy);

    xi = dx / length;
    yi = dy / length;

    x = x1; y = y1;

    for (i = 0; i <= length; i++) {
        putpixel(xmax/2 + (int)(x+0.5), ymax/2 - (int)(y+0.5), WHITE);
        x += xi; y += yi;
    }

    getch();
    closegraph();
    return 0;
}
