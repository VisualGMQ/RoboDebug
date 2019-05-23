#ifndef __DEBUGER_HPP__
#define __DEBUGER_HPP__
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <map>
using namespace std;

class debugger{
public:
    debugger();
    const map<string, string>& getVariables();
    void readAndParse(); 
    bool isChanged;
    ~debugger();
private:
    map<string, string> variables;
    static int fifofile;
    static void handle(int signum);
    void openFifo();
    void readData();
    void parse(string msg);
};
#endif