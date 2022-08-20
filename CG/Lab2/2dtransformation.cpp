#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm, s;
    initgraph(&gd, &gm, "c://turboc3//bgi");
    printf("1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Shearing\n");
    printf("Selection:");
    scanf("%d", &s);
    switch (s)
    {
    case 1:
        int x1 = 200, y1 = 150, x2 = 300, y2 = 250;
        int tx = 50, ty = 50;
        printf("Rectangle before translation\n");
        setcolor(3);
        rectangle(x1, y1, x2, y2);
        setcolor(4);
        printf("Rectangle after translation\n");
        rectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
        break;

    case 2:
        long x1 = 200, y1 = 200, x2 = 300, y2 = 300;
        double a;
        printf("Rectangle with rotation\n");
        setcolor(3);
        rectangle(x1, y1, x2, y2);
        printf("Angle of rotation:");
        scanf("%d", &a);
        a = (a * 3.14) / 180;
        long xr = x1 + ((x2 - x1) * cos(a) - (y2 - y1) * sin(a));
        long yr = y1 + ((x2 - x1) * sin(a) + (y2 - y1) * cos(a));
        setcolor(2);
        rectangle(x1, y1, xr, yr);
        break;

    case 3:
        int x1 = 30, y1 = 30, x2 = 70, y2 = 70, y = 2, x = 2;
        printf("Before scaling\n");
        setcolor(3);
        rectangle(x1, y1, x2, y2);
        printf("After scaling\n");
        setcolor(10);
        rectangle(x1 * x, y1 * y, x2 * x, y2 * y);
        break;

    case 4:
        int x1 = 200, y1 = 300, x2 = 500, y2 = 300, x3 = 350, y3 = 400;
        printf("triangle before reflection\n");
        setcolor(3);
        line(x1, y1, x2, y2);
        line(x1, y1, x3, y3);
        line(x2, y2, x3, y3);
        printf("triangle after reflection\n");
        setcolor(5);
        line(x1, -y1 + 500, x2, -y2 + 500);
        line(x1, -y1 + 500, x3, -y3 + 500);
        line(x2, -y2 + 500, x3, -y3 + 500);
        break;

    case 5:
        int x1 = 400, y1 = 100, x2 = 600, y2 = 100, x3 = 400, y3 = 200, x4 = 600, y4 = 200, shx = 2;
        printf("Before shearing of rectangle\n");
        setcolor(3);
        line(x1, y1, x2, y2);
        line(x1, y1, x3, y3);
        line(x3, y3, x4, y4);
        line(x2, y2, x4, y4);
        printf("After shearing of rectangle\n");
        x1 = x1 + shx * y1;
        x2 = x2 + shx * y2;
        x3 = x3 + shx * y3;
        x4 = x4 + shx * y4;
        setcolor(13);
        line(x1, y1, x2, y2);
        line(x1, y1, x3, y3);
        line(x3, y3, x4, y4);
        line(x2, y2, x4, y4);
        break;

    default:
        printf("Invalid Selection\n");
        break;
    }

    getch();
    closegraph();
    return 0;
}