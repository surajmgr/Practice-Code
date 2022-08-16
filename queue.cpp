#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int max = 10;
	int que[max], front=-1, rear=-1, caseN, num;
	char q;
	
	do{
		cout<<"Press: "<<endl<<"1: make queue empty"<<endl<<"2: Enqueue"<<endl<<"3: Dequeue"<<endl<<"4:Queue Traversal"<<endl;
		cin>>caseN;
		switch(caseN){
			case 1:
				rear=-1;
				front=-1;
				cout<<"Empty!"<<endl;
				break;
			case 2:
				if(rear==max-1){
					cout<<"Overflow!"<<endl;
				}
				else{
					cout<<"Enter the number to be enqueued: ";
					cin>>num;
					rear++;
					que[rear]=num;
					if(front==-1){
						front++;
					}
				}
				break;
			case 3:
				if(front==-1 || front>rear){
					cout<<"Underflow!"<<endl;
				}
				else{
					int temp = que[front];
					front++;
					cout<<"The deleted num is "<<temp<<"."<<endl;
				}
				break;
			case 4:
				if(front==-1 || front>rear){
					cout<<"Empty!"<<endl;
				}
				else{
					cout<<"Displaying the data: "<<endl;
					for(int i= front; i<=rear; i++){
						cout<<que[i]<<endl;
					}
				}
				break;
		}
		cout<<"Do you want to continue? (y/n):";
		cin>>q;
	} while (q=='y');
	
	getch();
	return 0;
}
