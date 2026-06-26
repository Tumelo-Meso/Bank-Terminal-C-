#include <iostream>
#include "interface.h"
#include "logic.h"
#include <string>
using namespace std;


Logic logic1("data/data.csv");

int main(){

    Interface interface1;
    
    int option; 
    do{
        option = interface1.displayFirstPage();

        switch(option){

            case 1:
                interface1.displayRegister(logic1);
                break;
            
            case 2:
                interface1.displayLogin(logic1);
                break;
            
            case 3:
                cout<<"Closing application...."<<endl;
                break;
            
            default:
                interface1.invalidInput();
                break;
        }
        
    }while(option!=3);

    cout<<"Thank you for using TM SmartBank 👍"<<endl;

    return 0;
}