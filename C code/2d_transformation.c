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
    int choice;
    printf("--- 2D Transformations Menu ---\n");
    printf("1. Translation\n");
    printf("2. Rotation\n");
    printf("3. Scaling\n");
    printf("4. Reflection (X-axis)\n");
    printf("5. Shearing (X-axis)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    printf("Enter x1 y1: ");
    scanf("%d%d", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%d%d", &x2, &y2);

    printf("Enter x3 y3: ");
    scanf("%d%d", &x3, &y3);

    printf("Enter x4 y4: ");
    scanf("%d%d", &x4, &y4);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);
    drawPolygon(x1, y1, x2, y2, x3, y3, x4, y4);

    setcolor(RED);

    if (choice == 1) { 
        int tx, ty;
        printf("Enter tx ty: ");
        scanf("%d%d", &tx, &ty);
        drawPolygon(x1 + tx, y1 + ty, x2 + tx, y2 + ty, x3 + tx, y3 + ty, x4 + tx, y4 + ty);
    }
    else if (choice == 2) { 
        float angle;
        printf("Enter angle: ");
        scanf("%f", &angle);
        float rad = angle * 3.14159 / 180.0;

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
    else if (choice == 3) { 
        float sx, sy;
        printf("Enter sx sy: ");
        scanf("%f%f", &sx, &sy);
        drawPolygon(x1 * sx, y1 * sy, x2 * sx, y2 * sy, x3 * sx, y3 * sy, x4 * sx, y4 * sy);
    }
    else if (choice == 4) { 
        drawPolygon(x1, -y1 + 300, x2, -y2 + 300, x3, -y3 + 300, x4, -y4 + 300);
    }
    else if (choice == 5) {
        int shx;
        printf("Enter shx: ");
        scanf("%d", &shx);
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
