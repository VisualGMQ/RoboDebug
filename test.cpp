#include "debugtool.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    initDebug();
    int a = 0;
    bool isAlpha = false;
    char ch = 'a';
    string str = "GMQ is here";
    int count = 0;
    while(count < 10){
        a++;
        SEND_VARIABLE(a);
        SEND_VARIABLE(ch);
        SEND_VARIABLE(str);
        SEND_VARIABLE(isAlpha);
        count++;
        sleep(1);
    }
    quitDebug();
    return 0;
}