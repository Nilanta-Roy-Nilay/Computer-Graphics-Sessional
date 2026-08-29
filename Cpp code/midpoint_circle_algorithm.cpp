#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int xc,yc,r;
    cout<<"Enter xc yc r: "; cin>>xc>>yc>>r;

    int x=0,y=r,p=1-r;
    while(x<=y) {
        putpixel(xc+x,yc+y,RED);
        putpixel(xc+y,yc+x,RED);
        putpixel(xc+x,yc-y,RED);
        putpixel(xc+y,yc-x,RED);
        putpixel(xc-x,yc-y,RED);
        putpixel(xc-y,yc-x,RED);
        putpixel(xc-x,yc+y,RED);
        putpixel(xc-y,yc+x,RED);

        x++;
        if(p<0) p+=2*x+1;
        else { y--; p+=2*(x-y)+1; }
    }

    getch();
    closegraph();
    return 0;
}
