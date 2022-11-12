#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#define max 10
using namespace std;

int factorial(int n){
	if(n==0)
		return 1;
	else
		return n*(factorial(n-1));
}

float cTerm(int n,int i){
	if(n<i)
		cout<<"invalid";
	else
		return factorial(n)/(factorial(n-i)*factorial(i));
}

float result(int a[max],int n,int i,float u){
	float sum=0;
	int j;
	for(j=i;j<=n;j++)
		sum=sum+(a[j]*cTerm(n,j)*pow(u,j)*pow(1-u,n-j));
	return sum;
}

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	int n,k,i=0;
	printf("Enter number of control points: ");
	scanf("%d", &n);

	int x[n-1],y[n-1];
	printf("Enter control points (one pair at a time): \n");
	for(k=0;k<n;k++)
		scanf("%d %d", &x[k], &y[k]);
	
	double q;
	for(q=0.0;q<1.0;q=q+0.0005){
		double xp,yp;
		xp=result(x,n-1,i,q);
		yp=result(y,n-1,i,q);
		putpixel(xp,yp,WHITE);
	}

	getch();
	delay(5000);
	closegraph();
	return 0;
}	
