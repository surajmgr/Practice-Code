#include<stdio.h>
#include<graphics.h>

int main(){
	float x1, y1, x2, y2;
	float dx, dy, steps, xinx, yinc;
	
	int gd = DETECT, gm, i;
	initgraph(&gd,&gm,"");
	
	printf("Enter the endpoints... (x1,y1): ");
	scanf("%f %f", &x1, &y1);
	printf("Enter the endpoints... (x2,y2): ");
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
	putpixel(x,y,RED);
	
	for(int i=0; i<steps; i++){
		x+=xinc;
		y+=yinc;
		putpixel(x,y,RED);
	}
	
	return 0;
}
