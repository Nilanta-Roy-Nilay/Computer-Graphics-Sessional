#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc;
    int r;

    printf("Enter xc: ");
    scanf("%d", &xc);

    printf("Enter yc: ");
    scanf("%d", &yc);

    printf("Enter r: ");
    scanf("%d", &r);

    int x = 0;
    int y = r;
    int p = 1 - r;   // midpoint initial decision parameter

    while (x <= y)
    {
        putpixel(xc + x, yc + y, RED);
        putpixel(xc + y, yc + x, RED);
        putpixel(xc + x, yc - y, RED);
        putpixel(xc + y, yc - x, RED);
        putpixel(xc - x, yc - y, RED);
        putpixel(xc - y, yc - x, RED);
        putpixel(xc - x, yc + y, RED);
        putpixel(xc - y, yc + x, RED);

        x = x + 1;
        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y = y - 1;
            p = p + 2 * (x - y) + 1;
        }
    }

    getch();
    closegraph();
    return 0;
}
