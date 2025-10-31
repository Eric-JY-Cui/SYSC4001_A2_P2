#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <cstdlib>

struct SharedMemory {
    int multiple;
    int counter;
};

int main(int argc, char *argv[]) {

    int shmid = atoi(argv[1]);
    SharedMemory *data = (SharedMemory *) shmat(shmid, nullptr, 0);
    while(data->counter <= 100){}

    while (data->counter < 500) {
            data->counter-=10;
            if(data->counter % data->multiple == 0){
                std::cout << "process 2: counter = " << data->counter << " - a multiple of " << data->multiple << std::endl;
            }else{
                std::cout << "process 2: counter = " << data->counter << std::endl;
            }
            
            sleep(2);  
    }

    std::cout << "Process 2 finished" << std::endl;

    shmdt(data);
    return 0;
}
