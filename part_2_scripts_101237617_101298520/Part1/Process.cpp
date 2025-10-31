#include <iostream>
#include <unistd.h>   
#include <cstdlib>    

using namespace std;

int main() {
    pid_t pid = fork();  

    if (pid == 0) {
        //child
        int counter = 0;
        while (true) {
            cout << "Child process: counter = " << counter-- << endl;
            sleep(1);  
        }
    } 
    else {
        //parent
        int counter = 0;
        while (true) {
            cout << "Parent process: counter = " << counter++ << endl;
            sleep(1);  
        }
    }

    return 0;
}