#include <iostream>
#include "logic.h"
#include "interface.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


Logic::Logic(string file){

    Logic::filename = new string(file);

}
bool Logic::verifyIdentity(string path ){

    Data * data = readFile();

    if(data ==nullptr){
        cout<<"Could not open file"<<endl;
        return false;
    }

    for(int i = 0; i <Logic::dataSize ; i++){

        if(Logic::data->id == data[i].id){

            if(path =="register"){
                cout<<"Account already exists, please login"<<endl;
                return false;
            } 

            if(Logic::data->pin == data[i].pin){
                return true;
            }
        } 
    }
    
    return false;
}

Data * Logic::readFile(){

    ifstream infile;
    infile.open(Logic::filename->c_str());
    if(!(infile.is_open())){
        return nullptr;
    }

    int size;
    string countLine;
    while(infile>>countLine){
        size++;
    }

    Logic::dataSize = size;
    Logic::data = new Data[size];
    string line;
    int counter = 0 ;

    while(infile>>line){

        stringstream ss(line);

        string id,name,pin,accountNumber,balance;
    
        getline(ss,id,',');
        getline(ss,name,',');
        getline(ss,pin,',');
        getline(ss,accountNumber,',');
        getline(ss,balance,',');

        double bal = strToDouble(balance);

        Logic::data[counter] = {id,name,pin,accountNumber,bal};
        counter++;
    }


    return Logic::data;

   
}

double strToDouble(string balance){

    stringstream ss(balance);
    double bal;
    ss>>bal;

    return bal;
}
bool Logic::writeFile(){

    ofstream outfile;
    outfile.open(Logic::filename->c_str());
    if(outfile.is_open()){
        return true;
    }

    return false;
}


double Bank::getBalance(){
    return Bank::data.balance;
}
string Bank::getId(){
    return Bank::data.id;
}
string Bank::getAccountNumber(){
    return Bank::data.acccountNumber;
}
string Bank::getName(){
    return Bank::data.name;
}



void Bank::printInfo(){

    double balance = Bank::getBalance();
    string id = Bank::getId();
    string name = Bank::getName();
    string accountNumber = Bank::getAccountNumber();

    cout<<"Name: "<<name <<" | ID: "<<id<<endl;
    cout<<"Account Number: "<<accountNumber << " | Balance: "<< balance <<endl;
}

void Bank::setInfo(Data info){

    Bank::data.balance= info.balance;
    Bank::data.acccountNumber = info.acccountNumber;
    Bank::data.pin = info.pin;
    Bank::data.name = info.name;
}
Logic::~Logic(){


    delete filename;
    filename = NULL;

    delete [] data;
    data = NULL;
}