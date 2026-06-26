#include <iostream>
#include "interface.h"
#include "logic.h"
#include <string>

using namespace std;

int Interface::displayFirstPage(){

    int option;

    
    cout<<"|-------------------------------|"<<endl;
    cout<<"|   Welcome to TM SmartBank 🏦  |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|    1.  Register               |"<<endl;
    cout<<"|    2.  Login                  |"<<endl;
    cout<<"|    3.  Exit                   |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|-------------------------------|"<<endl;
    cin>>option;
    
    return option;
}

void Interface::displayLogin(Logic logic1){

    cout<<"Welcome back"<<endl;
    identifictionNumber();
    string pin;
    cout<<"Enter your pin"<<endl;
    cin>>pin;

    Interface::pin = new string(pin);

    bool result =  logic1.verifyIdentity("login");

    
}

void Interface::displayRegister(Logic logic1){
    cout<<"Welcome the registration menu"<<endl;
    identifictionNumber();

    string registerPin,confirmPin;
    int count;
    do{
        if(count>0){
            cout<<"Password don't match try again "<<endl;
            cout<<endl;
        }

        cout<<"Enter your pin: "<<endl;
        cin>>registerPin;
        
        cout<<"Confirm your pin: "<<endl;
        cin>>confirmPin;
        
        count++;
    }
    while(registerPin!=confirmPin);

    Interface::pin = new string(registerPin);
    bool result = logic1.verifyIdentity("register");
}

void Interface::identifictionNumber(){
    
    string id;
    cout<<"Enter your ID number:"<<endl;
    cin>>id;
    Interface::id = new string(id);

}

void Interface::invalidInput(){

    cout<<"Invalid input please try again⚠️"<<endl;
}


Interface::~Interface(){

        //Deleting dynamically allocated properties
        delete id;
        id = NULL;
        delete pin;
        pin = NULL;
        delete accountNumber;
        accountNumber = NULL;

    }