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

    int dx=x2-x1, dy=y2-y1;
    int p=2*dy-dx;
    int x=x1,y=y1;

    while(x<=x2) {
        putpixel(x,y,WHITE);
        if(p<0) p+=2*dy;
        else { y++; p+=2*(dy-dx); }
        x++;
    }

    getch();
    closegraph();
    return 0;
}
