#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <string.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int countVowels(const char* word) {
    int count = 0;
    while (*word) {
        if (isVowel(*word)) {
            count++;
        }
        word++;
    }
    return count;
}

int countConsonants(const char* word) {
    int count = 0;
    while (*word) {
        if (isalpha(*word) && !isVowel(*word)) {
            count++;
        }
        word++;
    }
    return count;
}

int isPalindrome(const char* word) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void removePalindromes(char* text) {
    const char* delimiter = " \t\n";

    char* context = 0;
    char* token = strtok_s(text, delimiter, &context);

    while (token != 0) {
        if (!isPalindrome(token)) {
            printf("%s ", token);
        }

        token = strtok_s(0, delimiter, &context);
    }
}

void printLongestWord(char* text) {
    const char* delimiter = " \t\n";

    char* context = 0;
    char* token = strtok_s(text, delimiter, &context);

    if (token == 0) {
        printf("Текст не містить слів.\n");
        return;
    }

    const char* longestWord = token;
    size_t maxLength = strlen(token);

    while (token != 0) {
        size_t currentLength = strlen(token);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            longestWord = token;
        }

        token = strtok_s(0, delimiter, &context);
    }

    printf("Найдовше слово: \"%s\"\n", longestWord);
}

int main() {
    char input[1000];
    char inputCopy[1000];

    printf("Введіть текстовий рядок: ");
    fgets(input, sizeof(input), stdin);

    strcpy_s(inputCopy, input);

    const char* delimiter = " \t\n";

    char* context = 0;
    char* token = strtok_s(input, delimiter, &context);
    while (token != 0) {
        int vowelsCount = countVowels(token);
        int consonantsCount = countConsonants(token);

        if (vowelsCount == consonantsCount) {
            printf("Слово \"%s\" містить однакову кількість голосних і приголосних літер.\n", token);
        }

        token = strtok_s(0, delimiter, &context);
    }

    printf("Текст без паліндромів: ");
    removePalindromes(inputCopy);

    printLongestWord(inputCopy);

    return 0;
}
