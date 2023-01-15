// C++ code to linearly search x in arr[].
// If x is present then return its location,
// otherwise return -1

#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++) // loop through the array
        if (arr[i] == x)        // if x is present at i
            return i;           // return index of element
    return -1;
}

// Driver's code
int main()
{
    int len=5, arr[len];
	cout<<"Enter the data:";
	for( int i = 0 ; i < len; i++){
		cin>> arr[i];
	}

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    int result = search(arr, len, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index: " << result;
    return 0;
}
