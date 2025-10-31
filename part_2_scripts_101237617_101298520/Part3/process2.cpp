#include <iostream>
#include <unistd.h>   
#include <cstdlib>    

using namespace std;

int main() {
    int counter = 0;
        while (counter > -500) {
            counter -= 80;
            if(counter % 3 == 0){
                std::cout << "process 2: counter = " << counter << " - a multiple of 3" << std::endl;
            }else{
                std::cout << "process 2: counter = " << counter << std::endl;
            }
            sleep(1);  
        }

    return 0;
}