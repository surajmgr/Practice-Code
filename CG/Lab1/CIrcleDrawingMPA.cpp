#include <stdio.h>
#include <graphics.h>
#include <conio.h>
 
void drawcircle(int x0, int y0, int r)
{	
    int x = 0;
    int y = r;
    putpixel(x+x0, y+y0, WHITE);

	if(r>0){
		putpixel(x+x0, -y+y0, WHITE);
		putpixel(y+x0, x+y0, WHITE);
		putpixel(-y+x0, x+y0, WHITE);
	}
	
	int P=1-r;

    while (x <= y)
    {
		x++;
		if(P<=0)
			P=P+2*x+1;
		else{
			y--;
			P=P+2*x-2*y+1;
		}

		if(x>y)
			break;

		putpixel(x+x0, y+y0, WHITE);
		putpixel(-x+x0, y+y0, WHITE);
		putpixel(x+x0, -y+y0, WHITE);
		putpixel(-x+x0, -y+y0, WHITE);

		if(x!=y){
			putpixel(y+x0, x+y0, WHITE);
			putpixel(-y+x0, x+y0, WHITE);
			putpixel(y+x0, -x+y0, WHITE);
			putpixel(-y+x0, -x+y0, WHITE);
		}
    }
}
 
int main()
{
	int x, y, r;
	
	int gd=DETECT, gm, i;
	initgraph(&gd, &gm, "c:\\Turboc3\\BGI");
 
	printf("Enter co-ordinates of center, (x,y): ");
	scanf("%d %d", &x, &y);
	
	printf("Enter radius of circle: ");
	scanf("%d", &r);

	drawcircle(x, y, r);

	getch();
	closegraph();
	
	return 0;
}
