#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100, x2 = 150, y2 = 150, depth = 20;
    int choice;

    printf("--- 3D Transformation Menu ---\n");
    printf("1. Translation\n2. Rotation (Z-axis)\n3. Scaling\n4. Reflection (Z-plane)\n5. Shearing (Z-axis)\nChoice: ");
    scanf("%d", &choice);

    initgraph(&gd, &gm, "");
    setcolor(WHITE);
    bar3d(x1, y1, x2, y2, depth, 1); // Original 3D Box

    setcolor(RED);
    if (choice == 1) { // 3D Translation
        int tx = 80, ty = 50;
        bar3d(x1 + tx, y1 + ty, x2 + tx, y2 + ty, depth, 1);
    } 
    else if (choice == 2) { // 3D Rotation (Z-axis)
        float rad = 30 * 3.1416 / 180;
        int nx1 = x1 * cos(rad) - y1 * sin(rad);
        int ny1 = x1 * sin(rad) + y1 * cos(rad);
        int nx2 = x2 * cos(rad) - y2 * sin(rad);
        int ny2 = x2 * sin(rad) + y2 * cos(rad);
        bar3d(nx1, ny1, nx2, ny2, depth, 1);
    } 
    else if (choice == 3) { // 3D Scaling
        float sx = 1.5, sy = 1.5, sz = 1.5;
        bar3d(x1 * sx, y1 * sy, x2 * sx, y2 * sy, depth * sz, 1);
    } 
    else if (choice == 4) { // 3D Reflection
        bar3d(x1, -y1 + 300, x2, -y2 + 300, depth, 1);
    } 
    else if (choice == 5) { // 3D Shearing
        float shx = 0.5;
        int nx1 = x1 + shx * y1;
        int nx2 = x2 + shx * y2;
        bar3d(nx1, y1, nx2, y2, depth, 1);
    }

    getch();
    closegraph();
    return 0;
}
