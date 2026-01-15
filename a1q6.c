#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[1024];
    int total = 0, running = 0, terminals = 0;

    system("ps aux > ps_aux.txt");
    system("ps -ef > ps_ef.txt");

    fp = fopen("ps_aux.txt", "r");
    if (fp == NULL) {
        perror("File open error");
        exit(1);
    }

    fgets(line, sizeof(line), fp);

    printf("CPU intensive processes (CPU > 10%%):\n");
    while (fgets(line, sizeof(line), fp)) {
        total++;

        char user[50], tty[50];
        int pid;
        float cpu, mem;

        sscanf(line, "%s %d %f %f %*s %*s %*s %*s %s",
               user, &pid, &cpu, &mem, tty);

        if (cpu > 10.0)
            printf("PID: %d CPU: %.2f\n", pid, cpu);

        if (strcmp(tty, "?") != 0)
            terminals++;

        if (strstr(line, " R "))
            running++;
    }
    fclose(fp);

    fp = fopen("ps_ef.txt", "r");
    if (fp == NULL) {
        perror("File open error");
        exit(1);
    }

    fgets(line, sizeof(line), fp);

    printf("\nMemory hungry processes (MEM > 10%%):\n");
    while (fgets(line, sizeof(line), fp)) {
        int pid;
        float mem;

        if (sscanf(line, "%*s %d %*s %*s %*s %*s %f",
                   &pid, &mem) == 2) {
            if (mem > 10.0)
                printf("PID: %d MEM: %.2f\n", pid, mem);
        }
    }
    fclose(fp);

    printf("\nProcess statistics:\n");
    printf("Total processes: %d\n", total);
    printf("Running processes: %d\n", running);
    printf("Number of terminals: %d\n", terminals);

    return 0;
}

