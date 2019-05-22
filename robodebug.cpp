#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
using namespace std;

int fifofile = -1;

void handle(int signum){
    if(signum == SIGINT){
        if(fifofile > 0)
            close(fifofile);
        cout<<"client is quit"<<endl;
        exit(EXIT_SUCCESS);
    }
}

int main(){
    signal(SIGINT, handle); 
    fifofile = open("/usr/local/robofifo", O_RDONLY|O_NONBLOCK);
    if(fifofile <= 0){
        cout<<"please create the pip first"<<endl;
        return -1;
    }
    while(true){
        char data[1024];
        int len = read(fifofile, data, sizeof(data));
        if(len > 0)
            cout<<data<<endl;
    }
    return 0;
}