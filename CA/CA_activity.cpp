#include <iostream>
#include <string.h>
#include <cctype>
//#include <conio.h>
using namespace std;

char output(int x){
    char tempC;
    switch(x){
        case 1:
            tempC='.';
            break;

		case 11:
            tempC=',';
            break;

		case 111:
            tempC='1';
            break;
            
		case 2:
		    tempC='a';
			break;
			
		case 22:
		    tempC='b';
			break;
				
		case 222:
			tempC='c';
			break;
		
		case 2222:
			tempC='2';
			break;
			 
		case 3:
			tempC='d';
			break;
		
		case 33:
			tempC='e';
			break;
		
		case 333:
			tempC='f';
			break;
		
		case 3333:
			tempC='3';
			break;
		
		case 4:
			tempC='g';
			break;
		
		case 44:
			tempC='h';
			break;
		
		case 444:
			tempC='i';
			break;
		
		case 4444:
			tempC='4';
			break;
			
		case 5:
			tempC='j';
			break;
		
		case 55:
			tempC='k';
			break;
		
		case 555:
			tempC='l';
			break;
			
		case 5555:
		    tempC='5';
		    break;
		
		case 6:
			tempC='m';
			break;
		
		case 66:
			tempC='n';
			break;
		
		case 666:
			tempC='o';
			break;
			
		case 6666:
		    tempC='6';
		    break;
		
		case 7:
			tempC='p';
			break;
		
		case 77:
			tempC='q';
			break;
		
		case 777:
			tempC='r';
			break;
			
		case 7777:
		    tempC='s';
		    break;
		    
		case 77777:
		    tempC='7';
		    break;
		
		case 8:
			tempC='t';
			break;
		
		case 88:
			tempC='u';
			break;
	    
	    case 888:
			tempC='v';
			break;
		
		case 8888:
			tempC='8';
			break;
		
		case 9:
			tempC='w';
			break;
		
		case 99:
			tempC='x';
			break;
		
		case 999:
			tempC='y';
			break;
			
		case 9999:
			tempC='z';
			break;
			
	    case 99999:
			tempC='9';
			break;
			
		case 0:
		    tempC=' ';
		    break;
			
		default :
		    cout<<"Invalid input!";
		    tempC='*';
			break;
	}
    return tempC;
}

void instruction(){
    cout<<"Guide:"<<endl;
    cout<<"Keypad: "<<endl;
	cout<<"1:.,     2:abc   3:def"<<endl<<"4:ghi    5:jkl   6:mno"<<endl<<"7:pqrs   8:tuv   9:wxyz"<<endl<<"0: space"<<endl;
	cout<<"Example: 777 -> r"<<endl;
    cout<<"For numbers, type one excessive repetition. i.e, 2222 -> 2"<<endl<<"Uppercase: *#  Delete: *  Stop: #  Help: **"<<endl<<endl;
}

int main(){
    int num=10;
    int count=0;
    string tempInp;

    string *dataN = new string[num];

    instruction();

    do{
        cout<<"Input: ";
        cin>>tempInp;
        if(tempInp!="*" && tempInp!="#" && tempInp!="**" && tempInp!="00" && tempInp!="*#"){
            dataN[count]=output(stoi(tempInp));
            count++;
        }
        else if(tempInp=="*"){
            if (count>=1)
                count--;
        }
        else if(tempInp=="**"){
            instruction();
        }
		else if(tempInp=="00"){
			dataN[count]='0';
			count++;
		}
		else if(tempInp=="*#"){
			cout<<"Uppercase Input: ";
			cin>>tempInp;
			dataN[count]=toupper(output(stoi(tempInp)));
			count++;
		}
        cout<<"Output: ";
        for(int i=0; i<count; i++){
        cout<<dataN[i];
        }
        cout<<endl;
        
    }while(tempInp!="#"); 

    cout<<endl<<endl;
    cout<<"You have written: ";
    for(int i=0; i<count; i++){
        cout<<dataN[i];
    }
    cout<<endl;
    
    //getch();
    return 0;
}