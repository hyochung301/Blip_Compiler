//
// Created by Hyokwon Chung on 4/15/23.
//

#include "Project8.h"

map <string, int> symbo;
vector<string> command;


string tokenReader (const char *a) {
    string s = "";
    for (int i =0; a[i] != 0; i++) {
        s = s + a[i];
    }
    return s;
}

void getCommand() {
//cout<<next_token()<<endl;
    string tokenChecker = peek_next_token();
    for (; next_token_type != END && tokenChecker != "set" && tokenChecker != "output" && tokenChecker != "text" && tokenChecker != "var"; tokenChecker = peek_next_token()) {
    //for (; next_token_type != END && token != "set" && token != "output" && token != "text" && token != "var" ; read_next_token()) {
    read_next_token();
    string token = next_token();
        //cout<<token<<endl;
        if (token == "//"){skip_line();}
        command.push_back(next_token());
        //read_next_token();
//        token = peek_next_token();
    }
}
void displayText(){//
    //getCommand();
    read_next_token();
    command.push_back(next_token());
    for(int i=0; i < command.size(); i++) {
        cout << command.at(i) ; //<< endl;
    }


}
void initVAR(){
    //cout << next_token() << endl;
    read_next_token();
    //cout << next_token() << endl;
    string symbol = tokenReader(next_token());

    getCommand();
    //cout << next_token() << endl;

    //if already exits, generate a warning "varaible <varName> incorrectly re-initialized"
    if (symbo.count(symbol) == 1){cout<< "variable " << symbol << " incorrectly re-initialized" << endl;} //if previously declared, warning.
    symbo[symbol] = execute(command, symbo);    // set Var to change the variable

}

void setVAR(){
    //cout << next_token() << endl;
    read_next_token();
    //cout << next_token() << endl;
    string symbol = tokenReader(next_token());

    getCommand();
    //cout << next_token() << endl;
    //if it does not exits warn "varaible <varName> not declared".
    if (symbo.count(symbol) != 1){cout<< "variable " << symbol << " not declared" << endl;} //if previously not declared, warning.
    symbo[symbol] = execute(command, symbo);    //call init VAR to init


}
void run(){
    read_next_token();
    for(; next_token_type != END; read_next_token()){
        string token = next_token();
        if (token == "text"){
            displayText();
        }
        else if (token == "output"){
//            cout<<next_token()<<endl;
//            read_next_token();
//            cout<<next_token()<<endl;
//            if (next_token_type == NUMBER){
//                cout << next_token() << endl;
//            }
            //else {
                getCommand();
                cout << execute(command, symbo);
            //}
        }
        else if (token == "var"){
            initVAR();
        }
        else if (token == "set"){
            setVAR();
        }
        else if (token == "//"){skip_line();}
        command.clear();
    }
    symbo.clear();
}