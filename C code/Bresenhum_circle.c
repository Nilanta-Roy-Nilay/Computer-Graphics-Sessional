#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc;

    int r;

    printf("Enter xc: ");
    scanf("%d", &xc);

    printf("Enter yc: ");
    scanf("%d", &yc);

    printf("Enter r: ");
    scanf("%d", &r);


    int x=0;
    int y=r;
    
    int p = 3-2*r;


    while (x < y)
    {
        putpixel(xc+x, yc+y, RED);
        putpixel(xc+y, yc+x, RED);
        putpixel(xc+x, yc-y, RED);
        putpixel(xc+y, yc-x, RED);
        putpixel(xc-x, yc-y, RED);
        putpixel(xc-y, yc-x, RED);
        putpixel(xc-x, yc+y, RED);
        putpixel(xc-y, yc+x, RED);

      
        
        if (p < 0)
        {
            x = x + 1;
            y =y;
            p = p + 4 * x + 6;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p - 4 * y + 4 * x +10;
        }
    }

    getch();
    closegraph();
    return 0;
}
