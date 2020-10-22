#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h> 
#include <fcntl.h>
#include <pthread.h>

int globalVariable = 10;

void * threadFunction(void * data) {
    pthread_detach(pthread_self());
    for(int i=0;i<100;i++) {
        globalVariable--;
        printf("CHILD THREAD: %d\n"globalVariable);
    }
}

int main() {
    

}