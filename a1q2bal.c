#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *fp;
    int balance;

    fp = fopen("acc_balance.txt", "r");
    if (fp == NULL) {
        perror("File open error");
        exit(1);
    }

    fscanf(fp, "%d", &balance);
    fclose(fp);

    balance = balance + 100;

    sleep(1);

    fp = fopen("acc_balance.txt", "w");
    if (fp == NULL) {
        perror("File open error");
        exit(1);
    }

    fprintf(fp, "%d\n", balance);
    fclose(fp);

    printf("Updated balance: %d\n", balance);
    return 0;
}

