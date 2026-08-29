#include <stdio.h>
#include <graphics.h>

int main() {
    int x1, y1, x2, y2;
    printf("Enter first point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter second point: ");
    scanf("%d %d", &x2, &y2);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dy - dx;
    int x = x1, y = y1;

    while (x <= x2) {
        putpixel(x, y, WHITE);
        x++;
        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * (dy - dx);
        }
    }

    getch();
    closegraph();
    return 0;
}
