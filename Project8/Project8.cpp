//
// Created by Hyokwon Chung on 4/15/23.
//

#include "Project8.h"

map <string, int> symbo;
vector<string> command;

void getCommand() {
    for (; next_token() != "set" && next_token() != "output" && next_token() != "text" && next_token() != "var" ; read_next_token()) {
        if (next_token() == "//"){skip_line();}
        command.push_back(next_token());
    }
}
void displayText(){//
    while ()
    if (next_token() == "//"){skip_line();}

}
void initVAR(){
    //if already exits, generate a warning "varaible <varName> incorrectly re-initialized"
    string symbol = next_token();
    if (symbo.count(symbol) == 1){cout<< "variable" << symbol << "incorrectly re-initialized" << endl;} //if previously declared, warning.
    symbo[symbol] = execute(command);    // set Var to change the variable

}

void setVAR(){
    //if it does not exits warn "varaible <varName> not declared".
    string symbol = next_token();
    if (symbo.count(symbol) != 1){cout<< "variable" << symbol << "not declared" << endl;} //if previously not declared, warning.
    symbo[symbol] = execute(command);    //call init VAR to init


}
void run(){
for(; next_token_type != END; read_next_token()){
    string token = string (next_token());
    if (token == "text"){
        displayText();
    }
    else if (token == "output"){
        getCommand();
    }
    else if (token == "var"){
        initVAR();
    }
    else if (token == "set"){
        setVAR();

    }

};

}