#include <stdio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    int x, y, xc, yc, r, p, xmax, ymax;

    printf("Input center of the circle : ");
    scanf("%d%d", &xc, &yc);

    printf("Input the radius of the circle : ");
    scanf("%d", &r);

    initgraph(&gd, &gm, "");

    xmax = getmaxx();
    ymax = getmaxy();

    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);

    p = 1 - r;
    x = 0;
    y = r;

    while (x <= y) {
        putpixel((xmax / 2 + xc + x), (ymax / 2 - yc + y), WHITE);
        putpixel((xmax / 2 + xc - x), (ymax / 2 - yc + y), WHITE);
        putpixel((xmax / 2 + xc + x), (ymax / 2 - yc - y), WHITE);
        putpixel((xmax / 2 + xc - x), (ymax / 2 - yc - y), WHITE);
        putpixel((xmax / 2 + xc + y), (ymax / 2 - yc + x), WHITE);
        putpixel((xmax / 2 + xc - y), (ymax / 2 - yc + x), WHITE);
        putpixel((xmax / 2 + xc + y), (ymax / 2 - yc - x), WHITE);
        putpixel((xmax / 2 + xc - y), (ymax / 2 - yc - x), WHITE);

        if (p < 0) {
            x = x + 1;
            p = p + 2 * x + 1;
        } else {
            x = x + 1;
            y = y - 1;
            p = p + 2 * (x - y) + 1;
        }
    }

    getch();
    closegraph();
    return 0;
}