// Problem
// Code
#include<stdio.h>
#include<malloc.h>
int *a,*q,*m,*mc,*c,n,d;
int powr(int x,int y)
{
 int s=1,i;
 for(i=0;i<y;i++)
   s=s*x;
 return s;
}
int main()
{
int a[10],m[10],q[10],i,j,c=0,b[10],mc[10],z=0,s[10],x[10];
printf("\nEnter Divisor [M] : ");
for(i=4;i>=1;i--)
{
scanf("%d",&m[i]);
mc[i]=!m[i];
a[i]=0, x[i]=0;
}
x[1]=1, x[5]=0, m[5]=0, mc[5]=1;
for(i=1;i<=5;i++)
{
s[i]=x[i]^mc[i]^z;
c=(x[i]&&mc[i])||(x[i]&&z)||(mc[i]&&z);
z=c;
mc[i]=s[i];
}
printf("\n\nEnter Divident [Q] : ");
for(i=4;i>=1;i--)
{
scanf("%d",&q[i]);
}
printf("\n\n\n Step \t\t Action Performed \t\t A \t\tQ\n");
printf("\n\n 0\t\t Initialization\t 0 0 0 0 0 \t ");
for(i=4;i>=1;i--)
{
printf(" %d",q[i]);
}
for(j=1;j<=4;j++)
{
printf("\n\n\n %d",j);
printf("\t\t Left Shift \t\t ");
for(i=5;i>=2;i--)
{
a[i]=a[i-1];
}
a[1]=q[4];
for(i=4;i>=2;i--)
{
q[i]=q[i-1];
}
for(i=5;i>=1;i--)
{
printf(" %d",a[i]);
}
printf("\t ");
for(i=4;i>=2;i--)
{
printf(" %d",q[i]);
}
if(a[5]==0)
{
z=0;
for(i=1;i<=5;i++)
{
s[i]=a[i]^mc[i]^z;
c=(a[i]&&mc[i])||(a[i]&&z)||(mc[i]&&z);
z=c;
a[i]=s[i];
}
if(a[5]==1)
{
q[1]=0;
}
else
{
q[1]=1;
}
printf("\n\n\t\t a = a-m\t\t ");
for(i=5;i>=1;i--)
{
printf(" %d",a[i]);
}
printf("\t ");
for(i=4;i>=1;i--)
{
printf(" %d",q[i]);
}
}
else
{
z=0;
for(i=1;i<=5;i++)
{
s[i]=a[i]^m[i]^z;
c=(a[i]&&m[i])||(a[i]&&z)||(m[i]&&z);
z=c;
a[i]=s[i];
}
if(a[5]==1)
{
q[1]=0;
}
else
{
q[1]=1;
}
printf("\n\n\t\t a = a+m\t\t ");
for(i=5;i>=1;i--)
{
printf(" %d",a[i]);
}
printf("\t ");
for(i=4;i>=1;i--)
{
printf(" %d",q[i]);
}
}
}
if(a[5]==1)
{
printf("\n\n\n 5");
for(i=1;i<=5;i++)
{
s[i]=a[i]^m[i]^z;
c=(a[i]&&m[i])||(a[i]&&z)||(m[i]&&z);
z=c;
a[i]=s[i];
}
printf("\t\t a = a+m\t\t ");
for(i=5;i>=1;i--)
{
printf(" %d",a[i]);
}
printf("\t ");
for(i=4;i>=1;i--)
{
printf(" %d",q[i]);
}
}
printf("\n\n\n\n\nQuotient [Q] :");
for(i=4;i>=1;i--)
{
printf(" %d",q[i]);
}
printf("\n\n\n\nRemainder [A] :");
for(i=4;i>=1;i--)
{
printf(" %d",a[i]);
}
return 1;
}
void print(int arr[],int n)
{
 int i;
 for(i=0;i<n;i++)
  printf("%d ",arr[i]);
}
void bin(int n, int arr[]){
    int r, i = 0;
    do{
        r = n % 2;
        n /= 2;
        arr[i] = r;
        i++;
    }while(n > 0);
 }
void set(int array[], int x){
    int i,tmp[20]={0};
    for(i = x -1; i >=0; i--)
  tmp[x-1-i]=array[i];
 for(i=0;i<x;i++)
  array[i]=tmp[i];
 }
int len(int x)
{
 int i=0;
 while(powr(2,i)<=x) i++;
 return ++i;
}

void addBinary(int a1[], int a2[])
{
    int bi[2]={0},ca[20]={0};
    int t=len(n),tmp=0;
    int *su=(int*)malloc(sizeof(int)*len(n));
 while(t-->0)
 {
  tmp=a1[t]+a2[t]+ca[t];
  bin(tmp,bi);
  su[t]=bi[0];
  ca[t-1]=bi[1];
  bi[0]=0;bi[1]=0;
 }
 for(t=0;t<len(n);t++)
  a1[t]=su[t];
 free(su);
 }

void twoCom(int arr[]){
    int i;
    int *one=(int*)malloc(sizeof(int)*len(n));
    for(i=0;i<len(n)-1;i++)
  one[i]=0;
 one[i]=1;
    for(i = 0; i < len(n); i++){
        arr[i]=1-arr[i];
    }
    addBinary(arr, one);
    free(one);
}
void ls(int alen,int blen)
{
 int i=0;
 for(i=0;i<alen-1;i++)
  a[i]=a[i+1];
 a[i]=q[0];
 for(i=0;i<blen-1;i++)
  q[i]=q[i+1];
 q[i]=-1;
}
void printaq()
{
 print(a,len(n));
 printf("\t");
 print(q,len(n)-1);
 printf("\t");
 printf("\n");
}
int main()
{
 int i,cnt=0;
 printf("Enter The Numerator/Denominator: ");
 scanf("%d/%d",&n,&d);
 q=(int*)malloc(sizeof(int)*len(n)-1);
 bin (n,q);
 m=(int*)malloc(sizeof(int)*(len(n)));
 bin(d,m);
 a=(int*)malloc(sizeof(int)*(len(n)));
 for(i=0;i<len(n);i++)
  a[i]=0;
 mc=(int*)malloc(sizeof(int)*(len(n)));
 bin(d,mc);
 set(q,len(n)-1);
 set(m,len(n));
 set(mc,len(n));
 twoCom(mc);
 cnt=len(n)-1;
 printf("\t    A\t\t   Q\t\t    M\t    Count\n");
 printf("\t---------\t-------\t\t--------- ---------\n");
 while(cnt>0)
 {
  printf("\t");
  print(a,len(n));
  printf("\t");
  print(q,len(n)-1);
  printf("\t");
  print(m,len(n));
  printf("\t%d\n",cnt);
  if(a[0]==1)
  {
   ls(len(n),len(n)-1);
   printf("LSHIFT\t");
   printaq();
   addBinary(a,m);
   printf("A=A+M\t");
   printaq();
  }
  else
  {
   ls(len(n),len(n)-1);
   printf("LSHIFT\t");
   printaq();
   addBinary(a,mc);
   printf("A=A-M\t");
   printaq();
  }
  if(a[0]==1)
  {
   q[len(n)-2]=0;
   addBinary(a,m);
  }
  else
   q[len(n)-2]=1;
  printf("A=A+M\t");
  printaq();
  cnt-=1;
  printf("\n");
 }
 return 0;
}