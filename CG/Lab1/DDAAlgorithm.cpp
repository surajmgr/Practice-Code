#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main(){
	float x1, y1, x2, y2, x, y;
	float dx, dy, steps, xinc, yinc;
	
	int gd = DETECT, gm, i;
	initgraph(&gd,&gm,"c:\\TurboC3\\BGI");
	
	printf("Enter co-ordinates of first point, (x1,y1): ");
	scanf("%f %f", &x1, &y1);
	printf("Enter co-ordinates of end point, (x2,y2): ");
	scanf("%f %f", &x2, &y2);
	
	x=x1;
	y=y1;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	
	xinc = dx/steps;
	yinc = dy/steps;
	putpixel(x,y,WHITE);
	
	for(int i=0; i<steps; i++){
		x+=xinc;
		y+=yinc;
		putpixel(x,y,WHITE);
	}
	
	getch();
	closegraph();
	return 0;
}
