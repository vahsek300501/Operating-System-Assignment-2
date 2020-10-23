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
    while(globalVariable != -90) {
        globalVariable --;
    }
    printf("CHILD THREAD %d\n",globalVariable);
}

int main() {
    pthread_t thread_id;
    int rc = pthread_create(&thread_id,NULL,threadFunction,NULL);
    if(rc) {
        printf("Thread not spawn");
    }
    while(globalVariable!=100) {
        globalVariable++;
    } 
    printf("MAIN THREAD: %d\n",globalVariable);
}