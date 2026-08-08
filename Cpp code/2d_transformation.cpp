#include <graphics.h>
#include <cmath>
#include <iostream>

using namespace std;

int tri[3][2];

void drawTriangle() {
    line(tri[0][0], tri[0][1], tri[1][0], tri[1][1]);
    line(tri[1][0], tri[1][1], tri[2][0], tri[2][1]);
    line(tri[2][0], tri[2][1], tri[0][0], tri[0][1]);
}

void translate2D(int tx, int ty) {
    for(int i = 0; i < 3; i++) {
        tri[i][0] += tx;
        tri[i][1] += ty;
    }
}

void scale2D(float sx, float sy) {
    int cx = (tri[0][0] + tri[1][0] + tri[2][0]) / 3;
    int cy = (tri[0][1] + tri[1][1] + tri[2][1]) / 3;

    for(int i = 0; i < 3; i++) {
        int x = tri[i][0] - cx;
        int y = tri[i][1] - cy;
        tri[i][0] = cx + round(x * sx);
        tri[i][1] = cy + round(y * sy);
    }
}

void rotate2D(float theta) {
    int cx = (tri[0][0] + tri[1][0] + tri[2][0]) / 3;
    int cy = (tri[0][1] + tri[1][1] + tri[2][1]) / 3;

    for(int i = 0; i < 3; i++) {
        int x = tri[i][0] - cx;
        int y = tri[i][1] - cy;

        tri[i][0] = cx + round(x * cos(theta) - y * sin(theta));
        tri[i][1] = cy + round(x * sin(theta) + y * cos(theta));
    }
}

int main() {
    cout << "Enter coordinates for Point 1 (x y): ";
    cin >> tri[0][0] >> tri[0][1];

    cout << "Enter coordinates for Point 2 (x y): ";
    cin >> tri[1][0] >> tri[1][1];

    cout << "Enter coordinates for Point 3 (x y): ";
    cin >> tri[2][0] >> tri[2][1];

    int tx, ty;
    float sx, sy, angle;

    cout << "Enter Translation (tx ty): ";
    cin >> tx >> ty;

    cout << "Enter Scaling factors (sx sy): ";
    cin >> sx >> sy;

    cout << "Enter Rotation angle (in radians): ";
    cin >> angle;

    int gd = DETECT, gm;
    initwindow(800, 600, (char*)"2D Transformation");

    drawTriangle();
    outtextxy(50, 30, (char*)"Original Triangle");
    getch();
    cleardevice();

    translate2D(tx, ty);
    drawTriangle();
    outtextxy(50, 30, (char*)"After Translation");
    getch();
    cleardevice();

    scale2D(sx, sy);
    drawTriangle();
    outtextxy(50, 30, (char*)"After Scaling");
    getch();
    cleardevice();

    rotate2D(angle);
    drawTriangle();
    outtextxy(50, 30, (char*)"After Rotation");
    getch();

    closegraph();
    return 0;
}
