#include "debugger.hpp"

int debugger::fifofile = -1;

debugger::debugger(){
    debugger::fifofile = open("/tmp/robofifo", O_RDONLY);
    signal(SIGINT, this->handle);
    openFifo();
    isChanged = false;
}

const map<string, string>& debugger::getVariables(){
    return this->variables;
}

void debugger::readAndParse(){
    readData();
}

void debugger::handle(int signum){
    if(signum == SIGINT){
        if(debugger::fifofile > 0)
            close(fifofile);
        cout<<"client is quit"<<endl;
        exit(EXIT_SUCCESS);
    }
}

void debugger::openFifo(){
    int ref = mkfifo("/tmp/robofifo", 0777);
    if(ref == -1){
        cout<<"fifo is not created or is exits"<<endl;
    }
    if(fifofile <= 0){
        cout<<"please create the pip first"<<endl;
        exit(EXIT_FAILURE); 
    }
}

void debugger::parse(string msg){
    stringstream ss;
    ss<<msg;
    while(!ss.eof()){
        string str;
        getline(ss, str, ';');
        stringstream ss2;
        ss2<<str;
        string name, value;
        getline(ss2, name, ':');
        getline(ss2, value, ':');
        if(name != "\0" && name != "\n"){
            if(this->variables.find(name) == this->variables.end() || this->variables[name] != value){
                this->variables[name] = value;
                /*
                cout<<"name"<<name<<endl;
                cout<<"value"<<value<<endl;
                */
                isChanged = true;
            }
        }
    }
}

void debugger::readData(){
        char data[1024] = {'\0'};
        int len = read(fifofile, data, sizeof(data));
        if(len > 0){
            parse(data);
        }
}

debugger::~debugger(){
    if(debugger::fifofile > 0)
        close(debugger::fifofile);
}