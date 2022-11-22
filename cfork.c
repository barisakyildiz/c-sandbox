#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int forkAChild(){
    pid_t pid;

    /*Fork a child process*/
    pid = fork();
    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }else if(pid == 0){
        execlp("/bin/ls", "ls", NULL);
    }else{
        /*Parent will wait for the child to complete*/
        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}

void forkResult(){
    int forkResult1;
    printf("Process ID: %i \n", getpid());
    forkResult1 = fork();
    printf("Process ID: %i - Result: %d\n", getpid(), forkResult);
}

int main(){

    forkAChild();
    printf("\n\n\n\n");
    forkResult();

    return 0;
}