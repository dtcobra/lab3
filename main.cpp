#include <cstdio>
#include <rpc.h>
#include <iostream>
#include <cmath>

using namespace std;

char *readLine() {
    char *str = new char[1];

    char ch = 0;
    int i = 0;
    while ((ch = getchar()) != '\n') {
        str[i++] = ch;

        char *copyStr = new char[i + 1];
        strncpy(copyStr, str, i);

        delete[] str;
        str = copyStr;
    }
    str[i] = '\0';

    return str;
}

void handleString(char **str) {
    if (strlen(*str) != 0) {
        char *strBuffer = strdup(*str);
        char *word = "", *buffer = strtok(strBuffer, " .,?!");
        int count = 0;
        while (buffer != nullptr) {
            if (strlen(buffer) > strlen(word)) {
                word = buffer;
                count = 1;
            } else if (strcmp(buffer, word) == 0) count++;

            buffer = strtok(nullptr, " .,?!");
        }
        free(strBuffer);

        if (word != "") {
            printf("Самое длинное слово в строке: %s\n", word);
            printf("Оно встретилось в тексте %d раз\n", count);
        } else {
            printf("В строке нет слов\n");
        }
    } else {
        printf("Сначала создайте строку\n");
    }
}

void printString(char **str) {
    if (strlen(*str) != 0) {
        printf("%s\n", *str);
    } else printf("Сначала создайте строку\n");
}

bool parseInt(char *str, int *num) {
    return (sscanf(str, "%d", num)) == 1;
}

int main() {
    // Для работы с русским языком
    SetConsoleCP(1251); SetConsoleOutputCP(1251);


    // Объявление переменных
    char *str = new char[1];
    int num = 0, a, b;

    while (true) {
        printf("1. Ввести строку\n2. Обработать строку\n3. Вывести строку\n4. Выход\n");

        while (!parseInt(readLine(), &num)) {
            printf("Это не число, попробуйте снова\n");
        }

        switch (num) {
            // Ввод строки
            case 1:
                printf("Введите строку:\n");
                str = readLine();
                break;

                // Обработка строки
            case 2:
                handleString(&str);
                break;

                // Вывод строки
            case 3:
                printString(&str);
                break;

                // Выход
            case 4:
                printf("Спасибо!");
                return 0;

            default:
                printf("Такого пункта меню нет!\n");
        }
    }
}
