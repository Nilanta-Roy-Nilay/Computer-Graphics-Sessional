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

    /* Original 3D Box (White Color) */
    setcolor(WHITE);
    bar3d(x1, y1, x2, y2, depth, 1);

    /* Transformed 3D Box (Red Color) */
    setcolor(RED);

    if (choice == 1) { /* 3D Translation */
        int tx = 80, ty = 50;
        bar3d(x1 + tx, y1 + ty, x2 + tx, y2 + ty, depth, 1);
    } 
    else if (choice == 2) { /* 3D Rotation (Z-axis) */
        float rad = 30.0 * 3.1416 / 180.0;
        int nx1 = (int)(x1 * cos(rad) - y1 * sin(rad));
        int ny1 = (int)(x1 * sin(rad) + y1 * cos(rad));
        int nx2 = (int)(x2 * cos(rad) - y2 * sin(rad));
        int ny2 = (int)(x2 * sin(rad) + y2 * cos(rad));
        
        bar3d(nx1, ny1, nx2, ny2, depth, 1);
    } 
    else if (choice == 3) { /* 3D Scaling */
        float sx = 1.5, sy = 1.5, sz = 1.5;
        bar3d((int)(x1 * sx), (int)(y1 * sy), (int)(x2 * sx), (int)(y2 * sy), (int)(depth * sz), 1);
    } 
    else if (choice == 4) { /* 3D Reflection */
        bar3d(x1, -y1 + 300, x2, -y2 + 300, depth, 1);
    } 
    else if (choice == 5) { /* 3D Shearing */
        float shx = 0.5;
        int nx1 = (int)(x1 + shx * y1);
        int nx2 = (int)(x2 + shx * y2);
        
        bar3d(nx1, y1, nx2, y2, depth, 1);
    }

    getch();
    closegraph();
    return 0;
}
