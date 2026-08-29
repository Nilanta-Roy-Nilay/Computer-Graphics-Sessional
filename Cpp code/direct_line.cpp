#include <iostream>
#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int x, xend;
    float y, dx, dy, m, c;

    std::cout << "Enter the value of x1: ";
    std::cin >> x1;

    std::cout << "Enter the value of y1: ";
    std::cin >> y1;

    std::cout << "Enter the value of x2: ";
    std::cin >> x2;

    std::cout << "Enter the value of y2: ";
    std::cin >> y2;

    dx = (float)(x2 - x1);
    dy = (float)(y2 - y1);

    // handle vertical line to avoid division by zero
    if (dx == 0.0f) {
        int ymin = (y1 < y2) ? y1 : y2;
        int ymax = (y1 > y2) ? y1 : y2;
        for (int yy = ymin; yy <= ymax; yy++) {
            putpixel(x1, yy, WHITE);
        }
    } else {
        m = dy / dx;

        if (dx > 0)
        {
            x = x1;
            y = (float)y1;
            xend = x2;
        }
        else
        {
            x = x2;
            y = (float)y2;
            xend = x1;
        }

        c = y - m * x;

        while (x != xend)
        {
            putpixel(x, (int)(y + 0.5f), WHITE);

            x = x + 1;
            y = m * x + c;
        }

        putpixel(xend, (int)(y + 0.5f), WHITE);
    }

    getch();
    closegraph();
    return 0;
}
