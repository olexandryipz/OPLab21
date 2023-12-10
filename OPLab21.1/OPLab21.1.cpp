#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void findNumberOfDigit(const char* numberStr) {
    for (int i = 0; i < strlen(numberStr); i++) {
        if (!isdigit(numberStr[i])) {
            printf("Введено не ціле додатнє число.\n");
            return;
        }
    }

    int number = atoi(numberStr);

    int digitNumber = snprintf(0, 0, "%d", number);

    printf("Розрядність числа %d дорівнює %d.\n", number, digitNumber);
}

int main() {
    char numberStr[50];

    printf("Введіть ціле додатнє число: ");
    fgets(numberStr, sizeof(numberStr), stdin);
    numberStr[strcspn(numberStr, "\n")] = '\0';

    findNumberOfDigit(numberStr);

    return 0;
}