#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
Node *head = NULL;
Node *last = NULL;

void insert(int num){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = num;
    if (head == NULL){
        head = new_node;
        last = new_node;
        last->next = head;
    }else{
        int iCase;
        Node* temp = head;
        cout << "Insert:" << endl
             << "1. At the begining" << endl
             << "2. At the Specific Position" << endl
             << "3. At the end" << endl;
        cin >> iCase;
        switch (iCase){
        case 1:
            new_node->next = temp;
            head = new_node;
            last->next = head;
            break;
        case 2:
            int pos;
            cout << "Enter the position to be inserted: ";
            cin >> pos;
            if(pos==1){
    			new_node->next = temp;
                head = new_node;
                last->next = head;
    			break;
			}
            for (int i = 1; i < pos-1; i++){
                temp = temp->next;
            }
            if (temp->next != head){
                new_node->next = temp->next;
                temp->next = new_node;
            }
            else{
                new_node->next = head;
                temp->next = new_node;
                last = temp->next;
                break;
            }
            temp->next = new_node;
            break;
        case 3:
            new_node->next = head;
            temp->next = new_node;
            last = temp->next;
            break;
        default:
            cout<<"Invalid Choice!"<<endl;
            break;
        }
    }
}

void Delete(){
    if(head == NULL){
        cout<<"Empty!"<<endl;
        return;
    }
	int dCase;
	Node *temp = head;
	cout << "Delete:" << endl
         << "1. At the begining" << endl
         << "2. At the Specific Position" << endl
         << "3. At the end" << endl;
    cin >> dCase;
    
    switch(dCase){
    	case 1:
    		head = temp->next;
            last->next = head;
    		free(temp);
    		break;
    	case 2:
    		int pos;
    		cout<<"Enter the position to be deleted: ";
    		cin>>pos;
    		if(pos==1){
    			head = temp->next;
                last->next = head;
    			free(temp);
    			break;
			}
    		for(int i = 1; i < pos-1; i++)
    			temp = temp->next;
            free(temp->next);
            if(temp->next == last){
                last = temp;
                temp->next = head;
            }else
                temp->next = temp->next->next;
    		break;
    	case 3:
    		while(temp->next != last)
    			temp = temp->next;
    		free(temp->next);
            last = temp;
    		temp->next = head;
    		break;
    	default:
            cout<<"Invalid Choice!"<<endl;
            break;
	}
}

void traversal(){
    if (head == NULL)
    {
        cout << "The List is empty!!!" << endl;
    }
    else
    {
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
}

int main(){
    int caseN;
    char q;

    do{
        cout << "1. Insert" << endl
        	 << "2. Delete" <<endl
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

    // getch();
    return 0;
}
