#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int x1,y1,x2,y2;
    cout<<"Enter x1 y1: "; cin>>x1>>y1;
    cout<<"Enter x2 y2: "; cin>>x2>>y2;

    float m=(float)(y2-y1)/(x2-x1);
    float c=y1-m*x1;

    for(int x=x1;x<=x2;x++) {
        int y=(int)(m*x+c+0.5);
        putpixel(x,y,WHITE);
    }

    getch();
    closegraph();
    return 0;
}
