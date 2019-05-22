#ifndef __ROBOLIB_HPP__
#define __ROBOLIB_HPP__
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>
#include <string>
#include <fcntl.h>
using namespace std;
static int ref = -1;

#define SEND_VARIABLE(var)\
{\
    if(ref > 0){\
        string str = #var;\
        stringstream ss;\
        ss<<var;\
        string tmp;\
        ss>>tmp;\
        str += ":";\
        str += tmp;\
        write(ref, str.c_str(); strlen(str.c_str()));\
    }\
}

void initDebug(){
    int ref = mkfifo("/usr/local/robofifo", O_WRONLY|O_NONBLOCK);
    if(ref == -1){
        cout<<"fifo is not created"<<endl;
    }
}

void quitDebug(){
    if(ref != -1)
        close(ref);
}
#endif