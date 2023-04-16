//
// Created by Hyokwon Chung on 4/15/23.
//

#include "Project8.h"

map <string, int> symbo;
vector<string> command;


void displayText(){//
    read_next_token();
    if (next_token() == )
};
void initVAR(){
    //if already exits, generate a warning "varaible <varName> incorrectly re-initalized"

    //call set Var to change the variable
}

void setVAR(){
    //if it does not exits warn "varaible <varName> not declared".
    //call init VAR to init

}
void run(){
for(; next_token_type != END; read_next_token()){
    string token = string (next_token());
    if (token == "text"){
        displayText();

    }
    else if (token == "output"){

    }
    else if (token == "var"){
        initVAR();
    }
    else if (token == "set"){
        setVAR();

    }

};

}