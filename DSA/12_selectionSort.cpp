#include <iostream>
using namespace std;

int main(){
    int len = 5, least, leastIndex;
    int arr[len];
    
    cout<<"Enter the data: "<<endl;
    for(int i = 0; i < len; i++)
        cin>>arr[i];

    for(int i = 0; i < len; i++){
        least = arr[i];
        leastIndex = i;
        for(int j = i+1; j < len; j++){
            if (arr[j] < arr[leastIndex]){
                least = arr[j];
                leastIndex = j;
            }
        }
        int temp = arr[leastIndex];
        arr[leastIndex] = arr[i];
        arr[i] = temp;
    }

    cout<<"Sorted list: "<<endl;
    for(int i = 0; i < len; i++)
        cout<<arr[i]<<"\t";
    cout << endl;
    
    return 0;
}