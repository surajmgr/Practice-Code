#include <stdio.h>
#include <graphics.h>
#include <conio.h>

using namespace std;
 
void drawcircle(int x0, int y0, int r)
{	
    int x = r;
    int y = 0;
    int P = 0;
 
    while (x >= y)
    {
		putpixel(x0 + x, y0 + y, WHITE);
		putpixel(x0 + y, y0 + x, WHITE);
		putpixel(x0 - y, y0 + x, WHITE);
		putpixel(x0 - x, y0 + y, WHITE);
		putpixel(x0 - x, y0 - y, WHITE);
		putpixel(x0 - y, y0 - x, WHITE);
		putpixel(x0 + y, y0 - x, WHITE);
		putpixel(x0 + x, y0 - y, WHITE);
 
		if (P <= 0){
		    y += 1;
    		P += 2*y + 1;
		}
		if (P > 0){
    		x -= 1;
    		P -= 2*x + 1;
		}
    }
}
 
int main()
{
	int x, y, r;
	
	int gd=DETECT, gm, i;
	initgraph(&gd, &gm, "c:\\Turboc3\\BGI");
 
	cout<<"Enter co-ordinates of center, (x,y): ";
	cin>>x>>y;
	
	cout<<"Enter radius of circle: ";
	cin>>r;

	drawcircle(x, y, r);

	getch();
	closegraph();
	
	return 0;
}
