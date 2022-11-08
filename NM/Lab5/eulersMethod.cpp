#include <stdio.h>
#include <math.h>
#include <conio.h>

float f(float x, float y) {
  return x * x + y * y;
}

int main() {
  int i, n;
  float x, y, xp, h, dy;
  printf("\nInput initial values of x and y: ");
  scanf("%f%f", & x, & y);
  printf("\nInput x at which y is required: ");
  scanf("%f", & xp);
  printf("\nInput step-size h: ");
  scanf("%f", & h);
  n = (int)((xp - x) / h + 0.5);
  for (i = 1; i <= n; i++) {
    dy = h * f(x, y);
    x = x + h;
    y = y + dy;
    printi("\n%d\t %f\t %f\n", i, x, y);
  }
  printf("\nValue of y at x = %f is %f\n", xp, y);
  getch();
  return 0;
}
