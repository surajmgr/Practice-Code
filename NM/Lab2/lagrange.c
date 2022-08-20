#include <stdio.h>
#include <math.h>
#define MAX 15

int main(){
    int n;
    float x[MAX], f[MAX], xp, fp, p;
    char q;

    printf("\nEnter the total no. of data pairs: ");
    scanf("%d", &n);
    printf("\nEnter x(i) and f(i), (one pair at a time): ");

    for (int i = 0; i < n; i++){
        scanf("%f %f", &x[i], &f[i]);
    }

    do{
        printf("\nEnter the point, x at which interpolation is required: ");
        scanf("%f", &xp);
        fp = 0;
        for(int i=0; i<n; i++){
		    p=1;
		    for(int j=0; j<n; j++){
			    if(i!=j){
			       	p = p* (xp - x[j])/(x[i] - x[j]);
			    }
		    }
		  fp = fp + p * f[i];
        }
        printf("\nThe interpolated function value at x = %.5f is %.5f.", xp, fp);
        printf("\nDo you want to contitnue? (y/n): ");
        scanf("%c", &q);
    } while (q == 'y');
    return 0;
}