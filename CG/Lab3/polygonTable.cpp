#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	int ver, face;
	
	int gdriver= DETECT, gmode;
	initgraph(&gdriver, &gmode, "D:\\TURBOC3\\BGI");
	
	printf("Enter the number of faces: ");
	scanf("%d", &face);
	
	do{
		printf("Enter the number of vertices in face %d: ", face);
		scanf("%d", &ver);
		int poly[ver];
		
		for(int i=0; i<(ver*2); i+++){
			printf("Enter vertex from face %d (x,y): ", face);
			scanf("%d %d", &poly[i], &poly[i+1]);
			i++;
		}
		face--;
	}while(face>1);
	
	drawpoly(ver, poly);
	getch();

	closegraph();
	return 0;
}
