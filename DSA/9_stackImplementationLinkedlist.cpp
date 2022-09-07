#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
Node *top = NULL;

void push(int num){
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = num;
	new_node->next = top;
	top = new_node;
}

void pop(){
	if(top == NULL)
		cout<<"The list is empty!"<<endl;
	else{
		Node* temp = top;
		top = temp->next;
		free(temp);
	}
}

void peak(){
    if (top == NULL)
        cout << "The List is empty!!!" << endl;
    else
        cout<<"Peak data is: "<<top->data<<endl;
}

void traversal(){
    if (top == NULL)
        cout << "The List is empty!!!" << endl;
    else{
        Node* temp = top;
        while (temp != NULL)
        {
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
        cout << "1. Push" << endl
        	 << "2. Pop" << endl
             << "3. Peak" << endl
             << "4. Display" << endl;
        cin >> caseN;
        switch (caseN){
            case 1:
                int n;
                cout << "Enter the number to be inserted: ";
                cin >> n;
                push(n);
                break;
            case 2:
            	pop();
            	break;
            case 3:
                peak();
                break;
            case 4:	
                traversal();
                break;
            default:
                cout << "Invalid Choice!!!" << endl;
                break;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> q;
    } while (q == 'y');

    // getch();
    return 0;
}
