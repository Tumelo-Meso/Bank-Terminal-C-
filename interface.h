#ifndef INTERFACE_H
#define INTERFACE_H

class Interface {
    
    private:
        std::string * id;
        std::string * pin;
        std::string * accountNumber;
        

    public:
        int displayFirstPage();
        void identifictionNumber();
        void displayLogin(Logic logic1);
        void displayRegister(Logic logic1);
        void invalidInput();

    ~Interface();
};


#endif