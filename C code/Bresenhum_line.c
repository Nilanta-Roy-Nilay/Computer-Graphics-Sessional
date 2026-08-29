#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int dx, dy, p;
    int x, y;

    printf("Enter x1: ");
    scanf("%d", &x1);

    printf("Enter y1: ");
    scanf("%d", &y1);

    printf("Enter x2: ");
    scanf("%d", &x2);

    printf("Enter y2: ");
    scanf("%d", &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    p = 2 * dy - dx;

    x = x1;
    y = y1;

    while (x <= x2)
    {
        putpixel(x, y, WHITE);

        if (p < 0)
        {
            p = p + (2 * dy);
        }
        else
        {
            y = y + 1;
            p = p + (2 * dy) - (2 * dx);
        }

        x = x + 1;
    }

    getch();
    closegraph();
    return 0;
}
