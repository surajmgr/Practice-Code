#include <iostream>
using namespace std;

int main(){
    int len = 5, tempK, j;
    int arr[len];
    
    cout<<"Enter the data: "<<endl;
    for(int i = 0; i < len; i++)
        cin>>arr[i];

    for(int i = 1; i < len; i++){
        tempK = arr[i];
        j = i - 1;
        // If the second element(tempK) is less than previous element
        // then assign the previous element in the second element
        // Decrease the j index to swap until it checks the first element (j=0)
        while(tempK < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        // If the above while loop isn't executed then,
        // the index will remain same i.e, the list will not change.
        arr[j+1] = tempK;
    }

    cout<<"Sorted list: "<<endl;
    for(int i = 0; i < len; i++)
        cout<<arr[i]<<"\t";
    cout << endl;
    
    return 0;
}