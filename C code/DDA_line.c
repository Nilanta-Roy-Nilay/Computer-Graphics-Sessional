#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int dx, dy;
    float x, y, m;

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

    m = (float)dy / dx;

    x = x1;
    y = y1;

    if (abs(dx) >= abs(dy))
    {
        while ((int)(x + 0.5) != x2)
        {
            putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);

            x = x + 1;
            y = y + m;
        }
    }
    else
    {
        while ((int)(y + 0.5) != y2)
        {
            putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);

            x = x + (1.0 / m);
            y = y + 1;
        }
    }

    putpixel(x2, y2, WHITE);

    getch();
    closegraph();
    return 0;
}
