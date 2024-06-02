#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main() {
int pid = fork();
if(pid == -1) {
printf("fork failed");
exit(1);
} else if(pid == 0) {
printf("\nChild process starts\n");
for(int i = 0; i < 5; i++) {
printf("\nChild process %d is called", i);
}
printf("\nChild process ends\n");
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);
execlp("/bin/ls", "ls", "-l", NULL);
perror("exec");
exit(EXIT_FAILURE);
} else {
wait(NULL);
printf("\nParent process ends\n");
}
return 0;
}
