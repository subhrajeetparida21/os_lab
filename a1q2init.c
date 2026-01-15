#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("acc_balance.txt", "w");
    if (fp == NULL) {
        perror("File open error");
        exit(1);
    }

    fprintf(fp, "%d\n", 1000);
    fclose(fp);

    printf("Account initialized with balance = 1000\n");
    return 0;
}

