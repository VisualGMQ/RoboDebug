#ifndef __ROBOLIB_HPP__
#define __ROBOLIB_HPP__
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>
#include <string>
#include <sstream>
#include <fcntl.h>
using namespace std;
int fifofile = -1;

#define SEND_VARIABLE(var) \
{\
    if(fifofile > 0){\
        string name = #var;\
        stringstream ss;\
        ss<<var;\
        string value;\
        while(!ss.eof()){\
            string tmp;\
            ss>>tmp;\
            value += tmp;\
        }\
        string str = name;\
        str += ":" + value+";";\
        cout<<"sended "<<str<<endl;\
        write(fifofile, str.c_str(), str.size());\
    }\
}

void initDebug(){
    fifofile = open("/tmp/robofifo", O_WRONLY|O_NONBLOCK);
    if(fifofile <= 0){
        cout<<"fifo can't be opened"<<endl;
        exit(0);
    }
}

void quitDebug(){
    if(fifofile > 0){
        close(fifofile);
    }
}
#endif