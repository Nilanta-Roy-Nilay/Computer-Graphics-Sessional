#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int tri[3][2];

void drawTriangle() {
    line(tri[0][0], tri[0][1], tri[1][0], tri[1][1]);
    line(tri[1][0], tri[1][1], tri[2][0], tri[2][1]);
    line(tri[2][0], tri[2][1], tri[0][0], tri[0][1]);
}

void translate2D(int tx, int ty) {
    int i;
    for(i = 0; i < 3; i++) {
        tri[i][0] += tx;
        tri[i][1] += ty;
    }
}

void scale2D(float sx, float sy) {
    int cx = (tri[0][0] + tri[1][0] + tri[2][0]) / 3;
    int cy = (tri[0][1] + tri[1][1] + tri[2][1]) / 3;
    int i;

    for(i = 0; i < 3; i++) {
        int x = tri[i][0] - cx;
        int y = tri[i][1] - cy;
        tri[i][0] = cx + (int)round(x * sx);
        tri[i][1] = cy + (int)round(y * sy);
    }
}

void rotate2D(float theta) {
    int cx = (tri[0][0] + tri[1][0] + tri[2][0]) / 3;
    int cy = (tri[0][1] + tri[1][1] + tri[2][1]) / 3;
    int i;

    for(i = 0; i < 3; i++) {
        int x = tri[i][0] - cx;
        int y = tri[i][1] - cy;

        tri[i][0] = cx + (int)round(x * cos(theta) - y * sin(theta));
        tri[i][1] = cy + (int)round(x * sin(theta) + y * cos(theta));
    }
}

int main() {
    int tx, ty;
    float sx, sy, angle;
    int xmax, ymax;
    int gd = DETECT, gm;

    printf("Enter coordinates for Point 1 (x1 y1): ");
    scanf("%d %d", &tri[0][0], &tri[0][1]);

    printf("Enter coordinates for Point 2 (x2 y2): ");
    scanf("%d %d", &tri[1][0], &tri[1][1]);

    printf("Enter coordinates for Point 3 (x3 y3): ");
    scanf("%d %d", &tri[2][0], &tri[2][1]);

    printf("Enter Translation (tx ty): ");
    scanf("%d %d", &tx, &ty);

    printf("Enter Scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    printf("Enter Rotation angle (in radians): ");
    scanf("%f", &angle);

    initgraph(&gd, &gm, "");

    xmax = getmaxx();
    ymax = getmaxy();

    // অক্ষ (Axis) ড্র করার জন্য সেন্টারিং লাইন
    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);

    drawTriangle();
    outtextxy(50, 30, "Original Triangle");
    getch();
    cleardevice();

    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);
    translate2D(tx, ty);
    drawTriangle();
    outtextxy(50, 30, "After Translation");
    getch();
    cleardevice();

    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);
    scale2D(sx, sy);
    drawTriangle();
    outtextxy(50, 30, "After Scaling");
    getch();
    cleardevice();

    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);
    rotate2D(angle);
    drawTriangle();
    outtextxy(50, 30, "After Rotation");
    getch();

    closegraph();
    return 0;
}
