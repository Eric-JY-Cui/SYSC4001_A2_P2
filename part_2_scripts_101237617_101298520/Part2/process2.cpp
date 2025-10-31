#include <iostream>
#include <unistd.h>   
#include <cstdlib>    

using namespace std;

int main() {
    int counter = 0;
        while (true) {
            cout << "process 2: counter = " << counter-- << endl;
            sleep(1);  
        }

    return 0;
}