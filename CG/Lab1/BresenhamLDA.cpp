#include <stdio.h>  
#include <graphics.h>  
#include <conio.h>

void drawline(int x0, int y0, int x1, int y1)  
{  
    int dx, dy, p, x, y;  
    dx=x1-x0;  
    dy=y1-y0;  
    x=x0;  
    y=y0;  
    p=2*dy-dx;  
    while(x<x1)  
    {  
        if(p>=0)  
        {  
            putpixel(x,y,WHITE);  
            y=y+1;  
            p=p+2*dy-2*dx;  
        }  
        else  
        {  
            putpixel(x,y,WHITE);  
            p=p+2*dy;}  
            x=x+1;  
        }  
}  
int main()  
{
    int x0, y0, x1, y1;

    int gd=DETECT, gm, i;
    initgraph(&gd, &gm, "c:\\TurboC3\\BGI"); 

    printf("Enter co-ordinates of first point, (x0, y0): ");  
    scanf("%d %d", &x0, &y0);  
    printf("Enter co-ordinates of end point, (x1, yi): ");  
    scanf("%d %d", &x1, &y1);  

    drawline(x0, y0, x1, y1);  

    getch();
    closegraph();
    return 0;  
}
