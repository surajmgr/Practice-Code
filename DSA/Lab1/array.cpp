#include <iostream>
using namespace std;

int main() {
    int caseN, aNum, num, pos;
    char ch;
    
    cout<<"Enter the size of array: ";
    cin>>aNum;
    
    int arr[aNum];
    
    cout<<"Enter the numbers: "<<endl;
    for (int i=0; i<aNum; i++){
        cin>>arr[i];
    }
    
    do{
        cout<<"Press 1 for insertion in the begining"<<endl
            <<"Press 2 for insertion in the specific position"<<endl
            <<"Press 3 for insertion in the end"<<endl
            <<"Press 4 for displaying the array."<<endl;
        cin>>caseN;
        
        switch(caseN){
            case 1:
                //Insertion in the begining
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                for(int i=aNum; i>0; i--){
                    arr[i]=arr[i-1];
                }
                arr[0]=num;
                aNum++;
                break;
            case 2:
                //Insertion in the specific position
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                cout<<"Enter the position to be placed: ";
                cin>>pos;
                pos--;
                for(int i=aNum; i>pos; i--){
                    arr[i]=arr[i-1];
                }
                arr[pos]=num;
                aNum++;
                break;
            case 3:
                //Insertion in the end
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                arr[aNum]=num;
                aNum++;
                break;
            case 4:
                cout<<"Displaying Output: "<<endl;
                for(int i=0; i<aNum; i++){
                    cout<<arr[i]<<endl;
                }
                break;
            default:
                cout<<"Invalid input.";
        }
        
        cout<<"Do you want to continue? (y/n): ";
        cin>>ch;
    }while(ch=='y');

    return 0;
}