#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
Node *front = NULL;
Node *rear = NULL;

void insert(int num){
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = num;
    new_node->next = NULL;
    if(rear == NULL){
    	front = new_node;
    	rear = new_node;
	}else{
		rear->next = new_node;
    	rear = new_node;
	}
}

void Delete(){
	if(rear == NULL)
		cout<<"The list is empty!"<<endl;
	else{
		Node* temp = front;
		front = temp->next;
		free(temp);
	}
}

void traversal(){
    if (rear == NULL)
        cout << "The List is empty!!!" << endl;
    else{
        Node* temp = front;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    int caseN;
    char q;

    do{
        cout << "1. Insert" << endl
        	 << "2. Delete" << endl
             << "3. Display" << endl;
        cin >> caseN;
        switch (caseN){
            case 1:
                int n;
                cout << "Enter the number to be inserted: ";
                cin >> n;
                insert(n);
                break;
            case 2:
            	Delete();
            	break;
            case 3:	
                traversal();
                break;
            default:
                cout << "Invalid Choice!!!" << endl;
                break;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> q;
    } while (q == 'y');

    getch();
    return 0;
}
