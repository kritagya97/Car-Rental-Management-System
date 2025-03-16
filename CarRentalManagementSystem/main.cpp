#include <iostream>
using namespace std;

int main(){
int choice;
    // Project Name Decoration 
    cout<<"\t____________________________________________________________________________"<<endl;
    cout<<"\t|                          Car Rental Management System                     |"<<endl;
    cout<<"\t|___________________________________________________________________________|"<<endl;
    //display user choice
    cout<<"\t\t  1  Login as Admin\t\t"<<endl;
    cout<<"\t\t  2  Login as Employee\t\t"<<endl;
    cout<<"\t\t 99  Exit \t\t"<<endl;
    cout<<"\t____________________________________________________________________________"<<endl;

    //user input 
    cout<<"\t\t  Enter Your Choice\t\t"<<endl;
    cout<<"\t\t  > ";
    cin>>choice;

    switch(choice){
        case 1:
                
                break;

        case 2:

                break;
        
        case 99:    
                return 0;
                break;
        default:
                cout<<"\t\t Please Enter Valid Choice \t\t"<<endl;

    }

        
return 0;
}
