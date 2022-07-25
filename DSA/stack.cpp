#include <iostream>
using namespace std;

int main() {
   int caseN, val, stack[10], n=10, top=-1;
   char ch;
   
   do {
      cout<<"Press 1 for push operation"<<endl
      <<"Press 2 for pop operation"<<endl
      <<"Press 3 for Peek operation"<<endl
      <<"Press 4 for displaying thedata of stack."<<endl;
      cin>>caseN;
      switch(caseN) {
        case 1:
            cout<<"Enter the number to be pushed:"<<endl;
            cin>>val;
            if(top>=n-1)
                cout<<"Stack Overflow"<<endl;
            else {
              top++;
              stack[top]=val;
           }
           break;
        
        case 2:
            if(top<0)
                cout<<"Stack Underflow."<<endl;
            else
            {
                cout<<"The popped out number is: "<<stack[top]<<endl;
                top--;
            }
            break;

        case 3:
            if(top<0)
                cout<<"Stack is empty."<<endl;
            else
                cout<<"The peek element is: "<<stack[top]<<endl;
            break;
            
        case 4:
            if(top>=0){
                cout<<"Displaying stack: "<<endl;
                for(int i=top; i>=0; i--){
                    cout<<stack[i]<<endl;
                }
            }
            else
                cout<<"Stack is empty."<<endl;
            break;
            
         default: {
            cout<<"Invalid!"<<endl;
         }
      }
      cout<<"Do you want to continue? (y/n): ";
      cin>>ch;
   }while(ch=='y');
   return 0;
}

