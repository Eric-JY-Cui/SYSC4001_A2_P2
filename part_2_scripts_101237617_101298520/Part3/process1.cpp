#include <iostream>
#include <unistd.h>   
#include <cstdlib> 
#include <sys/wait.h>   

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
        int status;
        pid_t finished_pid = wait(&status);
        std::cout << "Process 1: Process 2 has finished.\n";
    }

    return 0;
}