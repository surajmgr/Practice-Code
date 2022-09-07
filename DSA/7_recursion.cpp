#include <iostream>
using namespace std;

int factorial(int n){
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n){
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void towerOfHanoi(int n, char source, char temp, char destination)
{
    if (n == 1){
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    
    towerOfHanoi(n - 1, source, destination, temp);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, temp, source, destination);
}

int main(){
    int caseN, n;
    char q;

    do{
        cout << "1. Factorial" << endl
        	 << "2. Fibonacci" << endl
             << "3. GCD" << endl
             << "4. Tower of Hanoi" << endl;
        cin >> caseN;
        switch (caseN){
            case 1:
                cout << "Enter a number: ";
                cin >> n;
                cout << "Factorial of " << n << ": " << factorial(n) << endl;
                break;
            case 2:
                cout << "Enter a number: ";
                cin >> n;
                cout << "Fibonacci number of " << n << ": " << fibonacci(n) << endl;
            	break;
            case 3:
                int a, b;
                cout << "Enter two non-negative integers - (a,b): ";
                cin >>a>>b;
                cout << "G.C.D (" << a << ", " << b << "): " << gcd(a, b) << endl;
                break;
            case 4:	
                cout << "Enter the number of disks: ";
                cin >> n;
                towerOfHanoi(n, 'A', 'B', 'C');
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