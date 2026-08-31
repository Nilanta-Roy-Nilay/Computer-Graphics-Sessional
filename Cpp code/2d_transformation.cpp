#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void drawPolygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
}

int main() {
    int gd = DETECT, gm;

    // Original Rectangle Coordinates
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 200, y3 = 200;
    int x4 = 100, y4 = 200;

    int choice;
    printf("--- 2D Transformations Menu ---\n");
    printf("1. Translation\n");
    printf("2. Rotation\n");
    printf("3. Scaling\n");
    printf("4. Reflection (X-axis)\n");
    printf("5. Shearing (X-axis)\n");
    printf("Enter choice (1-5): ");
    scanf("%d", &choice);

    initgraph(&gd, &gm, "");

    // Original Shape (Red color)
    setcolor(RED);
    rectangle(x1, y1, x3, y3);

    // Transformed Shape Color (White)
    setcolor(WHITE);

    if (choice == 1) { // Translation
        int tx = 100, ty = 50;
        rectangle(x1 + tx, y1 + ty, x3 + tx, y3 + ty);
    } 
    else if (choice == 2) { // Rotation
        float angle = 45;
        float rad = angle * 3.1416 / 180;

        int nx1 = x1 * cos(rad) - y1 * sin(rad);
        int ny1 = x1 * sin(rad) + y1 * cos(rad);
        int nx2 = x2 * cos(rad) - y2 * sin(rad);
        int ny2 = x2 * sin(rad) + y2 * cos(rad);
        int nx3 = x3 * cos(rad) - y3 * sin(rad);
        int ny3 = x3 * sin(rad) + y3 * cos(rad);
        int nx4 = x4 * cos(rad) - y4 * sin(rad);
        int ny4 = x4 * sin(rad) + y4 * cos(rad);

        drawPolygon(nx1, ny1, nx2, ny2, nx3, ny3, nx4, ny4);
    } 
    else if (choice == 3) { // Scaling
        float sx = 1.5, sy = 2.0;
        rectangle(x1 * sx, y1 * sy, x3 * sx, y3 * sy);
    } 
    else if (choice == 4) { // Reflection (Visual Screen Offset)
        rectangle(x1, -y1 + 300, x3, -y3 + 300);
    } 
    else if (choice == 5) { // Shearing (X-axis)
        float shx = 1.0;
        int nx1 = x1 + shx * y1;
        int nx2 = x2 + shx * y2;
        int nx3 = x3 + shx * y3;
        int nx4 = x4 + shx * y4;

        drawPolygon(nx1, y1, nx2, y2, nx3, y3, nx4, y4);
    }

    getch();
    closegraph();
    return 0;
}
