#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int pid = fork();
	printf("pid : %d\n",pid);
    while (1) {
        void *p = malloc(1024 * 1024);
        if (p == NULL) {
            break;
        }
        sleep(1);
    }
    return 0;
}

