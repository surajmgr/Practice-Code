#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main() {
	char a[16];
	int i,j,k,len;
	loop:
	cout<<"Enter a valid binary number"<<endl;
	gets(a);
	len=strlen(a);
	for(k=0;a[k]!='\0';k++){
		if(a[k]!='1'&&a[k]!='0'){
			cout<<"Invalid binary number."<<endl<<endl;
			goto loop;
		}
	}
	for(i=len-1;a[i]!='1';i--);
	for(j=i-1;j>=0;j--){
		if(a[j]=='1')
			a[j]='0';
		else
			a[j]='1';
	}
	
	cout<<"The 2's complement of the entered number is: "<<a;
}