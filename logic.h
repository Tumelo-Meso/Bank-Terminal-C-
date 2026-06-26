#ifndef LOGIC_H
#define LOGIC_H


class Logic {

    private:
        std::string * filename;
        int dataSize ;
        Data * data; 
        

    
    public:
        bool verifyIdentity(std::string path);
        Data * readFile();
        bool writeFile();
        Logic(std::string file);
    
    ~Logic();
};

class Bank {
    private:
        Data data;

    public:

        double getBalance();
        string getId();
        string getAccountNumber();
        string getName();
        void withdraw();
        void printInfo();
        void deposit();

        void setInfo(Data info);
        

};

struct Data {
   
    std::string id;
    std::string name;
    std::string pin;
    string acccountNumber;
    double balance;
};


double strToDouble(string balance);

#endif