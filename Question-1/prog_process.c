#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h> 
#include <fcntl.h>

int globalVariable = 10;

int main() {
    int process_id = fork();
    
    if(process_id == 0) {
        for(int i = 0;i<100;i++) {
            globalVariable--;
            printf("CHILD PROCESS: %d\n",globalVariable);
        }
    }
    else if(process_id > 0) {
        for(int i=0;i<90;i++) {
            globalVariable++;
            printf("PARENT PROCESS: %d\n",globalVariable);
        }
    }
    else {
        printf("ERROR IN PROCESS CREATION\n");
    }
}