#include "robolib.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    initDebug();
    int a = 0;
    SEND_VARIABLE(a);
    bool isAlpha = false;
    SEND_VARIABLE(isAlpha);
    char ch = 'a';
    SEND_VARIABLE(ch);
    string str = "GMQ is here";
    SEND_VARIABLE(str);
    quitDebug();
    /*
    stringstream ss;
    string str = "GMQ is here";
    ss<<str;
    string s;
    while(!ss.eof()){
        string tmp;
        ss>>tmp;
        s += tmp;
    }
    cout<<s<<endl;
    return 0;
    */
}