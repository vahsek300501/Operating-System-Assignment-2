#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern int errno;

int getFileName(char* arr) {
    int pathLength = strlen(arr);
    int i = pathLength-1;
    pathLength = 0;
    while(arr[i]!='/') {
        pathLength++;
        i--;
    }
    return pathLength;
}

int main(int argc, char ** argv) {
    int fileNameLength = 0;
    if(argc<3 || argc >3) {
        errno = EIO;
        perror("ERROR");
        return errno;
    }
    
    if(argv[2][0] == '/') {
        fileNameLength = getFileName(argv[2]);
    }
    else {
        fileNameLength = strlen(argv[2]);
    }

    if(fileNameLength >= 30) {
        errno = ENAMETOOLONG;
        perror("ERROR");
        return errno;
    }

    int out = syscall(440,atoi(argv[1]),argv[2]);
    if(out != 0){
        perror("ERROR");
        return errno;
    }

    return 0;
}