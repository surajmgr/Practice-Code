#include <stdio.h>
#include <math.h>
#include <conio.h>
#define max 10

int pivot(int n, float a[max][max], float b[max], int k){
	int p, i, j;
	float large, temp;
	p=k;
	large=fabs(a[k][k]);
	for(i=k+1; i<=n; i++){
		if(fabs(a[i][k])>large){
			large=fabs(fabs(a[i][k]));
			p=i;
		}
	}
	if(p!=k){
		for(j=k; j<=n; j++){
			temp=a[p][j];
			a[p][j]=a[k][j];
			a[k][j]=temp;
		}
		temp=b[p];
		b[p]=b[k];
		b[k]=temp;
	}
	return 0;
}

int elim(int n, float a[max][max], float b[max]){
	int i, j, k;
	float factor;
	for(k=1; k<=n-1; k++){
		pivot(n,a,b,k);
		for(i=k+1; i<=n; i++){
			factor=a[i][k]/a[k][k];
			for(j=k+1;j<=n;j++)
				a[i][j]=a[i][j]-factor*a[k][j];
			b[i]=b[i]-factor*b[k];
		}
	}
	return 0;
}

int bsub(int n, float a[max][max], float b[max], float x[max]){
	int i, j, k;
	float sum;
	x[n]=b[n]/a[n][n];
	for(k=n-1; k>=1; k--){
		sum=0.0;
		for(j=k+1;j<=n;j++)
			sum+=a[k][j]*x[j];
		x[k]=(b[k]-sum)/a[k][k];
	}
	return 0;
}

int gauss2(int n, float a[max][max], float b[max], float x[max]){
	elim(n, a, b);
	bsub(n, a, b, x);
	return 0;
}

int main(){
	int i, j, n;
	float a[max][max], b[max], x[max];
	printf("\nInput the number of variables: ");
	scanf("%d", &n);
	printf("\nInput coefficients a(i,j), row-wise (one row on each line): \n");
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%f", &a[i][j]);
	printf("\nEnter vector b: ");
	for(i=1; i<=n; i++)
		scanf("%f", &b[i]);
	gauss2(n,a,b,x);
	printf("\nSolution vector x: \n");
	for(i=1; i<=n; i++)
		printf("\t %f", x[i]);
	getch();
	return 0;
}
