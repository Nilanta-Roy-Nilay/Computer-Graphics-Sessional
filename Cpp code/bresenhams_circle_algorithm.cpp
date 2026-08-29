#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int xc,yc,r;
    cout<<"Enter xc yc r: "; cin>>xc>>yc>>r;

    int x=0,y=r,d=3-2*r;
    while(y>=x) {
        putpixel(xc+x,yc+y,RED);
        putpixel(xc+y,yc+x,RED);
        putpixel(xc+x,yc-y,RED);
        putpixel(xc+y,yc-x,RED);
        putpixel(xc-x,yc-y,RED);
        putpixel(xc-y,yc-x,RED);
        putpixel(xc-x,yc+y,RED);
        putpixel(xc-y,yc+x,RED);

        x++;
        if(d>0){ y--; d=d+4*(x-y)+10; }
        else d=d+4*x+6;
    }

    getch();
    closegraph();
    return 0;
}
