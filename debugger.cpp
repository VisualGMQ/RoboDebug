#include "debugger.hpp"

int debugger::fifofile = -1;

debugger::debugger(){
    debugger::fifofile = open("/tmp/robofifo", O_RDONLY);
    signal(SIGINT, this->handle);
    openFifo();
    isChanged = false;
}

void debugger::loopRead(){
    while(true){
        readData();
    }
}

void debugger::showDebugInfo(){
    if(isChanged){
        cout<<"\033[2J";
        for(auto it = variables.begin(); it != variables.end(); it++){
            cout<<it->first<<":"<<it->second<<endl;
        }
        isChanged = false;
    }
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
        cout<<"fifo is not created"<<endl;
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
            if(variables.find(name) == variables.end() || variables[name] != value){
                variables[name] = value;
                isChanged = true;
            }
        }
    }
}

void debugger::readData(){
    while(true){
        char data[1024] = {'\0'};
        int len = read(fifofile, data, sizeof(data));
        if(len > 0){
            parse(data);
            showDebugInfo();
        }
    }
}

debugger::~debugger(){
    if(debugger::fifofile > 0)
        close(debugger::fifofile);
}