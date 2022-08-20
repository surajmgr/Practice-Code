#include<iostream>
// #include<conio.h>
using namespace std;

int main(){
	int max=10;
	int que[max], front, rear, num, caseN;
	char q;
	
	do{
		cout<<"Press: "<<endl<<"1. Empty Queue"<<endl<<"2. Enqueue"<<endl<<"3. Dequeue"<<endl<<"4. Queue Traversal"<<endl;
		cin>>caseN;
		switch(caseN){
			case 1:
				front=rear=-1;
				cout<<"Empty!"<<endl;
				break;
			case 2:
				if(front==rear+1){
					cout<<"Overflow!"<<endl;
				}
				else{
					if (front == -1)
						front = 0;
					cout<<"Enter the number to be enqueued: ";
					cin>>num;
					rear = (rear + 1) % max;
					que[rear] = num;
				}
				break;
			case 3:
				if(front==rear){
					front=rear=-1;
					cout<<"Empty!"<<endl;
				}
				else{
					front = (front + 1) % max;
				}
				break;
			case 4:
				if (front==rear) {
					cout << "Empty!" << endl;
				}
				else{
					cout<<"Displaying data: "<<endl;
					for (int i = front; i != rear; i = (i + 1) % max)
						cout << que[i]<<endl;
				}
				break;
	}
	cout<<"Do you want to continue? (y/n): ";
	cin>>q;
	}while(q=='y');
	
	// getch();
	return 0;
}