#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>    

struct SharedMemory {
    int multiple;
    int counter;
};

int main() {
    int shmid = shmget(1234, sizeof(SharedMemory), IPC_CREAT | 0666);
    SharedMemory *data = (SharedMemory *) shmat(shmid, nullptr, 0);
    
    data->multiple = 3;
    data->counter = 0;

    pid_t pid = fork();
    if (pid == 0) {
        char shmid_str[16];
        snprintf(shmid_str, sizeof(shmid_str), "%d", shmid);
        execl("./process2", "process2", shmid_str, nullptr);
        perror("execl failed");
        _exit(1);
    }

    while (data->counter < 500) {
        data->counter += 40;
        if(data->counter % data->multiple == 0){
            std::cout << "process 1: counter = " << data->counter << " - a multiple of " << data->multiple << std::endl;
        }else{
            std::cout << "process 1: counter = " << data->counter << std::endl;
        }
        sleep(1);  
    }

    std::cout << "Process 1 finished" << std::endl;

    shmdt(data);
    shmctl(shmid, IPC_RMID, nullptr);

    return 0;
}
