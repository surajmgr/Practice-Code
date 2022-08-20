#include <iostream>
// #include<conio.h>
using namespace std;

int main(){
	int max = 3;
	int que[max], front = -1, rear = -1, num, caseN;
	char q;

	do{
		cout << "Press: " << endl
			 << "1. Empty Queue" << endl
			 << "2. Enqueue" << endl
			 << "3. Dequeue" << endl
			 << "4. Queue Traversal" << endl;
		cin >> caseN;
		switch (caseN){
		case 1:
			front = rear = -1;
			cout << "Empty!" << endl;
			break;
		case 2:
			if ((front == 0 && rear == max - 1) || (front == rear + 1)){
				cout << "Overflow!" << endl;
			}
			else{
				cout << "Enter the number to be enqueued: ";
				cin >> num;
				if (front == -1 && rear == -1)
					front = rear = 0;
				else if (rear == max - 1 && front != 0){
					rear = 0;
				}
				else
					rear += 1;
				que[rear] = num;
			}
			break;
		case 3:
			if (front == -1){
				cout << "Underflow!" << endl;
			}
			else if (front == rear){
				front = rear = -1;
				cout << "Empty!" << endl;
			}
			else{
				if (front == max-1)
					front = 0;
				else
					front += 1;
			}
			break;
		case 4:
			if (front == -1){
				cout << "Empty!" << endl;
			}
			else{
				cout << "Displaying data: " << endl;
				if(front <= rear){
					for (int i = front; i <= rear; i++)
						cout<< que[i] <<endl;
				}
				else
				{
					for (int i = front; i < max; i++)
						cout << que[i] <<endl;
					for (int i = 0; i <= rear; i++)
						cout << que[i] <<endl;
				}
			}
			break;
		}
		cout << "Do you want to continue? (y/n): ";
		cin >> q;
	} while (q == 'y');

	// getch();
	return 0;
}