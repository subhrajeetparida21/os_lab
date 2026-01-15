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
        while (1) {
            sleep(1);
        }
    } else {
        while (1) {
            sleep(1);
        }
    }

    return 0;
}

