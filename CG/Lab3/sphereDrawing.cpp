# include <iostream>
# include <graphics.h>
# include <conio.h>
# include <math.h>
# define f 0.3
# define projection_angle 45

void Sphere(int _x, int _y, int _z, int r){
   int x=_x, y=_y, z=_z;
   get_projected_point(x,y,z);
   for(int angle=2;angle<=r;angle+=5){
         ellipse(x,y,0,360,r,angle);
         ellipse(x,y,0,360,angle,r);
   }
}

void get_projected_point(int& x,int& y,int& z){
   float fcos0=(f*cos(projection_angle*(M_PI/180)));
   float fsin0=(f*sin(projection_angle*(M_PI/180)));

   float Par_v[4][4]={
      {1,0,0,0},
      {0,1,0,0},
      {fcos0,fsin0,0,0},
      {0,0,0,1}
   };

   float xy[4]={x,y,z,1};
   float new_xy[4]={0};

   multiply_matrices(xy,Par_v,new_xy);

   x=new_xy[0];
   y=new_xy[1];
   z=new_xy[2];
}

void multiply_matrices(float matrix_1[4], float matrix_2[4][4], float matrix_3[4]){
   for(int count_1=0;count_1<4;count_1++){
      for(int count_2=0;count_2<4;count_2++)
        matrix_3[count_1] += (matrix_1[count_2]*matrix_2[count_2][count_1]);
   }
}


int main( ){
   int x, y, z, r;
   char q;
   int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

   do{
      printf("Enter the coordinates of center - (x,y,z) :");
		scanf("%d %d %d", &x, &y, &z);

      printf("Enter the radius: ");
      scanf("%d", &r);

      Sphere(x,y,z,r);
      print("Do you want to continue? (y/n): ");
      scanf(" %c", &q);
   }while(q=='y');
	getch();
	closegraph();
   return 0;
}