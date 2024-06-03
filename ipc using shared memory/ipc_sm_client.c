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

    printf("\n\t SHARED MEMORY CLIENT PROGRAM\n ");

    if((shmid = shmget(key, SHMSIZE, 0666)) < 0) {
        perror("\n SHARED MEMORY CREATE ERROR");
        exit(0);
    }

    if((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("\n SHARED MEMORY ALLOCATED ERROR");
        exit(1);
    }

    for(s = shm; *s != '\0'; s++) {
        printf("\t");
        putchar(*s);
    }

    return 0;
}
