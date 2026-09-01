#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void draw3DBar(int x1, int y1, int x2, int y2, int depth) {
    bar3d(x1, y1, x2, y2, depth, 1);
}

int main() {
    int choice;
    printf("--- 3D Transformations Menu ---\n");
    printf("1. Translation\n");
    printf("2. Rotation (Z-axis)\n");
    printf("3. Scaling\n");
    printf("4. Reflection (XY Plane)\n");
    printf("5. Shearing (X-axis relative to Z)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    int x1, y1, x2, y2, depth;
    printf("Enter x1,y1: ");
    scanf("%d%d", &x1, &y1);

    printf("Enter x2,y2: ");
    scanf("%d%d", &x2, &y2);

    printf("Enter depth: ");
    scanf("%d", &depth);

    int tx, ty, tz;
    float angle;
    float sx, sy, sz;
    float shx;

    if (choice == 1) {
        printf("Enter tx,ty,tz: ");
        scanf("%d%d%d", &tx, &ty, &tz);
    }
    else if (choice == 2) {
        printf("Enter angle: ");
        scanf("%f", &angle);
    }
    else if (choice == 3) {
        printf("Enter sx,sy,sz: ");
        scanf("%f%f%f", &sx, &sy, &sz);
    }
    else if (choice == 5) {
        printf("Enter shx: ");
        scanf("%f", &shx);
    }

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);
    draw3DBar(x1, y1, x2, y2, depth);

    setcolor(RED);

    if (choice == 1) {
        draw3DBar(x1 + tx, y1 + ty, x2 + tx, y2 + ty, depth + tz);
    }
    else if (choice == 2) {
        float rad = angle * 3.1416 / 180;
        int nx1 = x1 * cos(rad) - y1 * sin(rad);
        int ny1 = x1 * sin(rad) + y1 * cos(rad);
        int nx2 = x2 * cos(rad) - y2 * sin(rad);
        int ny2 = x2 * sin(rad) + y2 * cos(rad);

        draw3DBar(nx1, ny1, nx2, ny2, depth);
    }
    else if (choice == 3) {
        draw3DBar(x1 * sx, y1 * sy, x2 * sx, y2 * sy, depth * sz);
    }
    else if (choice == 4) {
        draw3DBar(x1, y1, x2, y2, -depth);
    }
    else if (choice == 5) {
        int nx1 = x1 + shx * depth;
        int nx2 = x2 + shx * depth;

        draw3DBar(nx1, y1, nx2, y2, depth);
    }

    getch();
    closegraph();
    return 0;
}
