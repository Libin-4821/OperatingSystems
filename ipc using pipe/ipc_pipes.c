#include<stdio.h>
#include<unistd.h>
int main() {
    int fd[2], child;
    char a[10];
    char b[10];
    
    printf("\n Enter the string to enter into the pipe:");
    scanf("%s", a);
    
    pipe(fd);
    child = fork();
    
    if(child > 0) {
        write(fd[1], a, 10);
    } else {
        read(fd[0], b, 10);
        printf("\n The string retrieved from the pipe is %s\n", b);
    }
    
    return 0;
}
