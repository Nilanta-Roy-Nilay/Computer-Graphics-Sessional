#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int x, xend;
    float y, dx, dy, m, c;

    printf("Enter the value of x1: ");
    scanf("%d", &x1);

    printf("Enter the value of y1: ");
    scanf("%d", &y1);

    printf("Enter the value of x2: ");
    scanf("%d", &x2);

    printf("Enter the value of y2: ");
    scanf("%d", &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    m = dy / dx;

    if (dx > 0)
    {
        x = x1;
        y = y1;
        xend = x2;
    }
    else
    {
        x = x2;
        y = y2;
        xend = x1;
    }

    c = y - m * x;

    while (x != xend)
    {
        putpixel(x, (int)(y + 0.5), WHITE);

        x = x + 1;
        y = m * x + c;
    }

    putpixel(xend, (int)(y + 0.5), WHITE);

    getch();
    closegraph();
    return 0;
}
