#include <iostream>
#include <unistd.h>   
#include <cstdlib>    

using namespace std;

int main() {
    pid_t pid = fork();  

    if (pid == 0) {
        //exec
        execl("./process2", "process2", NULL);

        perror("execvp failed");
        exit(1);
    } 
    else {
        //parent
        int counter = 0;
        while (true) {
            cout << "process 1: counter = " << counter++ << endl;
            sleep(1);  
        }
    }

    return 0;
}