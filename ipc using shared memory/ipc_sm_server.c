#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#define SHMSIZE 25

int main() {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 9647;

    printf("\n\t SHARED MEMORY SERVER PROGRAM \n");

    if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) {
        perror("\n SHARED MEMORY CREATE ERROR");
        exit(0);
    }

    if((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("\n SHARED MEMORY ALLOCATED ERROR");
        exit(1);
    }

    s = shm;

    for(c = 'A'; c <= 'Z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    return 0;
}
