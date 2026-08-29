#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int x1,y1,x2,y2;
    cout<<"Enter x1 y1: "; cin>>x1>>y1;
    cout<<"Enter x2 y2: "; cin>>x2>>y2;

    int dx=x2-x1, dy=y2-y1;
    int steps = (abs(dx)>=abs(dy))?abs(dx):abs(dy);

    float xi=(float)dx/steps, yi=(float)dy/steps;
    float x=x1, y=y1;

    for(int i=0;i<=steps;i++) {
        putpixel((int)(x+0.5),(int)(y+0.5),WHITE);
        x+=xi; y+=yi;
    }

    getch();
    closegraph();
    return 0;
}
