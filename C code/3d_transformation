#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // 3D Bar coordinates (x1, y1, x2, y2, depth, topflag)
    int x1 = 100, y1 = 100, x2 = 150, y2 = 150, depth = 20;

    int choice;
    printf("--- 3D Transformations Menu ---\n");
    printf("1. 3D Translation\n");
    printf("2. 3D Scaling\n");
    printf("3. 3D Rotation (around Z-axis)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Original 3D Object
    bar3d(x1, y1, x2, y2, depth, 1);

    if (choice == 1) { // 3D Translation
        int tx = 80, ty = 50;
        bar3d(x1 + tx, y1 + ty, x2 + tx, y2 + ty, depth, 1);
    } 
    else if (choice == 2) { // 3D Scaling
        float sx = 1.5, sy = 1.5, sz = 1.5;
        bar3d(x1 * sx, y1 * sy, x2 * sx, y2 * sy, depth * sz, 1);
    } 
    else if (choice == 3) { // 3D Rotation (Z-axis)
        float angle = 30;
        float rad = angle * 3.1416 / 180;

        int nx1 = x1 * cos(rad) - y1 * sin(rad);
        int ny1 = x1 * sin(rad) + y1 * cos(rad);
        int nx2 = x2 * cos(rad) - y2 * sin(rad);
        int ny2 = x2 * sin(rad) + y2 * cos(rad);

        bar3d(nx1, ny1, nx2, ny2, depth, 1);
    }

    getch();
    closegraph();
    return 0;
}
