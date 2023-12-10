#include <stdio.h>
#include <Windows.h>
#include <ctype.h>

int main() {
    char input[100];

    printf("Введіть рядок десяткових чисел, розділених пробілами: ");
    fgets(input, sizeof(input), stdin);

    int evenNumbersCount = 0;
    int oddNumbersCount = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            int digit = input[i] - '0';

            if (digit % 2 == 0) {
                evenNumbersCount++;
            }
            else {
                oddNumbersCount++;
            }
        }
    }

    printf("Кількість парних цифр: %d\n", evenNumbersCount);
    printf("Кількість непарних цифр: %d\n", oddNumbersCount);

    return 0;
}
