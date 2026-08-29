#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(100, 100, 200, 200);

    int tx = 100;
    int ty = 50;

    rectangle(100 + tx, 100 + ty,
              200 + tx, 200 + ty);

    getch();
    closegraph();

    return 0;
}




rota

#include <graphics.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 200, y3 = 200;
    int x4 = 100, y4 = 200;

    float angle = 12;
    float rad = angle * 3.1416 / 180;

    int nx1, ny1, nx2, ny2;
    int nx3, ny3, nx4, ny4;

    // Original
    rectangle(x1, y1, x3, y3);

    // Rotation around origin
    nx1 = x1 * cos(rad) - y1 * sin(rad);
    ny1 = x1 * sin(rad) + y1 * cos(rad);

    nx2 = x2 * cos(rad) - y2 * sin(rad);
    ny2 = x2 * sin(rad) + y2 * cos(rad);

    nx3 = x3 * cos(rad) - y3 * sin(rad);
    ny3 = x3 * sin(rad) + y3 * cos(rad);

    nx4 = x4 * cos(rad) - y4 * sin(rad);
    ny4 = x4 * sin(rad) + y4 * cos(rad);

    line(nx1, ny1, nx2, ny2);
    line(nx2, ny2, nx3, ny3);
    line(nx3, ny3, nx4, ny4);
    line(nx4, ny4, nx1, ny1);

    getch();
    closegraph();

    return 0;
}





Scaling

#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 200;

    float sx = 1.5;
    float sy = 2.0;

    // Original
    rectangle(x1, y1, x2, y2);

    // Scaling
    rectangle(x1 * sx, y1 * sy,
              x2 * sx, y2 * sy);

    getch();
    closegraph();

    return 0;
}




Reflection

#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 200;

    // Original
    rectangle(x1, y1, x2, y2);

    // Reflection about X-axis
    rectangle(x1, -y1, x2, -y2);

    getch();
    closegraph();

    return 0;
}




Shearing

#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 200, y3 = 200;
    int x4 = 100, y4 = 200;

    int shx = 1;

    // Original
    rectangle(x1, y1, x3, y3);

    // Shearing
    int nx1 = x1 + shx * y1;
    int nx2 = x2 + shx * y2;
    int nx3 = x3 + shx * y3;
    int nx4 = x4 + shx * y4;

    line(nx1, y1, nx2, y2);
    line(nx2, y2, nx3, y3);
    line(nx3, y3, nx4, y4);
    line(nx4, y4, nx1, y1);

    getch();
    closegraph();

    return 0;
}
