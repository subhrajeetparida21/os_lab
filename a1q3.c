#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child running... mypid %d myparent pid %d mygroupid %d\n",
               getpid(), getppid(), getpgrp());
        printf("Bye\n");
    } else {
        printf("Parent running... mypid %d myparent pid %d mygroupid %d\n",
               getpid(), getppid(), getpgrp());
        printf("Bye\n");
    }

    return 0;
}

