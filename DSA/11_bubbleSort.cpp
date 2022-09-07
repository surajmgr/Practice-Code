#include <iostream>
using namespace std;

int main(){
    int len = 5;
    int arr[len];
    
    cout<<"Enter the data: "<<endl;
    for(int i = 0; i < len; i++)
        cin>>arr[i];

    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if (arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout<<"Sorted list: "<<endl;
    for(int i = 0; i < len; i++)
        cout<<arr[i]<<"\t";
    cout << endl;
    
    return 0;
}