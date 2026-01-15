#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    printf("pid : %d\n",pid);
    while (1) {
    }
    return 0;
}

