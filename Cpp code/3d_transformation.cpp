#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iostream>

using namespace std;

void Draw3DPolygon(int x[], int y[], int z[], int n) {
    int px[8], py[8];
    float perspective = 0.5;

    for (int i = 0; i < n; i++) {
        px[i] = x[i] + z[i] * perspective;
        py[i] = y[i] - z[i] * perspective;
    }

    for (int i = 0; i < n; i++) {
        line(px[i], py[i], px[(i + 1) % n], py[(i + 1) % n]);
    }
}

int main() {
    int gd = DETECT, gm;
    int n = 4;
    int x[4], y[4], z[4];
    int nx[4], ny[4], nz[4];
    int choice;

    for (int i = 0; i < n; i++) {
        cout << "Enter point (x" << i + 1 << ", y" << i + 1 << ", z" << i + 1 << "): ";
        cin >> x[i] >> y[i] >> z[i];
    }

    cout << "\n--- Enter 3D Transformation menu: ---" << endl;
    cout << "1. Translation" << endl;
    cout << "2. Rotation (Z-Axis)" << endl;
    cout << "3. Scaling" << endl;
    cout << "4. Reflection (XY Plane)" << endl;
    cout << "5. Shearing" << endl;
    cout << "Enter Choice(1-5): ";
    cin >> choice;

    initgraph(&gd, &gm, "");

    setcolor(RED);
    Draw3DPolygon(x, y, z, n);

    setcolor(WHITE);

    if (choice == 1) {
        int tx, ty, tz;
        cout << "Enter Translation (tx, ty, tz): ";
        cin >> tx >> ty >> tz;

        for (int i = 0; i < n; i++) {
            nx[i] = x[i] + tx;
            ny[i] = y[i] + ty;
            nz[i] = z[i] + tz;
        }
        Draw3DPolygon(nx, ny, nz, n);
    }
    else if (choice == 2) {
        float angle, rad;
        cout << "Enter Rotation angle around Z-axis: ";
        cin >> angle;

        rad = angle * 3.1416 / 180.0;

        for (int i = 0; i < n; i++) {
            nx[i] = x[i] * cos(rad) - y[i] * sin(rad);
            ny[i] = x[i] * sin(rad) + y[i] * cos(rad);
            nz[i] = z[i];
        }
        Draw3DPolygon(nx, ny, nz, n);
    }
    else if (choice == 3) {
        float sx, sy, sz;
        cout << "Enter Scaling factors (sx, sy, sz): ";
        cin >> sx >> sy >> sz;

        for (int i = 0; i < n; i++) {
            nx[i] = x[i] * sx;
            ny[i] = y[i] * sy;
            nz[i] = z[i] * sz;
        }
        Draw3DPolygon(nx, ny, nz, n);
    }
    else if (choice == 4) {
        for (int i = 0; i < n; i++) {
            nx[i] = x[i];
            ny[i] = y[i];
            nz[i] = -z[i];
        }
        Draw3DPolygon(nx, ny, nz, n);
    }
    else if (choice == 5) {
        float shx, shy;
        cout << "Enter Shearing factors relative to Z (shx, shy): ";
        cin >> shx >> shy;

        for (int i = 0; i < n; i++) {
            nx[i] = x[i] + shx * z[i];
            ny[i] = y[i] + shy * z[i];
            nz[i] = z[i];
        }
        Draw3DPolygon(nx, ny, nz, n);
    }

    getch();
    closegraph();
    return 0;
}
