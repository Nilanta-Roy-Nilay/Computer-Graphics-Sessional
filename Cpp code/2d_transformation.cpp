#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iostream>

using namespace std;

void DrawPolygon(int x[], int y[], int n) {
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

int main() {
    int gd = DETECT, gm;
    int n = 4;
    int x[4], y[4];
    int nx[4], ny[4];
    int choice;

    for (int i = 0; i < n; i++) {
        cout << "Enter point (x" << i + 1 << ", y" << i + 1 << "): ";
        cin >> x[i] >> y[i];
    }

    cout << "\n--- Enter 2D Transformation menu: ---" << endl;
    cout << "1. Translation" << endl;
    cout << "2. Rotation" << endl;
    cout << "3. Scaling" << endl;
    cout << "4. Reflection" << endl;
    cout << "5. Shearing" << endl;
    cout << "Enter Choice(1-5): ";
    cin >> choice;

    initgraph(&gd, &gm, "");

    setcolor(RED);
    DrawPolygon(x, y, n);

    setcolor(WHITE);

    if (choice == 1) {
        int tx, ty;
        cout << "Enter Translation (tx, ty): ";
        cin >> tx >> ty;

        for (int i = 0; i < n; i++) {
            nx[i] = x[i] + tx;
            ny[i] = y[i] + ty;
        }
        DrawPolygon(nx, ny, n);
    }
    else if (choice == 2) {
        float angle, rad;
        cout << "Enter Rotation (angle): ";
        cin >> angle;

        rad = angle * 3.1416 / 180.0;

        for (int i = 0; i < n; i++) {
            nx[i] = x[i] * cos(rad) - y[i] * sin(rad);
            ny[i] = x[i] * sin(rad) + y[i] * cos(rad);
        }
        DrawPolygon(nx, ny, n);
    }
    else if (choice == 3) {
        float sx, sy;
        cout << "Enter Scaling (sx, sy): ";
        cin >> sx >> sy;

        for (int i = 0; i < n; i++) {
            nx[i] = x[i] * sx;
            ny[i] = y[i] * sy;
        }
        DrawPolygon(nx, ny, n);
    }
    else if (choice == 4) {
        for (int i = 0; i < n; i++) {
            nx[i] = x[i];
            ny[i] = -y[i] + 300;
        }
        DrawPolygon(nx, ny, n);
    }
    else if (choice == 5) {
        float shx;
        cout << "Enter Shearing (shx): ";
        cin >> shx;

        for (int i = 0; i < n; i++) {
            nx[i] = x[i] + shx * y[i];
            ny[i] = y[i];
        }
        DrawPolygon(nx, ny, n);
    }

    getch();
    closegraph();
    return 0;
}
