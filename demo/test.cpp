#include "../src/debugtool/debugtool.hpp"
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
    while(count < 200){
        clearVariables();
        a++;
        CREATE_VARIABLE(a);
        CREATE_VARIABLE(ch);
        CREATE_VARIABLE(str);
        CREATE_VARIABLE(isAlpha);
        sendVariables();
        count++;
        sleep(1);
    }
    quitDebug();
    return 0;
}